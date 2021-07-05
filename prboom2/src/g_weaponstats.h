#ifndef PRBOOM_PLUS_G_WEAPONSTATS_H
#define PRBOOM_PLUS_G_WEAPONSTATS_H

#include "info.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <vec.h>

#include "doomdef.h"

typedef struct {
  int kills;
  int shots;
  int monsters[NUMMOBJTYPES];
  vec_int_t distances;
} weaponstats_t;

extern weaponstats_t weaponstats[NUMWEAPONS];

void weaponstats_init(weaponstats_t *stats);
void weaponstats_free(weaponstats_t *stats);
void weaponstats_cleanup(void);
void weaponstats_register_kill(weaponstats_t *stats, mobjtype_t type,
                               int distance);
void weaponstats_register_shot(weaponstats_t *stats);
void weaponstats_load(void);
void weaponstats_save(void);

#ifdef __cplusplus
}
#endif

#endif  // PRBOOM_PLUS_G_WEAPONSTATS_H
