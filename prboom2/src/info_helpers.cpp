#include "info_helpers.h"

const char *const INFO_mobjtype_name(mobjtype_t mt) {
  return magic_enum::enum_name(mt).data();
}

dboolean INFO_mobjtype_from_name(const char *const name, mobjtype_t *mt) {
  auto m = magic_enum::enum_cast<mobjtype_t>(name);
  if (m) {
    *mt = *m;
    return true;
  }
  return false;
}
