/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2000,2002 by
 *  Jess Haas, Nicolas Kalkhof, Colin Phipps, Florian Schulze
 *  Copyright 2005, 2006 by
 *  Florian Schulze, Colin Phipps, Neil Stevens, Andrey Budko
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *      Thinker, Ticker.
 *
 *-----------------------------------------------------------------------------*/

#include <iostream>

#include "p_tick.hh"
#include "doomstat.hh"
#include "e6y.hh"
#include "p_map.hh"
#include "p_spec.hh"
#include "p_user.hh"
#include "r_fps.hh"
#include "s_advsound.hh"
#include "unions.hh"

int leveltime;

static dboolean newthinkerpresent;

//
// THINKERS
// All thinkers should be allocated by Z_Malloc
// so they can be operated on uniformly.
// The actual structures will vary in size,
// but the first element must be thinker_t.
//

// killough 8/29/98: we maintain several separate threads, each containing
// a special class of thinkers, to allow more efficient searches.
std::array<thinker_t, TH_ALL.value() + 1> THINKER_CLASS_CAP;

//
// P_InitThinkers
//

void P_InitThinkers(void)
{
    int i;

    for (i = 0; i < NUMTHCLASS.value();
         i++) // killough 8/29/98: initialize threaded lists
        THINKER_CLASS_CAP[i].cprev = THINKER_CLASS_CAP[i].cnext =
            &THINKER_CLASS_CAP[i];

    THINKER_CLASS_CAP[TH_ALL.value()].prev =
        THINKER_CLASS_CAP[TH_ALL.value()].next =
            &THINKER_CLASS_CAP[TH_ALL.value()];
}

//
// killough 8/29/98:
//
// We maintain separate threads of friends and enemies, to permit more
// efficient searches.
//

void P_UpdateThinker(thinker_t *thinker)
{
    thinker_t *th;
    // find the class the thinker belongs to

    th_class cls;
    if (((mobj_t *)thinker)->flags & MF_FRIEND)
    {
        if (thinker->function == P_MobjThinker &&
            ((mobj_t *)thinker)->health > 0 &&
            (((mobj_t *)thinker)->flags & MF_COUNTKILL ||
             ((mobj_t *)thinker)->type == MT_SKULL))
        {
            if (thinker->function == P_RemoveThinkerDelayed)
            {
                cls = TH_DELETE;
            }
            else
            {
                cls = TH_FRIENDS;
            }
        }
        else
        {
            if (thinker->function == P_RemoveThinkerDelayed)
            {
                cls = TH_DELETE;
            }
            else
            {
                cls = TH_MISC;
            }
        }
    }
    else
    {
        if (thinker->function == P_MobjThinker &&
            ((mobj_t *)thinker)->health > 0 &&
            (((mobj_t *)thinker)->flags & MF_COUNTKILL ||
             ((mobj_t *)thinker)->type == MT_SKULL))
        {
            if (thinker->function == P_RemoveThinkerDelayed)
            {
                cls = TH_DELETE;
            }
            else
            {
                cls = TH_ENEMIES;
            }
        }
        else
        {
            if (thinker->function == P_RemoveThinkerDelayed)
            {
                cls = TH_DELETE;
            }
            else
            {
                cls = TH_MISC;
            }
        }
    }

    {
        /* Remove from current thread, if in one */
        if ((th = thinker->cnext) != nullptr)
            (th->cprev = thinker->cprev)->cnext = th;
    }

    // Add to appropriate thread
    th = &THINKER_CLASS_CAP[cls.value()];
    th->cprev->cnext = thinker;
    thinker->cnext = th;
    thinker->cprev = th->cprev;
    th->cprev = thinker;
}

//
// P_AddThinker
// Adds a new thinker at the end of the list.
//

void P_AddThinker(thinker_t *thinker)
{
    THINKER_CLASS_CAP[TH_ALL.value()].prev->next = thinker;
    thinker->next = &THINKER_CLASS_CAP[TH_ALL.value()];
    thinker->prev = THINKER_CLASS_CAP[TH_ALL.value()].prev;
    THINKER_CLASS_CAP[TH_ALL.value()].prev = thinker;

    thinker->references = 0; // killough 11/98: init reference counter to 0

    // killough 8/29/98: set sentinel pointers, and then add to appropriate list
    thinker->cnext = thinker->cprev = nullptr;
    P_UpdateThinker(thinker);
    newthinkerpresent = true;
}

//
// killough 11/98:
//
// Make currentthinker external, so that P_RemoveThinkerDelayed
// can adjust currentthinker when thinkers self-remove.

static thinker_t *currentthinker;

//
// P_RemoveThinkerDelayed()
//
// Called automatically as part of the thinker loop in P_RunThinkers(),
// on nodes which are pending deletion.
//
// If this thinker has no more pointers referencing it indirectly,
// remove it, and set currentthinker to one node preceeding it, so
// that the next step in P_RunThinkers() will get its successor.
//

void P_RemoveThinkerDelayed(thinker_t *thinker)
{
    if (!thinker->references)
    {
        { /* Remove from main thinker list */
            thinker_t *next = thinker->next;
            /* Note that currentthinker is guaranteed to point to us,
             * and since we're freeing our memory, we had better change that. So
             * point it to thinker->prev, so the iterator will correctly move on
             * to thinker->prev->next = thinker->next */
            (next->prev = currentthinker = thinker->prev)->next = next;
        }
        {
            /* Remove from current thinker class list */
            thinker_t *th = thinker->cnext;
            (th->cprev = thinker->cprev)->cnext = th;
        }
        Z_Free(thinker);
    }
}

//
// P_RemoveThinker
//
// Deallocation is lazy -- it will not actually be freed
// until its thinking turn comes up.
//
// killough 4/25/98:
//
// Instead of marking the function with -1 value cast to a function pointer,
// set the function to P_RemoveThinkerDelayed(), so that later, it will be
// removed automatically as part of the thinker process.
//

void P_RemoveThinker(thinker_t *thinker)
{
    R_StopInterpolationIfNeeded(thinker);
    thinker->function = P_RemoveThinkerDelayed;

    P_UpdateThinker(thinker);
}

/* cph 2002/01/13 - iterator for thinker list
 * WARNING: Do not modify thinkers between calls to this functin
 */
thinker_t *P_NextThinker(thinker_t *th, th_class cl)
{
    thinker_t *top = &THINKER_CLASS_CAP[cl.value()];
    if (!th)
        th = top;
    th = cl == TH_ALL ? th->next : th->cnext;
    return th == top ? nullptr : th;
}

/*
 * P_SetTarget
 *
 * This function is used to keep track of pointer references to mobj thinkers.
 * In Doom, objects such as lost souls could sometimes be removed despite
 * their still being referenced. In Boom, 'target' mobj fields were tested
 * during each gametic, and any objects pointed to by them would be prevented
 * from being removed. But this was incomplete, and was slow (every mobj was
 * checked during every gametic). Now, we keep a count of the number of
 * references, and delay removal until the count is 0.
 */

void P_SetTarget(mobj_t **mop, mobj_t *targ)
{
    if (*mop) // If there was a target already, decrease its refcount
        (*mop)->thinker.references--;
    if ((*mop =
             targ)) // Set new target and if non-nullptr, increase its counter
        targ->thinker.references++;
}

//
// P_RunThinkers
//
// killough 4/25/98:
//
// Fix deallocator to stop using "next" pointer after node has been freed
// (a Doom bug).
//
// Process each thinker. For thinkers which are marked deleted, we must
// load the "next" pointer prior to freeing the node. In Doom, the "next"
// pointer was loaded AFTER the thinker was freed, which could have caused
// crashes.
//
// But if we are not deleting the thinker, we should reload the "next"
// pointer after calling the function, in case additional thinkers are
// added at the end of the list.
//
// killough 11/98:
//
// Rewritten to delete nodes implicitly, by making currentthinker
// external and using P_RemoveThinkerDelayed() implicitly.
//

static void P_RunThinkers()
{
    for (currentthinker = THINKER_CLASS_CAP[TH_ALL.value()].next;
         currentthinker != &THINKER_CLASS_CAP[TH_ALL.value()];
         currentthinker = currentthinker->next)
    {
        if (newthinkerpresent)
            R_ActivateThinkerInterpolations(currentthinker);
        if (currentthinker->function != ACTION_NULL)
        {
            if (currentthinker->function.thinker())
                currentthinker->function.thinker()(currentthinker);
            else if (currentthinker->function.mobj())
                currentthinker->function.mobj()(
                    reinterpret_cast<mobj_t *>(currentthinker));
            else if (currentthinker->function.strobe())
            {
                currentthinker->function.strobe()(
                    reinterpret_cast<strobe_t *>(currentthinker));
            }
            else if (currentthinker->function.glow())
            {
                currentthinker->function.glow()(
                    reinterpret_cast<glow_t *>(currentthinker));
            }
            else if (currentthinker->function.fireflicker())
            {
                currentthinker->function.fireflicker()(
                    reinterpret_cast<fireflicker_t *>(currentthinker));
            }
            else if (currentthinker->function.scroll())
            {
                currentthinker->function.scroll()(
                    reinterpret_cast<scroll_t *>(currentthinker));
            }
            else
            {
                std::cout << currentthinker->function << std::endl;
            }
        }
    }
    newthinkerpresent = false;

    // Dedicated thinkers
    T_MAPMusic();
}

//
// P_Ticker
//

void P_Ticker(void)
{
    int i;

    /* pause if in menu and at least one tic has been run
     *
     * killough 9/29/98: note that this ties in with basetic,
     * since G_Ticker does the pausing during recording or
     * playback, and compenates by incrementing basetic.
     *
     * All of this complicated mess is used to preserve demo sync.
     */

    if (paused || (menuactive != mnact_inactive && !demoplayback && !netgame &&
                   players[consoleplayer].viewz != 1))
    {
        P_ResetWalkcam();
        return;
    }

    R_UpdateInterpolations();

    P_MapStart();
    // not if this is an intermission screen
    if (gamestate == GS_LEVEL)
        for (i = 0; i < MAXPLAYERS; i++)
            if (playeringame[i])
                P_PlayerThink(&players[i]);

    P_RunThinkers();
    P_UpdateSpecials();
    P_RespawnSpecials();
    P_MapEnd();
    leveltime++; // for par times
}
