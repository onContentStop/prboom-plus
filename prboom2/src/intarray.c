#include "intarray.h"

#include <stddef.h>
#include <stdlib.h>

#define GROW_CAPACITY(c) (((c) == 0) ? 8 : (c)*2)

void intarray_init(intarray_t *a) {
  a->data = NULL;
  a->count = 0;
  a->capacity = 0;
}

void intarray_free(intarray_t *a) {
  if (a->data) {
    free(a->data);
  }
  intarray_init(a);
}

void intarray_push_back(intarray_t *a, int v) {
  if (a->count >= a->capacity) {
    a->capacity = GROW_CAPACITY(a->capacity);
    a->data = realloc(a->data, a->capacity);
  }
  a->data[a->count++] = v;
}
