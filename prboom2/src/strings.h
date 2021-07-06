#ifndef PRBOOM_PLUS_STRINGS_H
#define PRBOOM_PLUS_STRINGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

typedef struct {
  char *text;
  size_t len;
} string_t;

typedef struct string_elem_s {
  struct string_elem_s *next;
  string_t value;
} string_elem_t;

#ifdef __cplusplus
}
#endif

#endif  // PRBOOM_PLUS_STRINGS_H
