#include "g_weaponstats.h"

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <sstream>

#include "info.h"
extern "C" {
#include "doomdef.h"
#include "doomstat.h"
#include "i_system.h"
#include "info_helpers.h"
#include "lprintf.h"
}

#undef malloc
#undef free
#undef realloc

static void parse(weaponstats_t *stats, const nlohmann::json &j);
static nlohmann::json serialize(const weaponstats_t &stats);

static std::stringstream weaponstatsfilename;

weaponstats_t weaponstats[NUMWEAPONS];

void weaponstats_init(weaponstats_t *stats) {
  stats->kills = 0;
  stats->shots = 0;
  for (mobjtype_t mt = MT_PLAYER; mt < NUMMOBJTYPES;
       mt = static_cast<mobjtype_t>(static_cast<int>(mt) + 1)) {
    stats->monsters[mt] = 0;
  }
  vec_init(&stats->distances);
}

void weaponstats_free(weaponstats_t *stats) { vec_deinit(&stats->distances); }

void weaponstats_cleanup(void) {
  for (int i = 0; i < NUMWEAPONS; i++) {
    weaponstats_free(&weaponstats[i]);
  }
}

void weaponstats_register_kill(weaponstats_t *stats, mobjtype_t type,
                               int distance) {
  ++stats->kills;
  ++stats->monsters[type];
  vec_push(&stats->distances, distance);
}

void weaponstats_register_shot(weaponstats_t *stats) { ++stats->shots; }

void weaponstats_load() {
  std::cout << "weaponstats_load: Load weapon stats.\n";
  weaponstatsfilename << I_DoomExeDir() << "/weaponstats.json";
  std::ifstream weaponstatsfile{weaponstatsfilename.str()};
  if (!weaponstatsfile) {
    std::cout << "[\x1b[1mLOG\x1b[0m] Weapon stats file not found at "
              << weaponstatsfilename.str() << "\n";
    return;
  }
  nlohmann::json j;
  weaponstatsfile >> j;

  if (!j.is_object()) {
    std::cout
        << "[\x1b[1;31mERR\x1b[0m] Weapon stats file is not a JSON object.\n";
    return;
  }

  if (j.find("fist") != j.end()) {
    parse(&weaponstats[wp_fist], j["fist"]);
  }
  if (j.find("pistol") != j.end()) {
    parse(&weaponstats[wp_pistol], j["pistol"]);
  }
  if (j.find("shotgun") != j.end()) {
    parse(&weaponstats[wp_shotgun], j["shotgun"]);
  }
  if (j.find("chaingun") != j.end()) {
    parse(&weaponstats[wp_chaingun], j["chaingun"]);
  }
  if (j.find("rocket launcher") != j.end()) {
    parse(&weaponstats[wp_missile], j["rocket launcher"]);
  }
  if (j.find("plasma rifle") != j.end()) {
    parse(&weaponstats[wp_plasma], j["plasma rifle"]);
  }
  if (j.find("bfg 9000") != j.end()) {
    parse(&weaponstats[wp_bfg], j["bfg 9000"]);
  }
  if (j.find("chainsaw") != j.end()) {
    parse(&weaponstats[wp_chainsaw], j["chainsaw"]);
  }
  if (j.find("super shotgun") != j.end()) {
    parse(&weaponstats[wp_supershotgun], j["super shotgun"]);
  }
}

void weaponstats_save() {
  nlohmann::json j;
  j["fist"] = serialize(weaponstats[wp_fist]);
  j["pistol"] = serialize(weaponstats[wp_pistol]);
  j["shotgun"] = serialize(weaponstats[wp_shotgun]);
  j["chaingun"] = serialize(weaponstats[wp_chaingun]);
  j["rocket launcher"] = serialize(weaponstats[wp_missile]);
  j["plasma rifle"] = serialize(weaponstats[wp_plasma]);
  j["bfg 9000"] = serialize(weaponstats[wp_bfg]);
  j["chainsaw"] = serialize(weaponstats[wp_chainsaw]);
  j["super shotgun"] = serialize(weaponstats[wp_supershotgun]);
  std::ofstream weaponstatsfile{weaponstatsfilename.str()};
  weaponstatsfile << j.dump(2);
}

static void parse(weaponstats_t *stats, const nlohmann::json &j) {
  if (j.find("kills") != j.end() && j["kills"].is_number()) {
    stats->kills = j["kills"];
  }
  if (j.find("shots") != j.end() && j["shots"].is_number()) {
    stats->shots = j["shots"];
  }
  if (j.find("distances") != j.end() && j["distances"].is_array()) {
    for (int i = 0; i < j["distances"].size(); ++i) {
      vec_push(&stats->distances, j["distances"][i]);
    }
  }
  if (j.find("monsters") != j.end() && j["monsters"].is_object()) {
    for (const auto &m : j["monsters"].items()) {
      mobjtype_t mt;
      if (!INFO_mobjtype_from_name(m.key().data(), &mt)) {
        std::cout
            << "[\x1b[1;31mERR\x1b[0m] Weapon stats file has invalid mobj type "
            << m.key() << "\n";
        continue;
      }
      if (!m.value().is_number()) {
        std::cout << "[\x1b[1;31mERR\x1b[0m] Weapon stats file has invalid "
                     "monster kill count "
                  << m.value() << "\n";
        continue;
      }
      stats->monsters[mt] = m.value();
    }
  }
}

static nlohmann::json serialize(const weaponstats_t &stats) {
  nlohmann::json j;
  j["kills"] = stats.kills;
  j["shots"] = stats.shots;
  j["distances"] = std::vector<int>{};
  for (int i = 0; i < stats.distances.length; ++i) {
    j["distances"].push_back(stats.distances.data[i]);
  }
  j["mobjkills"] = nlohmann::json{};
  for (mobjtype_t mt = MT_PLAYER; mt < NUMMOBJTYPES;
       mt = static_cast<mobjtype_t>(static_cast<int>(mt) + 1)) {
    if (stats.monsters[mt] > 0) {
      j["mobjkills"].emplace(INFO_mobjtype_name(mt), stats.monsters[mt]);
    }
  }
  return j;
}
