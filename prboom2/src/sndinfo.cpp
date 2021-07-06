#include "sndinfo.h"

#include <iostream>
#include <unordered_map>
#include <vector>

#include "sounds.h"

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
}  // namespace sound_type

using vec_sfxinfo_t = vec_t(sfxinfo_t*);

static vec_sfxinfo_t changes;
static std::unordered_map<std::string, std::string> symbols;

int parse_sndinfo() {
  int lumpnum = W_CheckNumForName("SNDINFO");
  if (lumpnum == -1) {
    return 1;
  }
  const char* lump = static_cast<const char*>(W_CacheLumpNum(lumpnum));

  yyscan_t scanner;
  yylex_init(&scanner);
  auto* buffer = yy_scan_string(lump, scanner);
  yy_switch_to_buffer(buffer, scanner);
  int ret = yyparse(scanner);
  yy_delete_buffer(buffer, scanner);
  yylex_destroy(scanner);
  return ret;
}

static void warn_unknown_sound(string_t name) {
  std::cout << "[\x1b[1;33mWRN\x1b[0m] in SNDINFO: Unknown sound name "
            << std::string{name.text, name.text + name.len} << "\n";
}

void random_decl(string_t name, string_elem_t* sounds) {
  std::cout << "[\x1b[1;34mPAR\x1b[0m] RANDOM DECL: "
            << std::string{name.text, name.text + name.len} << "\n";
  int index = SFX_GetIndex(&name);
  if (index == -1) {
    warn_unknown_sound(name);
    return;
  }
  free(S_sfx[index].names.data[0]);
  vec_pop(&S_sfx[index].names);
  auto* next = sounds->next;
  for (auto* sound = sounds; sound; sound = next) {
    auto nameStr = std::string{name.text, name.text + name.len};
    char* name = nullptr;
    auto it = symbols.find(nameStr);
    if (it != symbols.end()) {
      name = static_cast<char*>(malloc(it->second.length() + 1));
      strncpy(name, it->second.data(), it->second.length());
    } else {
      name = static_cast<char*>(malloc(sound->value.len + 1));
      strncpy(name, sound->value.text, sound->value.len);
    }
    vec_push(&S_sfx[index].names, name);
    next = sound->next;
    free(sound);
  }
  vec_push(&changes, &S_sfx[index]);
}

static void replace_sound(char** location, string_t value);

void sound_decl(string_t name, string_t value) {
  symbols.emplace(std::string{name.text, name.text + name.len},
                  std::string{value.text, value.text + value.len});
  bool found = false;
  for (int i = 0; i < changes.length; ++i) {
    for (int j = 0; j < changes.data[i]->names.length; ++j) {
      if (!strncmp(changes.data[i]->names.data[j], name.text, name.len)) {
        found = true;
        replace_sound(&changes.data[i]->names.data[j], value);
      }
    }
  }

  if (!found) {
    int index = SFX_GetIndex(&name);
    if (index == -1) {
      warn_unknown_sound(name);
      return;
    }
    replace_sound(&S_sfx[index].names.data[0], value);
  }
}

static void replace_sound(char** location, string_t value) {
  free(*location);
  int offset = 0;
  if (!strncmp(value.text, "ds", 2) || !strncmp(value.text, "dp", 2)) {
    offset = 2;
  }
  *location = static_cast<char*>(malloc(value.len - offset + 1));
  strncpy(*location, value.text + offset, value.len - offset);
}
