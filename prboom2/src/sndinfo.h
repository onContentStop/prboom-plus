#ifndef PRBOOM_PLUS_SNDINFO_H
#define PRBOOM_PLUS_SNDINFO_H

#include "strings.h"

#ifdef __cplusplus
extern "C" {
#endif

extern int parse_sndinfo(void);
extern void random_decl(string_t name, string_elem_t *sounds);
extern void sound_decl(string_t name, string_t value);
extern void alias_decl(string_t name, string_t value);

#ifdef __cplusplus
}
#endif

#endif  // PRBOOM_PLUS_SNDINFO_H
