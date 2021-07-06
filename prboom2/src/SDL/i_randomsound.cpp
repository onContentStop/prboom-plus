#include "i_randomsound.h"

#include <iostream>
#include <random>

char *I_GetRandomSoundName(vec_str_t vec) {
  static std::random_device rd;
  static std::default_random_engine eng{rd()};

  std::uniform_int_distribution<> dist{0, vec.length - 1};
  int i = dist(eng);
  return vec.data[i];
}
