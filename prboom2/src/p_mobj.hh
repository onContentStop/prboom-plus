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
 *      Map Objects, MObj, definition and handling.
 *
 *-----------------------------------------------------------------------------*/

#ifndef __P_MOBJ__
#define __P_MOBJ__

// Basics.
#include "m_fixed.hh"
#include "tables.hh"

// We need the thinker_t stuff.
#include "d_think.hh"

// We need the WAD data structure for Map things,
// from the THINGS lump.
#include "doomdata.hh"

// States are tied to finite states are
//  tied to animation frames.
// Needs precompiled tables/data structures.
#include "info.hh"

//
// NOTES: mobj_t
//
// mobj_ts are used to tell the refresh where to draw an image,
// tell the world simulation when objects are contacted,
// and tell the sound driver how to position a sound.
//
// The refresh uses the next and prev links to follow
// lists of things in sectors as they are being drawn.
// The sprite, frame, and angle elements determine which patch_t
// is used to draw the sprite if it is visible.
// The sprite and frame values are allmost allways set
// from state_t structures.
// The statescr.exe utility generates the states.h and states.c
// files that contain the sprite/frame numbers from the
// statescr.txt source file.
// The xyz origin point represents a point at the bottom middle
// of the sprite (between the feet of a biped).
// This is the default origin position for patch_ts grabbed
// with lumpy.exe.
// A walking creature will have its z equal to the floor
// it is standing on.
//
// The sound code uses the x,y, and subsector fields
// to do stereo positioning of any sound effited by the mobj_t.
//
// The play simulation uses the blocklinks, x,y,z, radius, height
// to determine when mobj_ts are touching each other,
// touching lines in the map, or hit by trace lines (gunshots,
// lines of sight, etc).
// The mobj_t->flags element has various bit flags
// used by the simulation.
//
// Every mobj_t is linked into a single sector
// based on its origin coordinates.
// The subsector_t is found with R_PointInSubsector(x,y),
// and the sector_t can be found with subsector->sector.
// The sector links are only used by the rendering code,
// the play simulation does not care about them at all.
//
// Any mobj_t that needs to be acted upon by something else
// in the play world (block movement, be shot, etc) will also
// need to be linked into the blockmap.
// If the thing has the MF_NOBLOCK flag set, it will not use
// the block links. It can still interact with other things,
// but only as the instigator (missiles will run into other
// things, but nothing can run into a missile).
// Each block in the grid is 128*128 units, and knows about
// every line_t that it contains a piece of, and every
// interactable mobj_t that has its origin contained.
//
// A valid mobj_t is a mobj_t that has the proper subsector_t
// filled in for its xy coordinates and is linked into the
// sector from which the subsector was made, or has the
// MF_NOSECTOR flag set (the subsector_t needs to be valid
// even if MF_NOSECTOR is set), and is linked into a blockmap
// block or has the MF_NOBLOCKMAP flag set.
// Links should only be modified by the P_[Un]SetThingPosition()
// functions.
// Do not change the MF_NO? flags while a thing is valid.
//
// Any questions?
//

//
// Misc. mobj flags
//

using MobjFlag = Bitset<int64_t>;

// Call P_SpecialThing when touched.
constexpr MobjFlag MF_SPECIAL = 0x0000000000000001;
// Blocks.
constexpr MobjFlag MF_SOLID = 0x0000000000000002;
// Can be hit.
constexpr MobjFlag MF_SHOOTABLE = 0x0000000000000004;
// Don't use the sector links (invisible but touchable).
constexpr MobjFlag MF_NOSECTOR = 0x0000000000000008;
// Don't use the blocklinks (inert but displayable)
constexpr MobjFlag MF_NOBLOCKMAP = 0x0000000000000010;

// Not to be activated by sound, deaf monster.
constexpr MobjFlag MF_AMBUSH = 0x0000000000000020;
// Will try to attack right back.
constexpr MobjFlag MF_JUSTHIT = 0x0000000000000040;
// Will take at least one step before attacking.
constexpr MobjFlag MF_JUSTATTACKED = 0x0000000000000080;
// On level spawning (initial position),
//  hang from ceiling instead of stand on floor.
constexpr MobjFlag MF_SPAWNCEILING = 0x0000000000000100;
// Don't apply gravity (every tic),
//  that is, object will float, keeping current height
//  or changing it actively.
constexpr MobjFlag MF_NOGRAVITY = 0x0000000000000200;

// Movement flags.
// This allows jumps from high places.
constexpr MobjFlag MF_DROPOFF = 0x0000000000000400;
// For players, will pick up items.
constexpr MobjFlag MF_PICKUP = 0x0000000000000800;
// Player cheat. ???
constexpr MobjFlag MF_NOCLIP = 0x0000000000001000;
// Player: keep info about sliding along walls.
constexpr MobjFlag MF_SLIDE = 0x0000000000002000;
// Allow moves to any height, no gravity.
// For active floaters, e.g. cacodemons, pain elementals.
constexpr MobjFlag MF_FLOAT = 0x0000000000004000;
// Don't cross lines
//   ??? or look at heights on teleport.
constexpr MobjFlag MF_TELEPORT = 0x0000000000008000;
// Don't hit same species, explode on block.
// Player missiles as well as fireballs of various kinds.
constexpr MobjFlag MF_MISSILE = 0x0000000000010000;
// Dropped by a demon, not level spawned.
// E.g. ammo clips dropped by dying former humans.
constexpr MobjFlag MF_DROPPED = 0x0000000000020000;
// Use fuzzy draw (shadow demons or spectres),
//  temporary player invisibility powerup.
constexpr MobjFlag MF_SHADOW = 0x0000000000040000;
// Flag: don't bleed when shot (use puff),
//  barrels and shootable furniture shall not bleed.
constexpr MobjFlag MF_NOBLOOD = 0x0000000000080000;
// Don't stop moving halfway off a step,
//  that is, have dead bodies slide down all the way.
constexpr MobjFlag MF_CORPSE = 0x0000000000100000;
// Floating to a height for a move, ???
//  don't auto float to target's height.
constexpr MobjFlag MF_INFLOAT = 0x0000000000200000;

// On kill, count this enemy object
//  towards intermission kill total.
// Happy gathering.
constexpr MobjFlag MF_COUNTKILL = 0x0000000000400000;

// On picking up, count this item object
//  towards intermission item total.
constexpr MobjFlag MF_COUNTITEM = 0x0000000000800000;

// Special handling: skull in flight.
// Neither a cacodemon nor a missile.
constexpr MobjFlag MF_SKULLFLY = 0x0000000001000000;

// Don't spawn this object
//  in death match mode (e.g. key cards).
constexpr MobjFlag MF_NOTDMATCH = 0x0000000002000000;

// Player sprites in multiplayer modes are modified
//  using an internal color lookup table for re-indexing.
// If 0x4 0x8 or 0xc,
//  use a translation table for player colormaps
constexpr MobjFlag MF_TRANSLATION = 0x000000000c000000;
constexpr MobjFlag MF_TRANSLATION1 = 0x0000000004000000;
constexpr MobjFlag MF_TRANSLATION2 = 0x0000000008000000;
// Hmm ???.
constexpr MobjFlag MF_TRANSSHIFT = 26;

constexpr MobjFlag MF_UNUSED2 = 0x0000000010000000;
constexpr MobjFlag MF_UNUSED3 = 0x0000000020000000;

// Translucent sprite?                                          // phares
constexpr MobjFlag MF_TRANSLUCENT = 0x0000000040000000;

// this is free
// LONGLONG(0x0000000100000000)

// these are greater than an int. That's why the flags below are now
// uint_64_t

constexpr MobjFlag MF_TOUCHY = 0x0000000100000000LL;
constexpr MobjFlag MF_BOUNCES = 0x0000000200000000LL;
constexpr MobjFlag MF_FRIEND = 0x0000000400000000;

constexpr MobjFlag MF_RESSURECTED = 0x0000001000000000LL;
constexpr MobjFlag MF_NO_DEPTH_TEST = 0x0000002000000000LL;
constexpr MobjFlag MF_FOREGROUND = 0x0000004000000000LL;
constexpr MobjFlag MF_PLAYERSPRITE = 0x0000008000000000LL;

// This actor not targetted when it hurts something else
constexpr MobjFlag MF_NOTARGET = 0x0000010000000000LL;
// fly mode is active
constexpr MobjFlag MF_FLY = 0x0000020000000000LL;
// [FG] colored blood and gibs
constexpr MobjFlag MF_COLOREDBLOOD = 0x0000040000000000LL;

// killough 9/15/98: Same, but internal flags, not intended for .deh
// (some degree of opaqueness is good, to avoid compatibility woes)

using MobjInternalFlag = Bitset<int>;
// Object is falling
constexpr MobjInternalFlag MIF_FALLING = 1;
// Object is armed (for MF_TOUCHY objects)
constexpr MobjInternalFlag MIF_ARMED = 2;

// Map Object definition.
//
//
// killough 2/20/98:
//
// WARNING: Special steps must be taken in p_saveg.c if C pointers are added to
// this mobj_s struct, or else savegames will crash when loaded. See p_saveg.c.
// Do not add "struct mobj_s *fooptr" without adding code to p_saveg.c to
// convert the pointers to ordinals and back for savegames. This was the whole
// reason behind monsters going to sleep when loading savegames (the "target"
// pointer was simply nullified after loading, to prevent Doom from crashing),
// and the whole reason behind loadgames crashing on savegames of AV attacks.
//

// killough 9/8/98: changed some fields to shorts,
// for better memory usage (if only for cache).
/* cph 2006/08/28 - move Prev[XYZ] fields to the end of the struct. Add any
 * other new fields to the end, and make sure you don't break savegames! */

struct player_t;
struct msecnode_t;

struct mobj_t
{
    // List: thinker links.
    thinker_t thinker;

    // Info for drawing: position.
    fixed_t x{};
    fixed_t y{};
    fixed_t z{};

    // More list: links in sector (if needed)
    mobj_t *snext{};
    // killough 8/10/98: change to ptr-to-ptr
    mobj_t **sprev{};

    // More drawing info: to determine current sprite.

    // orientation
    angle_t angle{};
    // used to find patch_t and flip value
    spritenum_t sprite{SPR_NULL};
    // might be ORed with FF_FULLBRIGHT
    int frame{};

    // Interaction info, by BLOCKMAP.
    // Links in blocks (if needed).
    mobj_t *bnext{};
    // killough 8/11/98: change to ptr-to-ptr
    mobj_t **bprev{};

    struct subsector_s *subsector{};

    // The closest interval over all contacted Sectors.
    fixed_t floorz{};
    fixed_t ceilingz{};

    // killough 11/98: the lowest floor over all contacted Sectors.
    fixed_t dropoffz{};

    // For movement checking.
    fixed_t radius{};
    fixed_t height{};

    // Momentums, used to update position.
    fixed_t momx{};
    fixed_t momy{};
    fixed_t momz{};

    // If == validcount, already checked.
    int validcount{};

    mobjtype_t type;
    // &mobjinfo[mobj->type]
    mobjinfo_t *info{};

    // state tic counter
    int tics{};
    state_t *state{};
    MobjFlag flags{};
    // killough 9/15/98: internal flags
    int intflags{};
    int health{};

    // Movement direction, movement generation (zig-zagging).

    // 0-7
    short movedir{};
    // when 0, select a new dir
    short movecount{};
    // killough 9/8/98: monster strafing
    short strafecount{};

    // Thing being chased/attacked (or nullptr),
    // also the originator for missiles.
    mobj_t *target{};

    // Reaction time: if non 0, don't attack yet.
    // Used by player to freeze a bit after teleporting.
    short reactiontime{};

    // If >0, the current target will be chased no
    // matter what (even if shot by another object)
    short threshold{};

    // killough 9/9/98: How long a monster pursues a target.
    short pursuecount{};

    // killough 11/98: used in torque simulation
    short gear{};

    // Additional info record for player avatars only.
    // Only valid if type == MT_PLAYER
    player_t *player{};

    // Player number last looked for.
    short lastlook{};

    // For nightmare respawn.
    mapthing_t spawnpoint{};

    // Thing being chased/attacked for tracers.
    mobj_t *tracer{};

    // new field: last known enemy -- killough 2/15/98
    mobj_t *lastenemy{};

    // killough 8/2/98: friction properties part of sectors,
    // not objects -- removed friction properties from here
    // e6y: restored friction properties here
    // Friction values for the sector the object is in
    // phares 3/17/98
    int friction{};
    int movefactor{};

    // a linked list of sectors where this object appears
    // phares 3/14/98
    msecnode_t *touching_sectorlist{};

    fixed_t PrevX{};
    fixed_t PrevY{};
    fixed_t PrevZ{};

    // e6y
    // orientation
    angle_t pitch{};
    int index{};
    short patch_width{};

    // hi word stores thing num, low word identifier num
    int iden_nums{};

    // cph - needed so I can get the size unambiguously on amd64
    fixed_t pad{};

    // SEE WARNING ABOVE ABOUT POINTER FIELDS!!!
};

constexpr bool ALIVE(mobj_t *thing)
{
    return ((thing->health > 0) &&
            ((thing->flags & (MF_COUNTKILL | MF_CORPSE | MF_RESSURECTED)) ==
             MF_COUNTKILL));
}

// External declarations (fomerly in p_local.h) -- killough 5/2/98

#define VIEWHEIGHT (41 * FRACUNIT)

#define GRAVITY FRACUNIT
#define MAXMOVE (30 * FRACUNIT)

#define ONFLOORZ INT_MIN
#define ONCEILINGZ INT_MAX

// Time interval for item respawning.
#define ITEMQUESIZE 128

#define FLOATSPEED (FRACUNIT * 4)
#define STOPSPEED (FRACUNIT / 16)

// killough 11/98:
// For torque simulation:

#define OVERDRIVE 6
#define MAXGEAR (OVERDRIVE + 16)

// killough 11/98:
// Whether an object is "sentient" or not. Used for environmental influences.
#define sentient(mobj) ((mobj)->health > 0 && (mobj)->info->seestate != S_NULL)

extern int iquehead;
extern int iquetail;

// [FG] colored blood and gibs
extern dboolean colored_blood;

mobj_t *P_SubstNullMobj(mobj_t *th);
void P_RespawnSpecials(void);
mobj_t *P_SpawnMobj(fixed_t x, fixed_t y, fixed_t z, mobjtype_t type);
void P_RemoveMobj(mobj_t *th);
dboolean P_SetMobjState(mobj_t *mobj, statenum_t state);
void P_MobjThinker(mobj_t *mobj);
void P_SpawnPuff(fixed_t x, fixed_t y, fixed_t z);
uint_64_t P_ColoredBlood(mobj_t *bleeder);
void P_SpawnBlood(fixed_t x, fixed_t y, fixed_t z, int damage, mobj_t *bleeder);
mobj_t *P_SpawnMissile(mobj_t *source, mobj_t *dest, mobjtype_t type);
void P_SpawnPlayerMissile(mobj_t *source, mobjtype_t type);
dboolean P_IsDoomnumAllowed(int doomnum);
mobj_t *P_SpawnMapThing(const mapthing_t *mthing, int index);
void P_SpawnPlayer(int n, const mapthing_t *mthing);
void P_CheckMissileSpawn(mobj_t *); // killough 8/2/98
void P_ExplodeMissile(mobj_t *);    // killough
#endif
