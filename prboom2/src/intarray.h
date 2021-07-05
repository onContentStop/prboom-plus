#ifndef PRBOOM_PLUS_INTARRAY_H
#define PRBOOM_PLUS_INTARRAY_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  int *data;
  long count;
  long capacity;
} intarray_t;

void intarray_init(intarray_t *a);
void intarray_free(intarray_t *a);
void intarray_push_back(intarray_t *a, int v);

#ifdef __cplusplus
}
#endif

#endif  // PRBOOM_PLUS_INTARRAY_H
