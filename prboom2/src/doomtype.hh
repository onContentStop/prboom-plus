/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2006 by
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
 *      Simple basic typedefs, isolated here to make it easier
 *       separating modules.
 *
 *-----------------------------------------------------------------------------*/

#ifndef __DOOMTYPE__
#define __DOOMTYPE__

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifndef __BYTEBOOL__
#define __BYTEBOOL__
/* Fixed to use builtin bool type with C++. */
#ifdef __cplusplus
typedef bool dboolean;
#else
typedef enum
{
    false,
    true
} dboolean;
#endif
typedef unsigned char byte;
#endif

// e6y
#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif
#ifndef BETWEEN
#define BETWEEN(l, u, x) ((l) > (x) ? (l) : (x) > (u) ? (u) : (x))
#endif

/* cph - Wrapper for the long long type, as Win32 used a different name.
 * Except I don't know what to test as it's compiler specific
 * Proff - I fixed it */
#ifndef _MSC_VER
typedef signed long long int_64_t;
typedef unsigned long long uint_64_t;
// define compiled-specific long-long contstant notation here
#define LONGLONG(num) (uint_64_t) num##ll
#else
typedef __int64 int_64_t;
typedef unsigned __int64 uint_64_t;
// define compiled-specific long-long contstant notation here
#define LONGLONG(num) (uint_64_t) num
#undef PATH_MAX
#define strcasecmp _stricmp
#define strncasecmp _strnicmp
#define S_ISDIR(x) (((sbuf.st_mode & S_IFDIR) == S_IFDIR) ? 1 : 0)
#endif

#ifndef PATH_MAX
#define PATH_MAX 1024
#endif

#ifdef __GNUC__
#define CONSTFUNC __attribute__((const))
#define PUREFUNC __attribute__((pure))
#define NORETURN __attribute__((noreturn))
#else
#define CONSTFUNC
#define PUREFUNC
#define NORETURN
#endif

// Definition of PACKEDATTR from Chocolate Doom
#ifdef __GNUC__
#if defined(_WIN32) && !defined(__clang__)
#define PACKEDATTR __attribute__((packed, gcc_struct))
#else
#define PACKEDATTR __attribute__((packed))
#endif
#else
#define PACKEDATTR
#endif

#ifdef WIN32
#define C_DECL __cdecl
#else
#define C_DECL
#endif

#ifdef _MSC_VER
#define INLINE __forceinline /* use __forceinline (VC++ specific) */
#else
#define INLINE inline /* use standard inline */
#endif

/* CPhipps - use limits.h instead of depreciated values.h */
#include <climits>

#include "b_bitops.hh"

/* cph - move compatibility levels here so we can use them in d_server.c */
using complevel_t = SequentialEnum<int>;
constexpr complevel_t doom_12_compatibility = 0;   /* Doom v1.2 */
constexpr complevel_t doom_1666_compatibility = 1; /* Doom v1.666 */
constexpr complevel_t doom2_19_compatibility = 2;  /* Doom & Doom 2 v1.9 */
constexpr complevel_t ultdoom_compatibility = 3; /* Ultimate Doom and Doom95 */
constexpr complevel_t finaldoom_compatibility = 4; /* Final Doom */
constexpr complevel_t dosdoom_compatibility = 5;   /* DosDoom 0.47 */
constexpr complevel_t tasdoom_compatibility = 6;   /* TASDoom */
constexpr complevel_t boom_compatibility_compatibility =
    7; /* Boom's compatibility mode */
constexpr complevel_t boom_201_compatibility = 8;   /* Boom v2.01 */
constexpr complevel_t boom_202_compatibility = 9;   /* Boom v2.02 */
constexpr complevel_t lxdoom_1_compatibility = 10;  /* LxDoom v1.3.2+ */
constexpr complevel_t mbf_compatibility = 11;       /* MBF */
constexpr complevel_t prboom_1_compatibility = 12;  /* PrBoom 2.03beta? */
constexpr complevel_t prboom_2_compatibility = 13;  /* PrBoom 2.1.0-2.1.1 */
constexpr complevel_t prboom_3_compatibility = 14;  /* PrBoom 2.2.x */
constexpr complevel_t prboom_4_compatibility = 15;  /* PrBoom 2.3.x */
constexpr complevel_t prboom_5_compatibility = 16;  /* PrBoom 2.4.0 */
constexpr complevel_t prboom_6_compatibility = 17;  /* Latest PrBoom */
constexpr complevel_t MAX_COMPATIBILITY_LEVEL = 18; /* Must be last entry */

/* Aliases follow */
/* Alias used by G_Compatibility */
constexpr complevel_t boom_compatibility = boom_201_compatibility;
/* cph - from v_video.h; needed by gl_struct.h */
constexpr complevel_t best_compatibility = prboom_6_compatibility;

using patch_translation_e = Bitset<int>;
constexpr patch_translation_e VPT_ALIGN_MASK{0xf};
constexpr patch_translation_e VPT_STRETCH_MASK{0x1f};

constexpr patch_translation_e VPT_ZERO{0};
// e6y: wide-res
constexpr patch_translation_e VPT_ALIGN_LEFT{1};
constexpr patch_translation_e VPT_ALIGN_RIGHT{2};
constexpr patch_translation_e VPT_ALIGN_TOP{3};
constexpr patch_translation_e VPT_ALIGN_LEFT_TOP{4};
constexpr patch_translation_e VPT_ALIGN_RIGHT_TOP{5};
constexpr patch_translation_e VPT_ALIGN_BOTTOM{6};
constexpr patch_translation_e VPT_ALIGN_WIDE{7};
constexpr patch_translation_e VPT_ALIGN_LEFT_BOTTOM{8};
constexpr patch_translation_e VPT_ALIGN_RIGHT_BOTTOM{9};
constexpr patch_translation_e VPT_ALIGN_MAX{10};
// Stretch to compensate for high-res
constexpr patch_translation_e VPT_STRETCH{16};
// Normal
constexpr patch_translation_e VPT_NONE{128};
// Flip image horizontally
constexpr patch_translation_e VPT_FLIP{256};
// Translate image via a translation table
constexpr patch_translation_e VPT_TRANS{512};
constexpr patch_translation_e VPT_NOOFFSET{1024};

#endif
