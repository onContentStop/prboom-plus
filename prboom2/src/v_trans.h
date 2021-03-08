#ifndef __V_TRANS__
#define __V_TRANS__

#include "d_ticcmd.h"
enum
{
    CR_NONE,
    CR_RED2BLUE,
    CR_RED2GREEN,
    CRMAX
};

extern byte *cr[CRMAX];

#endif