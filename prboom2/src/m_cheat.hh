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
 *      Cheat code checking.
 *
 *-----------------------------------------------------------------------------*/

#ifndef __M_CHEAT__
#define __M_CHEAT__

#include <cstddef>

#include "b_bitops.hh"
#include "d_ticcmd.hh"
#include "doomtype.hh"
#include "unions.hh"

#define CHEAT(cheat, deh_cheat, when, func, arg)                               \
    {                                                                          \
        cheat, deh_cheat, when, func, arg, 0, 0, sizeof(cheat) - 1, 0, 0, 0,   \
            ""                                                                 \
    }

#define CHEAT_ARGS_MAX 8 /* Maximum number of args at end of cheats */

/* killough 4/16/98: Cheat table structure */
struct CheatSequence
{
    const char *cheat;
    const char *const deh_cheat;
    using when_t = Bitset<int>;
    static constexpr when_t always = 0;
    static constexpr when_t not_dm = 1;
    static constexpr when_t not_coop = 2;
    static constexpr when_t not_demo = 4;
    static constexpr when_t not_menu = 8;
    static constexpr when_t not_deh = 16;
    static constexpr when_t not_net = not_dm | not_coop;
    static constexpr when_t cht_never = not_net | not_demo;
    when_t when;
    CheatSequenceFunction func;
    const int arg;
    uint_64_t code, mask;
    // settings for this cheat
    size_t sequence_len;
    size_t deh_sequence_len;
    // state used during the game
    size_t chars_read;
    int param_chars_read;
    char parameter_buf[CHEAT_ARGS_MAX];

    explicit CheatSequence(const char * /* arg */)
        : cheat(NULL), deh_cheat(NULL), when(cht_never), arg(0), code(0),
          mask(0), sequence_len(0), deh_sequence_len(0), chars_read(0),
          param_chars_read(0), parameter_buf("")
    {
    }

    CheatSequence(const char *cheat, const char *deh_cheat, when_t when,
               CheatSequenceFunction func, int arg)
        : cheat(cheat), deh_cheat(deh_cheat), when(when), func(func), arg(arg),
          code(0), mask(0), sequence_len(0), deh_sequence_len(0), chars_read(0),
          param_chars_read(0), parameter_buf("")
    {
    }
};

extern CheatSequence cheat[];

dboolean M_FindCheats(int key);

#endif
