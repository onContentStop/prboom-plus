#ifndef PRBOOM_PLUS_INFO_HELPERS_H
#define PRBOOM_PLUS_INFO_HELPERS_H

#include "info.h"

#ifdef __cplusplus
extern "C" {
#endif

const char *const INFO_mobjtype_name(mobjtype_t mt);
dboolean INFO_mobjtype_from_name(const char *const name, mobjtype_t *mt);

#ifdef __cplusplus
}
#endif

#endif  // PRBOOM_PLUS_INFO_HELPERS_H
