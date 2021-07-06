#include "sndinfo.h"

#include <iostream>
#include <vector>

// clang-format off
extern "C" {
#include <sndinfo.parse.h>
#include <sndinfo.lex.h>
}
// clang-format on

#include "w_wad.h"

namespace sound_type {
enum {
  ACTIVE,
  ATTACK,
  DEATH,
  PAIN,
  SEE,
};
}

int parse_sndinfo() {
  int lumpnum = W_CheckNumForName("SNDINFO");
  if (lumpnum == -1) {
    return 1;
  }
  const char* lump = static_cast<const char*>(W_CacheLumpNum(lumpnum));

  yyscan_t scanner;
  yylex_init(&scanner);
  auto buffer = yy_scan_string(lump, scanner);
  yy_switch_to_buffer(buffer, scanner);
  int ret = yyparse(scanner);
  yy_delete_buffer(buffer, scanner);
  yylex_destroy(scanner);
  return ret;
}

void random_decl(string_t name, string_elem_t* sounds) {
  std::cout << "[\x1b[1;34mPAR\x1b[0m] RANDOM DECL: "
            << std::string{name.text, name.text + name.len} << "\n";
  std::vector<std::string> soundsVec;
  auto* next = sounds->next;
  for (auto* sound = sounds; sound; sound = next) {
    next = sound->next;
    soundsVec.emplace_back(sound->value.text,
                           sound->value.text + sound->value.len);
    free(sound);
  }
}
