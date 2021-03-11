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
 *  Sprite animation.
 *
 *-----------------------------------------------------------------------------*/

#ifndef __P_PSPR__
#define __P_PSPR__

/* Basic data types.
 * Needs fixed point, and BAM angles. */

#include "m_fixed.hh"
#include "tables.hh"

/* Needs to include the precompiled sprite animation tables.
 *
 * Header generated by multigen utility.
 * This includes all the data for thing animation,
 * i.e. the Thing Atrributes table and the Frame Sequence table.
 */

#include "doomdef.hh"
#include "info.hh"

#ifdef __GNUG__
#pragma interface
#endif

/*
 * Frame flags:
 * handles maximum brightness (torches, muzzle flare, light sources)
 */

#define FF_FULLBRIGHT 0x8000 /* flag in thing->frame */
#define FF_FRAMEMASK 0x7fff

/*
 * Overlay psprites are scaled shapes
 * drawn directly on the view screen,
 * coordinates are given for a 320*200 view screen.
 */

typedef enum
{
    ps_weapon,
    ps_flash,
    NUMPSPRITES
} psprnum_t;

struct pspdef_t
{
    state_t *state; /* a nullptr state means not active */
    int tics;
    fixed_t sx;
    fixed_t sy;
};

enum
{
    CENTERWEAPON_OFF,
    CENTERWEAPON_HOR,
    CENTERWEAPON_HORVER,
    CENTERWEAPON_BOB,
    NUM_CENTERWEAPON,
};

extern int weapon_preferences[2][NUMWEAPONS + 1]; /* killough 5/2/98 */
extern int weapon_attack_alignment;
bool P_WeaponPreferred(int w1, int w2);

struct player_t;
weapontype_t P_SwitchWeapon(player_t *player);
dboolean P_CheckAmmo(player_t *player);
void P_SetupPsprites(player_t *curplayer);
void P_MovePsprites(player_t *curplayer);
void P_DropWeapon(player_t *player);

void A_Light0(player_t *player, pspdef_t *psp);
void A_WeaponReady(player_t *player, pspdef_t *psp);
void A_Lower(player_t *player, pspdef_t *psp);
void A_Raise(player_t *player, pspdef_t *psp);
void A_Punch(player_t *player, pspdef_t *psp);
void A_ReFire(player_t *player, pspdef_t *psp);
void A_FirePistol(player_t *player, pspdef_t *psp);
void A_Light1(player_t *player, pspdef_t *psp);
void A_FireShotgun(player_t *player, pspdef_t *psp);
void A_Light2(player_t *player, pspdef_t *psp);
void A_FireShotgun2(player_t *player, pspdef_t *psp);
void A_CheckReload(player_t *player, pspdef_t *psp);
void A_OpenShotgun2(player_t *player, pspdef_t *psp);
void A_LoadShotgun2(player_t *player, pspdef_t *psp);
void A_CloseShotgun2(player_t *player, pspdef_t *psp);
void A_FireCGun(player_t *player, pspdef_t *psp);
void A_GunFlash(player_t *player, pspdef_t *psp);
void A_FireMissile(player_t *player, pspdef_t *psp);
void A_Saw(player_t *player, pspdef_t *psp);
void A_FirePlasma(player_t *player, pspdef_t *psp);
void A_BFGsound(player_t *player, pspdef_t *psp);
void A_FireBFG(player_t *player, pspdef_t *psp);
void A_BFGSpray(mobj_t *mo);
void A_FireOldBFG(player_t *player, pspdef_t *psp);

#endif
