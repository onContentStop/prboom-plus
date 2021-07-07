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
 *      Created by a sound utility.
 *      Kept as a sample, DOOM2 sounds.
 *
 *-----------------------------------------------------------------------------*/

// killough 5/3/98: reformatted

#include "p_saveg.h"
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "doomtype.h"
#include "sounds.h"

//
// Information about all the music
//

musicinfo_t S_music[] = {{0},
                         {"e1m1", 0},
                         {"e1m2", 0},
                         {"e1m3", 0},
                         {"e1m4", 0},
                         {"e1m5", 0},
                         {"e1m6", 0},
                         {"e1m7", 0},
                         {"e1m8", 0},
                         {"e1m9", 0},
                         {"e2m1", 0},
                         {"e2m2", 0},
                         {"e2m3", 0},
                         {"e2m4", 0},
                         {"e2m5", 0},
                         {"e2m6", 0},
                         {"e2m7", 0},
                         {"e2m8", 0},
                         {"e2m9", 0},
                         {"e3m1", 0},
                         {"e3m2", 0},
                         {"e3m3", 0},
                         {"e3m4", 0},
                         {"e3m5", 0},
                         {"e3m6", 0},
                         {"e3m7", 0},
                         {"e3m8", 0},
                         {"e3m9", 0},
                         {"inter", 0},
                         {"intro", 0},
                         {"bunny", 0},
                         {"victor", 0},
                         {"introa", 0},
                         {"runnin", 0},
                         {"stalks", 0},
                         {"countd", 0},
                         {"betwee", 0},
                         {"doom", 0},
                         {"the_da", 0},
                         {"shawn", 0},
                         {"ddtblu", 0},
                         {"in_cit", 0},
                         {"dead", 0},
                         {"stlks2", 0},
                         {"theda2", 0},
                         {"doom2", 0},
                         {"ddtbl2", 0},
                         {"runni2", 0},
                         {"dead2", 0},
                         {"stlks3", 0},
                         {"romero", 0},
                         {"shawn2", 0},
                         {"messag", 0},
                         {"count2", 0},
                         {"ddtbl3", 0},
                         {"ampie", 0},
                         {"theda3", 0},
                         {"adrian", 0},
                         {"messg2", 0},
                         {"romer2", 0},
                         {"tense", 0},
                         {"shawn3", 0},
                         {"openin", 0},
                         {"evil", 0},
                         {"ultima", 0},
                         {"read_m", 0},
                         {"dm2ttl", 0},
                         {"dm2int", 0},

                         // custom music from MUSINFO lump
                         {"musinfo", 0}};

static const char *sfx_names[] = {
    "none",
    "pistol",
    "shotgn",
    "sgcock",
    "dshtgn",
    "dbopn",
    "dbcls",
    "dbload",
    "plasma",
    "bfg",
    "sawup",
    "sawidl",
    "sawful",
    "sawhit",
    "rlaunc",
    "rxplod",
    "firsht",
    "firxpl",
    "pstart",
    "pstop",
    "doropn",
    "dorcls",
    "stnmov",
    "swtchn",
    "swtchx",
    "plpain",
    "dmpain",
    "popain",
    "vipain",
    "mnpain",
    "pepain",
    "slop",
    "itemup",
    "wpnup",
    "oof",
    "telept",
    "posit1",
    "posit2",
    "posit3",
    "bgsit1",
    "bgsit2",
    "sgtsit",
    "cacsit",
    "brssit",
    "cybsit",
    "spisit",
    "bspsit",
    "kntsit",
    "vilsit",
    "mansit",
    "pesit",
    "sklatk",
    "sgtatk",
    "skepch",
    "vilatk",
    "claw",
    "skeswg",
    "pldeth",
    "pdiehi",
    "podth1",
    "podth2",
    "podth3",
    "bgdth1",
    "bgdth2",
    "sgtdth",
    "cacdth",
    "skldth",
    "brsdth",
    "cybdth",
    "spidth",
    "bspdth",
    "vildth",
    "kntdth",
    "pedth",
    "skedth",
    "posact",
    "bgact",
    "dmact",
    "bspact",
    "bspwlk",
    "vilact",
    "noway",
    "barexp",
    "punch",
    "hoof",
    "metal",
    "chgun",
    "tink",
    "bdopn",
    "bdcls",
    "itmbk",
    "flame",
    "flamst",
    "getpow",
    "bospit",
    "boscub",
    "bossit",
    "bospn",
    "bosdth",
    "manatk",
    "mandth",
    "sssit",
    "ssdth",
    "keenpn",
    "keendt",
    "skeact",
    "skesit",
    "skeatk",
    "radio",

    "dgsit",
    "dgatk",
    "dgact",
    "dgdth",
    "dgpain",
    "secret",
    "gibdth",
    // Everything from here up to 500 is reserved for future use.

    // Free slots for DEHEXTRA. Priorities should be overridden by user.
    // There is a gap present to accomodate Eternity Engine - see their commit
    // @ https://github.com/team-eternity/eternity/commit/b8fb8f71 - which means
    // I must use desginated initializers, or else supply an exact number of
    // dummy
    // entries to pad it out. Not sure which would be uglier to maintain. -SH
    [500] = "fre000",
    [501] = "fre001",
    [502] = "fre002",
    [503] = "fre003",
    [504] = "fre004",
    [505] = "fre005",
    [506] = "fre006",
    [507] = "fre007",
    [508] = "fre008",
    [509] = "fre009",
    [510] = "fre010",
    [511] = "fre011",
    [512] = "fre012",
    [513] = "fre013",
    [514] = "fre014",
    [515] = "fre015",
    [516] = "fre016",
    [517] = "fre017",
    [518] = "fre018",
    [519] = "fre019",
    [520] = "fre020",
    [521] = "fre021",
    [522] = "fre022",
    [523] = "fre023",
    [524] = "fre024",
    [525] = "fre025",
    [526] = "fre026",
    [527] = "fre027",
    [528] = "fre028",
    [529] = "fre029",
    [530] = "fre030",
    [531] = "fre031",
    [532] = "fre032",
    [533] = "fre033",
    [534] = "fre034",
    [535] = "fre035",
    [536] = "fre036",
    [537] = "fre037",
    [538] = "fre038",
    [539] = "fre039",
    [540] = "fre040",
    [541] = "fre041",
    [542] = "fre042",
    [543] = "fre043",
    [544] = "fre044",
    [545] = "fre045",
    [546] = "fre046",
    [547] = "fre047",
    [548] = "fre048",
    [549] = "fre049",
    [550] = "fre050",
    [551] = "fre051",
    [552] = "fre052",
    [553] = "fre053",
    [554] = "fre054",
    [555] = "fre055",
    [556] = "fre056",
    [557] = "fre057",
    [558] = "fre058",
    [559] = "fre059",
    [560] = "fre060",
    [561] = "fre061",
    [562] = "fre062",
    [563] = "fre063",
    [564] = "fre064",
    [565] = "fre065",
    [566] = "fre066",
    [567] = "fre067",
    [568] = "fre068",
    [569] = "fre069",
    [570] = "fre070",
    [571] = "fre071",
    [572] = "fre072",
    [573] = "fre073",
    [574] = "fre074",
    [575] = "fre075",
    [576] = "fre076",
    [577] = "fre077",
    [578] = "fre078",
    [579] = "fre079",
    [580] = "fre080",
    [581] = "fre081",
    [582] = "fre082",
    [583] = "fre083",
    [584] = "fre084",
    [585] = "fre085",
    [586] = "fre086",
    [587] = "fre087",
    [588] = "fre088",
    [589] = "fre089",
    [590] = "fre090",
    [591] = "fre091",
    [592] = "fre092",
    [593] = "fre093",
    [594] = "fre094",
    [595] = "fre095",
    [596] = "fre096",
    [597] = "fre097",
    [598] = "fre098",
    [599] = "fre099",
    [600] = "fre100",
    [601] = "fre101",
    [602] = "fre102",
    [603] = "fre103",
    [604] = "fre104",
    [605] = "fre105",
    [606] = "fre106",
    [607] = "fre107",
    [608] = "fre108",
    [609] = "fre109",
    [610] = "fre110",
    [611] = "fre111",
    [612] = "fre112",
    [613] = "fre113",
    [614] = "fre114",
    [615] = "fre115",
    [616] = "fre116",
    [617] = "fre117",
    [618] = "fre118",
    [619] = "fre119",
    [620] = "fre120",
    [621] = "fre121",
    [622] = "fre122",
    [623] = "fre123",
    [624] = "fre124",
    [625] = "fre125",
    [626] = "fre126",
    [627] = "fre127",
    [628] = "fre128",
    [629] = "fre129",
    [630] = "fre130",
    [631] = "fre131",
    [632] = "fre132",
    [633] = "fre133",
    [634] = "fre134",
    [635] = "fre135",
    [636] = "fre136",
    [637] = "fre137",
    [638] = "fre138",
    [639] = "fre139",
    [640] = "fre140",
    [641] = "fre141",
    [642] = "fre142",
    [643] = "fre143",
    [644] = "fre144",
    [645] = "fre145",
    [646] = "fre146",
    [647] = "fre147",
    [648] = "fre148",
    [649] = "fre149",
    [650] = "fre150",
    [651] = "fre151",
    [652] = "fre152",
    [653] = "fre153",
    [654] = "fre154",
    [655] = "fre155",
    [656] = "fre156",
    [657] = "fre157",
    [658] = "fre158",
    [659] = "fre159",
    [660] = "fre160",
    [661] = "fre161",
    [662] = "fre162",
    [663] = "fre163",
    [664] = "fre164",
    [665] = "fre165",
    [666] = "fre166",
    [667] = "fre167",
    [668] = "fre168",
    [669] = "fre169",
    [670] = "fre170",
    [671] = "fre171",
    [672] = "fre172",
    [673] = "fre173",
    [674] = "fre174",
    [675] = "fre175",
    [676] = "fre176",
    [677] = "fre177",
    [678] = "fre178",
    [679] = "fre179",
    [680] = "fre180",
    [681] = "fre181",
    [682] = "fre182",
    [683] = "fre183",
    [684] = "fre184",
    [685] = "fre185",
    [686] = "fre186",
    [687] = "fre187",
    [688] = "fre188",
    [689] = "fre189",
    [690] = "fre190",
    [691] = "fre191",
    [692] = "fre192",
    [693] = "fre193",
    [694] = "fre194",
    [695] = "fre195",
    [696] = "fre196",
    [697] = "fre197",
    [698] = "fre198",
    [699] = "fre199",
    [700] = "barexp",
    [701] = "posact",
    [702] = "dmact",
    [703] = "firxpl",
    [704] = "slop",
    [705] = "barexp",
    [706] = "popain",
    [707] = "posact",
    [708] = "firxpl",
    [709] = "posit1",
    [710] = "posit2",
    [711] = "posit3",
    [712] = "popain",
    [713] = "podth1",
    [714] = "podth2",
    [715] = "podth3",
    [716] = "pistol",
    [717] = "posit1",
    [718] = "posit2",
    [719] = "posit3",
    [720] = "shotgn",
    [721] = "popain",
    [722] = "podth1",
    [723] = "podth2",
    [724] = "podth3",
    [725] = "posact",
    [726] = "shotgn",
    [727] = "popain",
    [728] = "posact",
    [729] = "shotgn",
    [730] = "sgtsit",
    [731] = "sgtatk",
    [732] = "dmpain",
    [733] = "sgtdth",
    [734] = "popain",
    [735] = "popain",
    [736] = "dmact",
    [737] = "dmact",
};

//
// Information about all the sfx
//

sfxinfo_t S_sfx[] = {
    // S_sfx[0] needs to be a dummy for odd reasons.
    {{}, false, 0, 0, -1, -1, 0},
    {{}, false, 64, 0, -1, -1, 0},
    {{}, false, 64, 0, -1, -1, 0},
    {{}, false, 64, 0, -1, -1, 0},
    {{}, false, 64, 0, -1, -1, 0},
    {{}, false, 64, 0, -1, -1, 0},
    {{}, false, 64, 0, -1, -1, 0},
    {{}, false, 64, 0, -1, -1, 0},
    {{}, false, 64, 0, -1, -1, 0},
    {{}, false, 64, 0, -1, -1, 0},
    {{}, false, 64, 0, -1, -1, 0},
    {{}, false, 118, 0, -1, -1, 0},
    {{}, false, 64, 0, -1, -1, 0},
    {{}, false, 64, 0, -1, -1, 0},
    {{}, false, 64, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 100, 0, -1, -1, 0},
    {{}, false, 100, 0, -1, -1, 0},
    {{}, false, 100, 0, -1, -1, 0},
    {{}, false, 100, 0, -1, -1, 0},
    {{}, false, 119, 0, -1, -1, 0},
    {{}, false, 78, 0, -1, -1, 0},
    {{}, false, 78, 0, -1, -1, 0},
    {{}, false, 96, 0, -1, -1, 0},
    {{}, false, 96, 0, -1, -1, 0},
    {{}, false, 96, 0, -1, -1, 0},
    {{}, false, 96, 0, -1, -1, 0},
    {{}, false, 96, 0, -1, -1, 0},
    {{}, false, 96, 0, -1, -1, 0},
    {{}, false, 78, 0, -1, -1, 0},
    {{}, true, 78, 0, -1, -1, 0},
    {{}, true, 78, 0, -1, -1, 0},
    {{}, false, 96, 0, -1, -1, 0},
    {{}, false, 32, 0, -1, -1, 0},
    {{}, true, 98, 0, -1, -1, 0},
    {{}, true, 98, 0, -1, -1, 0},
    {{}, true, 98, 0, -1, -1, 0},
    {{}, true, 98, 0, -1, -1, 0},
    {{}, true, 98, 0, -1, -1, 0},
    {{}, true, 98, 0, -1, -1, 0},
    {{}, true, 98, 0, -1, -1, 0},
    {{}, true, 94, 0, -1, -1, 0},
    {{}, true, 92, 0, -1, -1, 0},
    {{}, true, 90, 0, -1, -1, 0},
    {{}, true, 90, 0, -1, -1, 0},
    {{}, true, 90, 0, -1, -1, 0},
    {{}, true, 90, 0, -1, -1, 0},
    {{}, true, 90, 0, -1, -1, 0},
    {{}, true, 90, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 32, 0, -1, -1, 0},
    {{}, false, 32, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 32, 0, -1, -1, 0},
    {{}, false, 32, 0, -1, -1, 0},
    {{}, false, 32, 0, -1, -1, 0},
    {{}, false, 32, 0, -1, -1, 0},
    {{}, false, 32, 0, -1, -1, 0},
    {{}, false, 32, 0, -1, -1, 0},
    {{}, false, 32, 0, -1, -1, 0},
    {{}, false, 32, 0, -1, -1, 0},
    {{}, true, 120, 0, -1, -1, 0},
    {{}, true, 120, 0, -1, -1, 0},
    {{}, true, 120, 0, -1, -1, 0},
    {{}, true, 100, 0, -1, -1, 0},
    {{}, true, 100, 0, -1, -1, 0},
    {{}, true, 100, 0, -1, -1, 0},
    {{}, false, 78, 0, -1, -1, 0},
    {{}, false, 60, 0, -1, -1, 0},
    {{}, false, 64, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 64, &S_sfx[sfx_pistol], 150, 0, 0},
    {{}, false, 60, 0, -1, -1, 0},
    {{}, false, 100, 0, -1, -1, 0},
    {{}, false, 100, 0, -1, -1, 0},
    {{}, false, 100, 0, -1, -1, 0},
    {{}, false, 32, 0, -1, -1, 0},
    {{}, false, 32, 0, -1, -1, 0},
    {{}, false, 60, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 60, 0, -1, -1, 0},

    // killough 11/98: dog sounds
    {{}, false, 98, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 120, 0, -1, -1, 0},
    {{}, false, 70, 0, -1, -1, 0},
    {{}, false, 96, 0, -1, -1, 0},

    // e6y
    {{}, false, 60, 0, -1, -1, 0},
    {{}, false, 60, 0, -1, -1, 0},
    // Everything from here up to 500 is reserved for future use.

    // Free slots for DEHEXTRA. Priorities should be overridden by user.
    // There is a gap present to accomodate Eternity Engine - see their commit
    // @ https://github.com/team-eternity/eternity/commit/b8fb8f71 - which means
    // I must use desginated initializers, or else supply an exact number of
    // dummy
    // entries to pad it out. Not sure which would be uglier to maintain. -SH
    [500] = {{}, false, 127, 0, -1, -1, 0},
    [501] = {{}, false, 127, 0, -1, -1, 0},
    [502] = {{}, false, 127, 0, -1, -1, 0},
    [503] = {{}, false, 127, 0, -1, -1, 0},
    [504] = {{}, false, 127, 0, -1, -1, 0},
    [505] = {{}, false, 127, 0, -1, -1, 0},
    [506] = {{}, false, 127, 0, -1, -1, 0},
    [507] = {{}, false, 127, 0, -1, -1, 0},
    [508] = {{}, false, 127, 0, -1, -1, 0},
    [509] = {{}, false, 127, 0, -1, -1, 0},
    [510] = {{}, false, 127, 0, -1, -1, 0},
    [511] = {{}, false, 127, 0, -1, -1, 0},
    [512] = {{}, false, 127, 0, -1, -1, 0},
    [513] = {{}, false, 127, 0, -1, -1, 0},
    [514] = {{}, false, 127, 0, -1, -1, 0},
    [515] = {{}, false, 127, 0, -1, -1, 0},
    [516] = {{}, false, 127, 0, -1, -1, 0},
    [517] = {{}, false, 127, 0, -1, -1, 0},
    [518] = {{}, false, 127, 0, -1, -1, 0},
    [519] = {{}, false, 127, 0, -1, -1, 0},
    [520] = {{}, false, 127, 0, -1, -1, 0},
    [521] = {{}, false, 127, 0, -1, -1, 0},
    [522] = {{}, false, 127, 0, -1, -1, 0},
    [523] = {{}, false, 127, 0, -1, -1, 0},
    [524] = {{}, false, 127, 0, -1, -1, 0},
    [525] = {{}, false, 127, 0, -1, -1, 0},
    [526] = {{}, false, 127, 0, -1, -1, 0},
    [527] = {{}, false, 127, 0, -1, -1, 0},
    [528] = {{}, false, 127, 0, -1, -1, 0},
    [529] = {{}, false, 127, 0, -1, -1, 0},
    [530] = {{}, false, 127, 0, -1, -1, 0},
    [531] = {{}, false, 127, 0, -1, -1, 0},
    [532] = {{}, false, 127, 0, -1, -1, 0},
    [533] = {{}, false, 127, 0, -1, -1, 0},
    [534] = {{}, false, 127, 0, -1, -1, 0},
    [535] = {{}, false, 127, 0, -1, -1, 0},
    [536] = {{}, false, 127, 0, -1, -1, 0},
    [537] = {{}, false, 127, 0, -1, -1, 0},
    [538] = {{}, false, 127, 0, -1, -1, 0},
    [539] = {{}, false, 127, 0, -1, -1, 0},
    [540] = {{}, false, 127, 0, -1, -1, 0},
    [541] = {{}, false, 127, 0, -1, -1, 0},
    [542] = {{}, false, 127, 0, -1, -1, 0},
    [543] = {{}, false, 127, 0, -1, -1, 0},
    [544] = {{}, false, 127, 0, -1, -1, 0},
    [545] = {{}, false, 127, 0, -1, -1, 0},
    [546] = {{}, false, 127, 0, -1, -1, 0},
    [547] = {{}, false, 127, 0, -1, -1, 0},
    [548] = {{}, false, 127, 0, -1, -1, 0},
    [549] = {{}, false, 127, 0, -1, -1, 0},
    [550] = {{}, false, 127, 0, -1, -1, 0},
    [551] = {{}, false, 127, 0, -1, -1, 0},
    [552] = {{}, false, 127, 0, -1, -1, 0},
    [553] = {{}, false, 127, 0, -1, -1, 0},
    [554] = {{}, false, 127, 0, -1, -1, 0},
    [555] = {{}, false, 127, 0, -1, -1, 0},
    [556] = {{}, false, 127, 0, -1, -1, 0},
    [557] = {{}, false, 127, 0, -1, -1, 0},
    [558] = {{}, false, 127, 0, -1, -1, 0},
    [559] = {{}, false, 127, 0, -1, -1, 0},
    [560] = {{}, false, 127, 0, -1, -1, 0},
    [561] = {{}, false, 127, 0, -1, -1, 0},
    [562] = {{}, false, 127, 0, -1, -1, 0},
    [563] = {{}, false, 127, 0, -1, -1, 0},
    [564] = {{}, false, 127, 0, -1, -1, 0},
    [565] = {{}, false, 127, 0, -1, -1, 0},
    [566] = {{}, false, 127, 0, -1, -1, 0},
    [567] = {{}, false, 127, 0, -1, -1, 0},
    [568] = {{}, false, 127, 0, -1, -1, 0},
    [569] = {{}, false, 127, 0, -1, -1, 0},
    [570] = {{}, false, 127, 0, -1, -1, 0},
    [571] = {{}, false, 127, 0, -1, -1, 0},
    [572] = {{}, false, 127, 0, -1, -1, 0},
    [573] = {{}, false, 127, 0, -1, -1, 0},
    [574] = {{}, false, 127, 0, -1, -1, 0},
    [575] = {{}, false, 127, 0, -1, -1, 0},
    [576] = {{}, false, 127, 0, -1, -1, 0},
    [577] = {{}, false, 127, 0, -1, -1, 0},
    [578] = {{}, false, 127, 0, -1, -1, 0},
    [579] = {{}, false, 127, 0, -1, -1, 0},
    [580] = {{}, false, 127, 0, -1, -1, 0},
    [581] = {{}, false, 127, 0, -1, -1, 0},
    [582] = {{}, false, 127, 0, -1, -1, 0},
    [583] = {{}, false, 127, 0, -1, -1, 0},
    [584] = {{}, false, 127, 0, -1, -1, 0},
    [585] = {{}, false, 127, 0, -1, -1, 0},
    [586] = {{}, false, 127, 0, -1, -1, 0},
    [587] = {{}, false, 127, 0, -1, -1, 0},
    [588] = {{}, false, 127, 0, -1, -1, 0},
    [589] = {{}, false, 127, 0, -1, -1, 0},
    [590] = {{}, false, 127, 0, -1, -1, 0},
    [591] = {{}, false, 127, 0, -1, -1, 0},
    [592] = {{}, false, 127, 0, -1, -1, 0},
    [593] = {{}, false, 127, 0, -1, -1, 0},
    [594] = {{}, false, 127, 0, -1, -1, 0},
    [595] = {{}, false, 127, 0, -1, -1, 0},
    [596] = {{}, false, 127, 0, -1, -1, 0},
    [597] = {{}, false, 127, 0, -1, -1, 0},
    [598] = {{}, false, 127, 0, -1, -1, 0},
    [599] = {{}, false, 127, 0, -1, -1, 0},
    [600] = {{}, false, 127, 0, -1, -1, 0},
    [601] = {{}, false, 127, 0, -1, -1, 0},
    [602] = {{}, false, 127, 0, -1, -1, 0},
    [603] = {{}, false, 127, 0, -1, -1, 0},
    [604] = {{}, false, 127, 0, -1, -1, 0},
    [605] = {{}, false, 127, 0, -1, -1, 0},
    [606] = {{}, false, 127, 0, -1, -1, 0},
    [607] = {{}, false, 127, 0, -1, -1, 0},
    [608] = {{}, false, 127, 0, -1, -1, 0},
    [609] = {{}, false, 127, 0, -1, -1, 0},
    [610] = {{}, false, 127, 0, -1, -1, 0},
    [611] = {{}, false, 127, 0, -1, -1, 0},
    [612] = {{}, false, 127, 0, -1, -1, 0},
    [613] = {{}, false, 127, 0, -1, -1, 0},
    [614] = {{}, false, 127, 0, -1, -1, 0},
    [615] = {{}, false, 127, 0, -1, -1, 0},
    [616] = {{}, false, 127, 0, -1, -1, 0},
    [617] = {{}, false, 127, 0, -1, -1, 0},
    [618] = {{}, false, 127, 0, -1, -1, 0},
    [619] = {{}, false, 127, 0, -1, -1, 0},
    [620] = {{}, false, 127, 0, -1, -1, 0},
    [621] = {{}, false, 127, 0, -1, -1, 0},
    [622] = {{}, false, 127, 0, -1, -1, 0},
    [623] = {{}, false, 127, 0, -1, -1, 0},
    [624] = {{}, false, 127, 0, -1, -1, 0},
    [625] = {{}, false, 127, 0, -1, -1, 0},
    [626] = {{}, false, 127, 0, -1, -1, 0},
    [627] = {{}, false, 127, 0, -1, -1, 0},
    [628] = {{}, false, 127, 0, -1, -1, 0},
    [629] = {{}, false, 127, 0, -1, -1, 0},
    [630] = {{}, false, 127, 0, -1, -1, 0},
    [631] = {{}, false, 127, 0, -1, -1, 0},
    [632] = {{}, false, 127, 0, -1, -1, 0},
    [633] = {{}, false, 127, 0, -1, -1, 0},
    [634] = {{}, false, 127, 0, -1, -1, 0},
    [635] = {{}, false, 127, 0, -1, -1, 0},
    [636] = {{}, false, 127, 0, -1, -1, 0},
    [637] = {{}, false, 127, 0, -1, -1, 0},
    [638] = {{}, false, 127, 0, -1, -1, 0},
    [639] = {{}, false, 127, 0, -1, -1, 0},
    [640] = {{}, false, 127, 0, -1, -1, 0},
    [641] = {{}, false, 127, 0, -1, -1, 0},
    [642] = {{}, false, 127, 0, -1, -1, 0},
    [643] = {{}, false, 127, 0, -1, -1, 0},
    [644] = {{}, false, 127, 0, -1, -1, 0},
    [645] = {{}, false, 127, 0, -1, -1, 0},
    [646] = {{}, false, 127, 0, -1, -1, 0},
    [647] = {{}, false, 127, 0, -1, -1, 0},
    [648] = {{}, false, 127, 0, -1, -1, 0},
    [649] = {{}, false, 127, 0, -1, -1, 0},
    [650] = {{}, false, 127, 0, -1, -1, 0},
    [651] = {{}, false, 127, 0, -1, -1, 0},
    [652] = {{}, false, 127, 0, -1, -1, 0},
    [653] = {{}, false, 127, 0, -1, -1, 0},
    [654] = {{}, false, 127, 0, -1, -1, 0},
    [655] = {{}, false, 127, 0, -1, -1, 0},
    [656] = {{}, false, 127, 0, -1, -1, 0},
    [657] = {{}, false, 127, 0, -1, -1, 0},
    [658] = {{}, false, 127, 0, -1, -1, 0},
    [659] = {{}, false, 127, 0, -1, -1, 0},
    [660] = {{}, false, 127, 0, -1, -1, 0},
    [661] = {{}, false, 127, 0, -1, -1, 0},
    [662] = {{}, false, 127, 0, -1, -1, 0},
    [663] = {{}, false, 127, 0, -1, -1, 0},
    [664] = {{}, false, 127, 0, -1, -1, 0},
    [665] = {{}, false, 127, 0, -1, -1, 0},
    [666] = {{}, false, 127, 0, -1, -1, 0},
    [667] = {{}, false, 127, 0, -1, -1, 0},
    [668] = {{}, false, 127, 0, -1, -1, 0},
    [669] = {{}, false, 127, 0, -1, -1, 0},
    [670] = {{}, false, 127, 0, -1, -1, 0},
    [671] = {{}, false, 127, 0, -1, -1, 0},
    [672] = {{}, false, 127, 0, -1, -1, 0},
    [673] = {{}, false, 127, 0, -1, -1, 0},
    [674] = {{}, false, 127, 0, -1, -1, 0},
    [675] = {{}, false, 127, 0, -1, -1, 0},
    [676] = {{}, false, 127, 0, -1, -1, 0},
    [677] = {{}, false, 127, 0, -1, -1, 0},
    [678] = {{}, false, 127, 0, -1, -1, 0},
    [679] = {{}, false, 127, 0, -1, -1, 0},
    [680] = {{}, false, 127, 0, -1, -1, 0},
    [681] = {{}, false, 127, 0, -1, -1, 0},
    [682] = {{}, false, 127, 0, -1, -1, 0},
    [683] = {{}, false, 127, 0, -1, -1, 0},
    [684] = {{}, false, 127, 0, -1, -1, 0},
    [685] = {{}, false, 127, 0, -1, -1, 0},
    [686] = {{}, false, 127, 0, -1, -1, 0},
    [687] = {{}, false, 127, 0, -1, -1, 0},
    [688] = {{}, false, 127, 0, -1, -1, 0},
    [689] = {{}, false, 127, 0, -1, -1, 0},
    [690] = {{}, false, 127, 0, -1, -1, 0},
    [691] = {{}, false, 127, 0, -1, -1, 0},
    [692] = {{}, false, 127, 0, -1, -1, 0},
    [693] = {{}, false, 127, 0, -1, -1, 0},
    [694] = {{}, false, 127, 0, -1, -1, 0},
    [695] = {{}, false, 127, 0, -1, -1, 0},
    [696] = {{}, false, 127, 0, -1, -1, 0},
    [697] = {{}, false, 127, 0, -1, -1, 0},
    [698] = {{}, false, 127, 0, -1, -1, 0},
    [699] = {{}, false, 127, 0, -1, -1, 0},
    [700] = {{}, false, 70, 0, -1, -1, 0},
    [701] = {{}, true, 120, 0, -1, -1, 0},
    [702] = {{}, true, 120, 0, -1, -1, 0},
    [703] = {{}, false, 70, 0, -1, -1, 0},
    [704] = {{}, false, 78, 0, -1, -1, 0},
    [705] = {{}, false, 60, 0, -1, -1, 0},
    [706] = {{}, false, 96, 0, -1, -1, 0},
    [707] = {{}, true, 120, 0, -1, -1, 0},
    [708] = {{}, false, 70, 0, -1, -1, 0},
    [709] = {{}, true, 98, 0, -1, -1, 0},
    [710] = {{}, true, 98, 0, -1, -1, 0},
    [711] = {{}, true, 98, 0, -1, -1, 0},
    [712] = {{}, false, 96, 0, -1, -1, 0},
    [713] = {{}, false, 70, 0, -1, -1, 0},
    [714] = {{}, false, 70, 0, -1, -1, 0},
    [715] = {{}, false, 70, 0, -1, -1, 0},
    [716] = {{}, false, 64, 0, -1, -1, 0},
    [717] = {{}, true, 98, 0, -1, -1, 0},
    [718] = {{}, true, 98, 0, -1, -1, 0},
    [719] = {{}, true, 98, 0, -1, -1, 0},
    [720] = {{}, false, 64, 0, -1, -1, 0},
    [721] = {{}, false, 96, 0, -1, -1, 0},
    [722] = {{}, false, 70, 0, -1, -1, 0},
    [723] = {{}, false, 70, 0, -1, -1, 0},
    [724] = {{}, false, 70, 0, -1, -1, 0},
    [725] = {{}, true, 120, 0, -1, -1, 0},
    [726] = {{}, false, 64, 0, -1, -1, 0},
    [727] = {{}, false, 96, 0, -1, -1, 0},
    [728] = {{}, true, 120, 0, -1, -1, 0},
    [729] = {{}, false, 64, 0, -1, -1, 0},
    [730] = {{}, true, 98, 0, -1, -1, 0},
    [731] = {{}, false, 70, 0, -1, -1, 0},
    [732] = {{}, false, 96, 0, -1, -1, 0},
    [733] = {{}, false, 70, 0, -1, -1, 0},
    [734] = {{}, false, 96, 0, -1, -1, 0},
    [735] = {{}, false, 96, 0, -1, -1, 0},
    [736] = {{}, true, 120, 0, -1, -1, 0},
    [737] = {{}, true, 120, 0, -1, -1, 0},
};

void init_sfx(void) {
  char *name = NULL;
  for (int i = 0; i < sizeof(sfx_names) / sizeof(const char *); ++i) {
    if (!sfx_names[i]) {
      continue;
    }
    vec_init(&S_sfx[i].names);
    name = malloc(strlen(sfx_names[i]) + 1);
    strcpy(name, sfx_names[i]);
    vec_push(&S_sfx[i].names, name);
  }
}

#define CHECK_SFX_NAME(expected, if_match)       \
  if (!strncmp(name.text, expected, name.len)) { \
    return if_match;                             \
  }

int SFX_GetIndex(string_t name) {
  CHECK_SFX_NAME("grunt/sight1", sfx_posit1);
  CHECK_SFX_NAME("grunt/sight2", sfx_posit2);
  CHECK_SFX_NAME("grunt/sight3", sfx_posit3);
  CHECK_SFX_NAME("grunt/attack", sfx_posatk);
  CHECK_SFX_NAME("grunt/pain", sfx_popain);
  CHECK_SFX_NAME("grunt/death1", sfx_podth1);
  CHECK_SFX_NAME("grunt/death2", sfx_podth2);
  CHECK_SFX_NAME("grunt/death3", sfx_podth3);
  CHECK_SFX_NAME("grunt/active", sfx_posact);

  CHECK_SFX_NAME("shotguy/sight1", sfx_sgsit1);
  CHECK_SFX_NAME("shotguy/sight2", sfx_sgsit2);
  CHECK_SFX_NAME("shotguy/sight3", sfx_sgsit3);
  CHECK_SFX_NAME("shotguy/attack", sfx_sgatk);
  CHECK_SFX_NAME("shotguy/pain", sfx_sgpain);
  CHECK_SFX_NAME("shotguy/death1", sfx_sgdth1);
  CHECK_SFX_NAME("shotguy/death2", sfx_sgdth2);
  CHECK_SFX_NAME("shotguy/death3", sfx_sgdth3);
  CHECK_SFX_NAME("shotguy/active", sfx_sgact);

  CHECK_SFX_NAME("chainguy/sight1", sfx_cgsit1);
  CHECK_SFX_NAME("chainguy/sight2", sfx_cgsit2);
  CHECK_SFX_NAME("chainguy/sight3", sfx_cgsit3);
  CHECK_SFX_NAME("chainguy/attack", sfx_cgatk);
  CHECK_SFX_NAME("chainguy/pain", sfx_cgpain);
  CHECK_SFX_NAME("chainguy/death1", sfx_cgdth1);
  CHECK_SFX_NAME("chainguy/death2", sfx_cgdth2);
  CHECK_SFX_NAME("chainguy/death3", sfx_cgdth3);
  CHECK_SFX_NAME("chainguy/active", sfx_cgact);

  CHECK_SFX_NAME("wolfss/sight", sfx_sssit);
  CHECK_SFX_NAME("wolfss/pain", sfx_sspain);
  CHECK_SFX_NAME("wolfss/death", sfx_ssdth);
  CHECK_SFX_NAME("wolfss/active", sfx_ssact);
  CHECK_SFX_NAME("wolfss/attack", sfx_ssatk);

  CHECK_SFX_NAME("demon/sight", sfx_sgtsit);
  CHECK_SFX_NAME("demon/melee", sfx_sgtatk);
  CHECK_SFX_NAME("demon/pain", sfx_dmpain);
  CHECK_SFX_NAME("demon/death", sfx_sgtdth);
  CHECK_SFX_NAME("demon/active", sfx_dmact);

  CHECK_SFX_NAME("spectre/sight", sfx_spsit);
  CHECK_SFX_NAME("spectre/melee", sfx_spatk);
  CHECK_SFX_NAME("spectre/pain", sfx_sppain);
  CHECK_SFX_NAME("spectre/death", sfx_spdth);
  CHECK_SFX_NAME("spectre/active", sfx_spact);

  CHECK_SFX_NAME("imp/sight1", sfx_bgsit1);
  CHECK_SFX_NAME("imp/sight2", sfx_bgsit2);
  CHECK_SFX_NAME("imp/pain", sfx_bgpain);
  CHECK_SFX_NAME("imp/death1", sfx_bgdth1);
  CHECK_SFX_NAME("imp/death2", sfx_bgdth2);
  CHECK_SFX_NAME("imp/active", sfx_bgact);
  CHECK_SFX_NAME("imp/attack", sfx_claw);
  CHECK_SFX_NAME("imp/shotx", sfx_firxpl);

  CHECK_SFX_NAME("skull/melee", sfx_sklatk);
  CHECK_SFX_NAME("skull/pain", sfx_sklpn);
  CHECK_SFX_NAME("skull/death", sfx_skldth);
  CHECK_SFX_NAME("skull/active", sfx_sklact);

  CHECK_SFX_NAME("fatso/active", sfx_manact);
  CHECK_SFX_NAME("fatso/attack", sfx_manatk);
  CHECK_SFX_NAME("fatso/sight", sfx_mansit);
  CHECK_SFX_NAME("fatso/pain", sfx_mnpain);
  CHECK_SFX_NAME("fatso/death", sfx_mandth);
  CHECK_SFX_NAME("fatso/shotx", sfx_mnsxpl);

  CHECK_SFX_NAME("pain/sight", sfx_pesit);
  CHECK_SFX_NAME("pain/pain", sfx_pepain);
  CHECK_SFX_NAME("pain/death", sfx_pedth);
  CHECK_SFX_NAME("pain/active", sfx_peact);

  CHECK_SFX_NAME("skeleton/melee", sfx_punch);
  CHECK_SFX_NAME("skeleton/sight", sfx_skesit);
  CHECK_SFX_NAME("skeleton/pain", sfx_skepn);
  CHECK_SFX_NAME("skeleton/death", sfx_skedth);
  CHECK_SFX_NAME("skeleton/active", sfx_skeact);
  CHECK_SFX_NAME("skeleton/attack", sfx_skeatk);
  CHECK_SFX_NAME("skeleton/tracex", sfx_tracex);

  CHECK_SFX_NAME("baron/sight", sfx_brssit);
  CHECK_SFX_NAME("baron/pain", sfx_brspn);
  CHECK_SFX_NAME("baron/death", sfx_brsdth);
  CHECK_SFX_NAME("baron/active", sfx_brsact);
  CHECK_SFX_NAME("baron/attack", sfx_brsatk);
  CHECK_SFX_NAME("baron/shotx", sfx_brsxpl);

  CHECK_SFX_NAME("knight/sight", sfx_kntsit);
  CHECK_SFX_NAME("knight/active", sfx_kntact);
  CHECK_SFX_NAME("knight/pain", sfx_kntpn);
  CHECK_SFX_NAME("knight/death", sfx_kntdth);
  CHECK_SFX_NAME("knight/attack", sfx_kntatk);
  CHECK_SFX_NAME("knight/shotx", sfx_kntxpl);

  CHECK_SFX_NAME("caco/sight", sfx_cacsit);
  CHECK_SFX_NAME("caco/pain", sfx_cacpn);
  CHECK_SFX_NAME("caco/death", sfx_cacdth);
  CHECK_SFX_NAME("caco/active", sfx_cacact);
  CHECK_SFX_NAME("caco/attack", sfx_cacatk);
  CHECK_SFX_NAME("caco/shotx", sfx_cacxpl);

  CHECK_SFX_NAME("vile/sight", sfx_vilsit);
  CHECK_SFX_NAME("vile/pain", sfx_vipain);
  CHECK_SFX_NAME("vile/death", sfx_vildth);
  CHECK_SFX_NAME("vile/active", sfx_vilact);
  CHECK_SFX_NAME("vile/raise", sfx_vilres);
  CHECK_SFX_NAME("vile/start", sfx_vilatk);
  CHECK_SFX_NAME("vile/stop", sfx_vilstp);
  CHECK_SFX_NAME("vile/firestrt", sfx_flamst);
  CHECK_SFX_NAME("vile/firecrkl", sfx_flame);

  CHECK_SFX_NAME("baby/sight", sfx_bspsit);
  CHECK_SFX_NAME("baby/pain", sfx_bsppn);
  CHECK_SFX_NAME("baby/death", sfx_bspdth);
  CHECK_SFX_NAME("baby/active", sfx_bspact);
  CHECK_SFX_NAME("baby/attack", sfx_bspatk);
  CHECK_SFX_NAME("baby/shotx", sfx_bspxpl);
  CHECK_SFX_NAME("baby/walk", sfx_bspwlk);

  CHECK_SFX_NAME("dog/active", sfx_dgact);
  CHECK_SFX_NAME("dog/attack", sfx_dgatk);
  CHECK_SFX_NAME("dog/death", sfx_dgdth);
  CHECK_SFX_NAME("dog/pain", sfx_dgpain);
  CHECK_SFX_NAME("dog/sight", sfx_dgsit);

  CHECK_SFX_NAME("brain/pain", sfx_bospn);
  CHECK_SFX_NAME("brain/death", sfx_bosdth);
  CHECK_SFX_NAME("brain/spit", sfx_bospit);
  CHECK_SFX_NAME("brain/cubeboom", sfx_bosxpl);
  CHECK_SFX_NAME("brain/sight", sfx_bossit);
  CHECK_SFX_NAME("brain/spawn", sfx_bosspw);
  CHECK_SFX_NAME("brain/cube", sfx_boscub);

  CHECK_SFX_NAME("cyber/sight", sfx_cybsit);
  CHECK_SFX_NAME("cyber/pain", sfx_cybpn);
  CHECK_SFX_NAME("cyber/death", sfx_cybdth);
  CHECK_SFX_NAME("cyber/active", sfx_cybact);
  CHECK_SFX_NAME("cyber/attack", sfx_cybatk);
  CHECK_SFX_NAME("cyber/hoof", sfx_hoof);

  CHECK_SFX_NAME("spider/sight", sfx_spisit);
  CHECK_SFX_NAME("spider/attack", sfx_spiatk);
  CHECK_SFX_NAME("spider/pain", sfx_spipn);
  CHECK_SFX_NAME("spider/active", sfx_spiact);
  CHECK_SFX_NAME("spider/death", sfx_spidth);
  CHECK_SFX_NAME("spider/walk", sfx_metal);

  CHECK_SFX_NAME("weapons/sshotl", sfx_dbload);
  CHECK_SFX_NAME("weapons/chngun", sfx_chgun);
  CHECK_SFX_NAME("weapons/plasmax", sfx_plsxpl);

  CHECK_SFX_NAME("world/barrelx", sfx_barexp);

  CHECK_SFX_NAME("misc/p_pkup", sfx_getpow);
  return -1;
}
