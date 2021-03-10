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
 *      Created by the sound utility written by Dave Taylor.
 *      Kept as a sample, DOOM2 sounds. Frozen.
 *
 *-----------------------------------------------------------------------------*/

#ifndef __SOUNDS__
#define __SOUNDS__

//
// SoundFX struct.
//

struct sfxinfo_struct;

typedef struct sfxinfo_struct sfxinfo_t;

struct sfxinfo_struct
{

    // up to 6-character name
    const char *name; // CPhipps - const

    // Sfx singularity (only one at a time)
    int singularity;

    // Sfx priority
    int priority;

    // referenced sound if a link
    sfxinfo_t *link;

    // pitch if a link
    int pitch;

    // volume if a link
    int volume;

    // sound data
    void *data;

    // this is checked every second to see if sound
    // can be thrown out (if 0, then decrement, if -1,
    // then throw out, if > 0, then it is in use)
    int usefulness;

    // lump number of sfx
    int lumpnum;
};

//
// MusicInfo struct.
//

typedef struct
{
    // up to 6-character name
    const char *name; // CPhipps - const

    // lump number of music
    int lumpnum;

    /* music data - cphipps 4/11 made const void* */
    const void *data;

    // music handle once registered
    int handle;
} musicinfo_t;

// the complete set of sound effects
extern sfxinfo_t S_sfx[];

// the complete set of music
extern musicinfo_t S_music[];

//
// Identifiers for all music in game.
//

typedef enum
{
    mus_None,
    mus_e1m1,
    mus_e1m2,
    mus_e1m3,
    mus_e1m4,
    mus_e1m5,
    mus_e1m6,
    mus_e1m7,
    mus_e1m8,
    mus_e1m9,
    mus_e2m1,
    mus_e2m2,
    mus_e2m3,
    mus_e2m4,
    mus_e2m5,
    mus_e2m6,
    mus_e2m7,
    mus_e2m8,
    mus_e2m9,
    mus_e3m1,
    mus_e3m2,
    mus_e3m3,
    mus_e3m4,
    mus_e3m5,
    mus_e3m6,
    mus_e3m7,
    mus_e3m8,
    mus_e3m9,
    mus_inter,
    mus_intro,
    mus_bunny,
    mus_victor,
    mus_introa,
    mus_runnin,
    mus_stalks,
    mus_countd,
    mus_betwee,
    mus_doom,
    mus_the_da,
    mus_shawn,
    mus_ddtblu,
    mus_in_cit,
    mus_dead,
    mus_stlks2,
    mus_theda2,
    mus_doom2,
    mus_ddtbl2,
    mus_runni2,
    mus_dead2,
    mus_stlks3,
    mus_romero,
    mus_shawn2,
    mus_messag,
    mus_count2,
    mus_ddtbl3,
    mus_ampie,
    mus_theda3,
    mus_adrian,
    mus_messg2,
    mus_romer2,
    mus_tense,
    mus_shawn3,
    mus_openin,
    mus_evil,
    mus_ultima,
    mus_read_m,
    mus_dm2ttl,
    mus_dm2int,
    NUMMUSIC
} musicenum_t;

//
// Identifiers for all sfx in game.
//

using sfxenum_t = SequentialEnum<int>;
constexpr sfxenum_t sfx_None = 0;
constexpr sfxenum_t sfx_pistol = 1;
constexpr sfxenum_t sfx_shotgn = 2;
constexpr sfxenum_t sfx_sgcock = 3;
constexpr sfxenum_t sfx_dshtgn = 4;
constexpr sfxenum_t sfx_dbopn = 5;
constexpr sfxenum_t sfx_dbcls = 6;
constexpr sfxenum_t sfx_dbload = 7;
constexpr sfxenum_t sfx_plasma = 8;
constexpr sfxenum_t sfx_bfg = 9;
constexpr sfxenum_t sfx_sawup = 10;
constexpr sfxenum_t sfx_sawidl = 11;
constexpr sfxenum_t sfx_sawful = 12;
constexpr sfxenum_t sfx_sawhit = 13;
constexpr sfxenum_t sfx_rlaunc = 14;
constexpr sfxenum_t sfx_rxplod = 15;
constexpr sfxenum_t sfx_firsht = 16;
constexpr sfxenum_t sfx_firxpl = 17;
constexpr sfxenum_t sfx_pstart = 18;
constexpr sfxenum_t sfx_pstop = 19;
constexpr sfxenum_t sfx_doropn = 20;
constexpr sfxenum_t sfx_dorcls = 21;
constexpr sfxenum_t sfx_stnmov = 22;
constexpr sfxenum_t sfx_swtchn = 23;
constexpr sfxenum_t sfx_swtchx = 24;
constexpr sfxenum_t sfx_plpain = 25;
constexpr sfxenum_t sfx_dmpain = 26;
constexpr sfxenum_t sfx_popain = 27;
constexpr sfxenum_t sfx_vipain = 28;
constexpr sfxenum_t sfx_mnpain = 29;
constexpr sfxenum_t sfx_pepain = 30;
constexpr sfxenum_t sfx_slop = 31;
constexpr sfxenum_t sfx_itemup = 32;
constexpr sfxenum_t sfx_wpnup = 33;
constexpr sfxenum_t sfx_oof = 34;
constexpr sfxenum_t sfx_telept = 35;
constexpr sfxenum_t sfx_posit1 = 36;
constexpr sfxenum_t sfx_posit2 = 37;
constexpr sfxenum_t sfx_posit3 = 38;
constexpr sfxenum_t sfx_bgsit1 = 39;
constexpr sfxenum_t sfx_bgsit2 = 40;
constexpr sfxenum_t sfx_sgtsit = 41;
constexpr sfxenum_t sfx_cacsit = 42;
constexpr sfxenum_t sfx_brssit = 43;
constexpr sfxenum_t sfx_cybsit = 44;
constexpr sfxenum_t sfx_spisit = 45;
constexpr sfxenum_t sfx_bspsit = 46;
constexpr sfxenum_t sfx_kntsit = 47;
constexpr sfxenum_t sfx_vilsit = 48;
constexpr sfxenum_t sfx_mansit = 49;
constexpr sfxenum_t sfx_pesit = 50;
constexpr sfxenum_t sfx_sklatk = 51;
constexpr sfxenum_t sfx_sgtatk = 52;
constexpr sfxenum_t sfx_skepch = 53;
constexpr sfxenum_t sfx_vilatk = 54;
constexpr sfxenum_t sfx_claw = 55;
constexpr sfxenum_t sfx_skeswg = 56;
constexpr sfxenum_t sfx_pldeth = 57;
constexpr sfxenum_t sfx_pdiehi = 58;
constexpr sfxenum_t sfx_podth1 = 59;
constexpr sfxenum_t sfx_podth2 = 60;
constexpr sfxenum_t sfx_podth3 = 61;
constexpr sfxenum_t sfx_bgdth1 = 62;
constexpr sfxenum_t sfx_bgdth2 = 63;
constexpr sfxenum_t sfx_sgtdth = 64;
constexpr sfxenum_t sfx_cacdth = 65;
constexpr sfxenum_t sfx_skldth = 66;
constexpr sfxenum_t sfx_brsdth = 67;
constexpr sfxenum_t sfx_cybdth = 68;
constexpr sfxenum_t sfx_spidth = 69;
constexpr sfxenum_t sfx_bspdth = 70;
constexpr sfxenum_t sfx_vildth = 71;
constexpr sfxenum_t sfx_kntdth = 72;
constexpr sfxenum_t sfx_pedth = 73;
constexpr sfxenum_t sfx_skedth = 74;
constexpr sfxenum_t sfx_posact = 75;
constexpr sfxenum_t sfx_bgact = 76;
constexpr sfxenum_t sfx_dmact = 77;
constexpr sfxenum_t sfx_bspact = 78;
constexpr sfxenum_t sfx_bspwlk = 79;
constexpr sfxenum_t sfx_vilact = 80;
constexpr sfxenum_t sfx_noway = 81;
constexpr sfxenum_t sfx_barexp = 82;
constexpr sfxenum_t sfx_punch = 83;
constexpr sfxenum_t sfx_hoof = 84;
constexpr sfxenum_t sfx_metal = 85;
constexpr sfxenum_t sfx_chgun = 86;
constexpr sfxenum_t sfx_tink = 87;
constexpr sfxenum_t sfx_bdopn = 88;
constexpr sfxenum_t sfx_bdcls = 89;
constexpr sfxenum_t sfx_itmbk = 90;
constexpr sfxenum_t sfx_flame = 91;
constexpr sfxenum_t sfx_flamst = 92;
constexpr sfxenum_t sfx_getpow = 93;
constexpr sfxenum_t sfx_bospit = 94;
constexpr sfxenum_t sfx_boscub = 95;
constexpr sfxenum_t sfx_bossit = 96;
constexpr sfxenum_t sfx_bospn = 97;
constexpr sfxenum_t sfx_bosdth = 98;
constexpr sfxenum_t sfx_manatk = 99;
constexpr sfxenum_t sfx_mandth = 100;
constexpr sfxenum_t sfx_sssit = 101;
constexpr sfxenum_t sfx_ssdth = 102;
constexpr sfxenum_t sfx_keenpn = 103;
constexpr sfxenum_t sfx_keendt = 104;
constexpr sfxenum_t sfx_skeact = 105;
constexpr sfxenum_t sfx_skesit = 106;
constexpr sfxenum_t sfx_skeatk = 107;
constexpr sfxenum_t sfx_radio = 108;

/* killough 11/98: dog sounds */
constexpr sfxenum_t sfx_dgsit = 109;
constexpr sfxenum_t sfx_dgatk = 110;
constexpr sfxenum_t sfx_dgact = 111;
constexpr sfxenum_t sfx_dgdth = 112;
constexpr sfxenum_t sfx_dgpain = 113;

// e6y
constexpr sfxenum_t sfx_secret = 114;
constexpr sfxenum_t sfx_gibdth = 115;
// Everything from here to 500 is reserved

/* Free sound effect slots for DEHEXTRA. Offset agreed upon with Eternity
 * devs. -SH */
constexpr sfxenum_t sfx_fre000 = 500;
constexpr sfxenum_t sfx_fre001 = 501;
constexpr sfxenum_t sfx_fre002 = 502;
constexpr sfxenum_t sfx_fre003 = 503;
constexpr sfxenum_t sfx_fre004 = 504;
constexpr sfxenum_t sfx_fre005 = 505;
constexpr sfxenum_t sfx_fre006 = 506;
constexpr sfxenum_t sfx_fre007 = 507;
constexpr sfxenum_t sfx_fre008 = 508;
constexpr sfxenum_t sfx_fre009 = 509;
constexpr sfxenum_t sfx_fre010 = 510;
constexpr sfxenum_t sfx_fre011 = 511;
constexpr sfxenum_t sfx_fre012 = 512;
constexpr sfxenum_t sfx_fre013 = 513;
constexpr sfxenum_t sfx_fre014 = 514;
constexpr sfxenum_t sfx_fre015 = 515;
constexpr sfxenum_t sfx_fre016 = 516;
constexpr sfxenum_t sfx_fre017 = 517;
constexpr sfxenum_t sfx_fre018 = 518;
constexpr sfxenum_t sfx_fre019 = 519;
constexpr sfxenum_t sfx_fre020 = 520;
constexpr sfxenum_t sfx_fre021 = 521;
constexpr sfxenum_t sfx_fre022 = 522;
constexpr sfxenum_t sfx_fre023 = 523;
constexpr sfxenum_t sfx_fre024 = 524;
constexpr sfxenum_t sfx_fre025 = 525;
constexpr sfxenum_t sfx_fre026 = 526;
constexpr sfxenum_t sfx_fre027 = 527;
constexpr sfxenum_t sfx_fre028 = 528;
constexpr sfxenum_t sfx_fre029 = 529;
constexpr sfxenum_t sfx_fre030 = 530;
constexpr sfxenum_t sfx_fre031 = 531;
constexpr sfxenum_t sfx_fre032 = 532;
constexpr sfxenum_t sfx_fre033 = 533;
constexpr sfxenum_t sfx_fre034 = 534;
constexpr sfxenum_t sfx_fre035 = 535;
constexpr sfxenum_t sfx_fre036 = 536;
constexpr sfxenum_t sfx_fre037 = 537;
constexpr sfxenum_t sfx_fre038 = 538;
constexpr sfxenum_t sfx_fre039 = 539;
constexpr sfxenum_t sfx_fre040 = 540;
constexpr sfxenum_t sfx_fre041 = 541;
constexpr sfxenum_t sfx_fre042 = 542;
constexpr sfxenum_t sfx_fre043 = 543;
constexpr sfxenum_t sfx_fre044 = 544;
constexpr sfxenum_t sfx_fre045 = 545;
constexpr sfxenum_t sfx_fre046 = 546;
constexpr sfxenum_t sfx_fre047 = 547;
constexpr sfxenum_t sfx_fre048 = 548;
constexpr sfxenum_t sfx_fre049 = 549;
constexpr sfxenum_t sfx_fre050 = 550;
constexpr sfxenum_t sfx_fre051 = 551;
constexpr sfxenum_t sfx_fre052 = 552;
constexpr sfxenum_t sfx_fre053 = 553;
constexpr sfxenum_t sfx_fre054 = 554;
constexpr sfxenum_t sfx_fre055 = 555;
constexpr sfxenum_t sfx_fre056 = 556;
constexpr sfxenum_t sfx_fre057 = 557;
constexpr sfxenum_t sfx_fre058 = 558;
constexpr sfxenum_t sfx_fre059 = 559;
constexpr sfxenum_t sfx_fre060 = 560;
constexpr sfxenum_t sfx_fre061 = 561;
constexpr sfxenum_t sfx_fre062 = 562;
constexpr sfxenum_t sfx_fre063 = 563;
constexpr sfxenum_t sfx_fre064 = 564;
constexpr sfxenum_t sfx_fre065 = 565;
constexpr sfxenum_t sfx_fre066 = 566;
constexpr sfxenum_t sfx_fre067 = 567;
constexpr sfxenum_t sfx_fre068 = 568;
constexpr sfxenum_t sfx_fre069 = 569;
constexpr sfxenum_t sfx_fre070 = 570;
constexpr sfxenum_t sfx_fre071 = 571;
constexpr sfxenum_t sfx_fre072 = 572;
constexpr sfxenum_t sfx_fre073 = 573;
constexpr sfxenum_t sfx_fre074 = 574;
constexpr sfxenum_t sfx_fre075 = 575;
constexpr sfxenum_t sfx_fre076 = 576;
constexpr sfxenum_t sfx_fre077 = 577;
constexpr sfxenum_t sfx_fre078 = 578;
constexpr sfxenum_t sfx_fre079 = 579;
constexpr sfxenum_t sfx_fre080 = 580;
constexpr sfxenum_t sfx_fre081 = 581;
constexpr sfxenum_t sfx_fre082 = 582;
constexpr sfxenum_t sfx_fre083 = 583;
constexpr sfxenum_t sfx_fre084 = 584;
constexpr sfxenum_t sfx_fre085 = 585;
constexpr sfxenum_t sfx_fre086 = 586;
constexpr sfxenum_t sfx_fre087 = 587;
constexpr sfxenum_t sfx_fre088 = 588;
constexpr sfxenum_t sfx_fre089 = 589;
constexpr sfxenum_t sfx_fre090 = 590;
constexpr sfxenum_t sfx_fre091 = 591;
constexpr sfxenum_t sfx_fre092 = 592;
constexpr sfxenum_t sfx_fre093 = 593;
constexpr sfxenum_t sfx_fre094 = 594;
constexpr sfxenum_t sfx_fre095 = 595;
constexpr sfxenum_t sfx_fre096 = 596;
constexpr sfxenum_t sfx_fre097 = 597;
constexpr sfxenum_t sfx_fre098 = 598;
constexpr sfxenum_t sfx_fre099 = 599;
constexpr sfxenum_t sfx_fre100 = 600;
constexpr sfxenum_t sfx_fre101 = 601;
constexpr sfxenum_t sfx_fre102 = 602;
constexpr sfxenum_t sfx_fre103 = 603;
constexpr sfxenum_t sfx_fre104 = 604;
constexpr sfxenum_t sfx_fre105 = 605;
constexpr sfxenum_t sfx_fre106 = 606;
constexpr sfxenum_t sfx_fre107 = 607;
constexpr sfxenum_t sfx_fre108 = 608;
constexpr sfxenum_t sfx_fre109 = 609;
constexpr sfxenum_t sfx_fre110 = 610;
constexpr sfxenum_t sfx_fre111 = 611;
constexpr sfxenum_t sfx_fre112 = 612;
constexpr sfxenum_t sfx_fre113 = 613;
constexpr sfxenum_t sfx_fre114 = 614;
constexpr sfxenum_t sfx_fre115 = 615;
constexpr sfxenum_t sfx_fre116 = 616;
constexpr sfxenum_t sfx_fre117 = 617;
constexpr sfxenum_t sfx_fre118 = 618;
constexpr sfxenum_t sfx_fre119 = 619;
constexpr sfxenum_t sfx_fre120 = 620;
constexpr sfxenum_t sfx_fre121 = 621;
constexpr sfxenum_t sfx_fre122 = 622;
constexpr sfxenum_t sfx_fre123 = 623;
constexpr sfxenum_t sfx_fre124 = 624;
constexpr sfxenum_t sfx_fre125 = 625;
constexpr sfxenum_t sfx_fre126 = 626;
constexpr sfxenum_t sfx_fre127 = 627;
constexpr sfxenum_t sfx_fre128 = 628;
constexpr sfxenum_t sfx_fre129 = 629;
constexpr sfxenum_t sfx_fre130 = 630;
constexpr sfxenum_t sfx_fre131 = 631;
constexpr sfxenum_t sfx_fre132 = 632;
constexpr sfxenum_t sfx_fre133 = 633;
constexpr sfxenum_t sfx_fre134 = 634;
constexpr sfxenum_t sfx_fre135 = 635;
constexpr sfxenum_t sfx_fre136 = 636;
constexpr sfxenum_t sfx_fre137 = 637;
constexpr sfxenum_t sfx_fre138 = 638;
constexpr sfxenum_t sfx_fre139 = 639;
constexpr sfxenum_t sfx_fre140 = 640;
constexpr sfxenum_t sfx_fre141 = 641;
constexpr sfxenum_t sfx_fre142 = 642;
constexpr sfxenum_t sfx_fre143 = 643;
constexpr sfxenum_t sfx_fre144 = 644;
constexpr sfxenum_t sfx_fre145 = 645;
constexpr sfxenum_t sfx_fre146 = 646;
constexpr sfxenum_t sfx_fre147 = 647;
constexpr sfxenum_t sfx_fre148 = 648;
constexpr sfxenum_t sfx_fre149 = 649;
constexpr sfxenum_t sfx_fre150 = 650;
constexpr sfxenum_t sfx_fre151 = 651;
constexpr sfxenum_t sfx_fre152 = 652;
constexpr sfxenum_t sfx_fre153 = 653;
constexpr sfxenum_t sfx_fre154 = 654;
constexpr sfxenum_t sfx_fre155 = 655;
constexpr sfxenum_t sfx_fre156 = 656;
constexpr sfxenum_t sfx_fre157 = 657;
constexpr sfxenum_t sfx_fre158 = 658;
constexpr sfxenum_t sfx_fre159 = 659;
constexpr sfxenum_t sfx_fre160 = 660;
constexpr sfxenum_t sfx_fre161 = 661;
constexpr sfxenum_t sfx_fre162 = 662;
constexpr sfxenum_t sfx_fre163 = 663;
constexpr sfxenum_t sfx_fre164 = 664;
constexpr sfxenum_t sfx_fre165 = 665;
constexpr sfxenum_t sfx_fre166 = 666;
constexpr sfxenum_t sfx_fre167 = 667;
constexpr sfxenum_t sfx_fre168 = 668;
constexpr sfxenum_t sfx_fre169 = 669;
constexpr sfxenum_t sfx_fre170 = 670;
constexpr sfxenum_t sfx_fre171 = 671;
constexpr sfxenum_t sfx_fre172 = 672;
constexpr sfxenum_t sfx_fre173 = 673;
constexpr sfxenum_t sfx_fre174 = 674;
constexpr sfxenum_t sfx_fre175 = 675;
constexpr sfxenum_t sfx_fre176 = 676;
constexpr sfxenum_t sfx_fre177 = 677;
constexpr sfxenum_t sfx_fre178 = 678;
constexpr sfxenum_t sfx_fre179 = 679;
constexpr sfxenum_t sfx_fre180 = 680;
constexpr sfxenum_t sfx_fre181 = 681;
constexpr sfxenum_t sfx_fre182 = 682;
constexpr sfxenum_t sfx_fre183 = 683;
constexpr sfxenum_t sfx_fre184 = 684;
constexpr sfxenum_t sfx_fre185 = 685;
constexpr sfxenum_t sfx_fre186 = 686;
constexpr sfxenum_t sfx_fre187 = 687;
constexpr sfxenum_t sfx_fre188 = 688;
constexpr sfxenum_t sfx_fre189 = 689;
constexpr sfxenum_t sfx_fre190 = 690;
constexpr sfxenum_t sfx_fre191 = 691;
constexpr sfxenum_t sfx_fre192 = 692;
constexpr sfxenum_t sfx_fre193 = 693;
constexpr sfxenum_t sfx_fre194 = 694;
constexpr sfxenum_t sfx_fre195 = 695;
constexpr sfxenum_t sfx_fre196 = 696;
constexpr sfxenum_t sfx_fre197 = 697;
constexpr sfxenum_t sfx_fre198 = 698;
constexpr sfxenum_t sfx_fre199 = 699;
constexpr sfxenum_t NUMSFX = 700;

#endif
