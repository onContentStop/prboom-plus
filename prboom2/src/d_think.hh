/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2000 by
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
 *  MapObj data. Map Objects or mobjs are actors, entities,
 *  thinker, take-your-pick... anything that moves, acts, or
 *  suffers state changes of more or less violent nature.
 *
 *-----------------------------------------------------------------------------*/

#ifndef __D_THINK__
#define __D_THINK__

#ifdef __GNUG__
#pragma interface
#endif

/*
 * Experimental stuff.
 * To compile this as "ANSI C with classes"
 *  we will need to handle the various
 *  action functions cleanly.
 */
// killough 11/98: convert back to C instead of C++
typedef void (*actionf_t)();

// e6y: for boom's friction code
using actionf_v = void (*)();
struct mobj_t;
using actionf_mobj1 = void (*)(mobj_t *);
typedef void (*actionf_p1)(void *);
typedef void (*actionf_p2)(void *, void *);

class actionf
{
    enum class actionf_discriminant
    {
        af_v,
        af_mobj1,
        af_p1,
        af_p2,
        undefined
    };
    actionf_v m_v = nullptr;
    actionf_mobj1 m_mobj1 = nullptr;
    actionf_p1 m_p1 = nullptr;
    actionf_p2 m_p2 = nullptr;
    actionf_discriminant m_which = actionf_discriminant::undefined;

  public:
    actionf() = default;

    actionf(actionf_v fn) : m_v(fn), m_which(actionf_discriminant::af_v)
    {
    }

    actionf(actionf_mobj1 fn)
        : m_mobj1(fn), m_which(actionf_discriminant::af_mobj1)
    {
    }

    actionf(actionf_p1 fn) : m_p1(fn), m_which(actionf_discriminant::af_p1)
    {
    }

    actionf(actionf_p2 fn) : m_p2(fn), m_which(actionf_discriminant::af_p1)
    {
    }

    const actionf_v *V() const
    {
        if (m_which == actionf_discriminant::af_v)
        {
            return &m_v;
        }

        return nullptr;
    }

    const actionf_mobj1 *Mobj1() const
    {
        if (m_which == actionf_discriminant::af_mobj1)
        {
            return &m_mobj1;
        }

        return nullptr;
    }

    const actionf_p1 *P1() const
    {
        if (m_which == actionf_discriminant::af_p1)
        {
            return &m_p1;
        }

        return nullptr;
    }

    const actionf_p2 *P2() const
    {
        if (m_which == actionf_discriminant::af_p2)
        {
            return &m_p2;
        }

        return nullptr;
    }

    bool Empty() const
    {
        return m_which == actionf_discriminant::undefined;
    }
};

/* Note: In d_deh.c you will find references to these
 * wherever code pointers and function handlers exist
 */
/*
typedef union
{
  actionf_p1    acp1;
  actionf_v     acv;
  actionf_p2    acp2;

} actionf_t;
*/

/* Historically, "think_t" is yet another
 *  function pointer to a routine to handle
 *  an actor.
 */
typedef actionf_t think_t;

/* Doubly linked list of actors. */
typedef struct thinker_s
{
    struct thinker_s *prev;
    struct thinker_s *next;
    think_t function;

    /* killough 8/29/98: we maintain thinkers in several equivalence classes,
     * according to various criteria, so as to allow quicker searches.
     */

    struct thinker_s *cnext, *cprev; /* Next, previous thinkers in same class */

    /* killough 11/98: count of how many other objects reference
     * this one using pointers. Used for garbage collection.
     */
    unsigned references;
} thinker_t;

#endif
