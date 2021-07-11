//
// Created by kyle2 on 7/11/21.
//

#include "data_manager.h"

#include <sys/stat.h>

#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "config.h"
#include "d_deh.h"
#include "e6y.h"
#include "i_system.h"
#include "lprintf.h"
#include "m_argv.h"
#include "string_case.h"
#include "w_wad.h"

int organized_saves;
static std::string base_save_dir;
static std::string wad_save_dir;
static std::string data_root = string::snakeCase(PACKAGE_NAME) + "_data";
static std::vector<std::string> data_dir_strings;
static std::string base_data_dir;
static std::string wad_data_dir;

static void normalizeSlashes(std::string* str) {
  if (!str || str->empty()) {
    return;
  }
  std::filesystem::path p{*str};
  *str = p.make_preferred().string();
  //  if (str->ends_with("\\") || str->ends_with("/")) {
  //    str->replace(str->length() - 1, 1, "");
  //  }
  //  size_t pos = str->length() - 1;
  //  while ((pos = str->rfind('\\', pos)) != std::string::npos) {
  //    str->replace(pos, 1, "/");
  //    ++pos;
  //  }
}

static void initWadDataDir() {
  int iwadIndex = 1;
  int pwadIndex = 2;
  data_dir_strings.emplace_back(data_root);

  for (int i = 0; i < numwadfiles; ++i) {
    std::string start = PathFindFileName(wadfiles[i].name);
    if (start.ends_with(".wad")) {
      int dirIndex;
      if (wadfiles[i].src == source_iwad) {
        dirIndex = iwadIndex;
      } else if (wadfiles[i].src == source_pwad) {
        dirIndex = pwadIndex;
      } else {
        dirIndex = -1;
      }

      if (dirIndex >= 0) {
        data_dir_strings.emplace_back(
            string::lowerCase(start.substr(0, start.length() - 4)));
        if (dirIndex == pwadIndex) {
          ++pwadIndex;
        }
      }
    }
  }

  wad_data_dir = base_data_dir;
  for (auto& dds : data_dir_strings) {
    wad_data_dir += "/";
    wad_data_dir += dds;

    struct stat sbuf {};
    if (stat(wad_data_dir.c_str(), &sbuf) || !S_ISDIR(sbuf.st_mode)) {
      std::filesystem::create_directory(wad_data_dir);
    }
  }

  lprintf(LO_INFO, "Using data file directory: %s\n", wad_data_dir.c_str());
}

void data_InitSaveDir() {
  base_save_dir = data_DetectDirectory("DOOMSAVEDIR", "-save");
}
void data_InitDataDir() {
  base_data_dir = data_DetectDirectory("DOOMDATADIR", "-data");
}
char* data_DetectDirectory(const char* envHint, const char* argHint) {
  const char* default_directory = getenv(envHint);
  if (!default_directory) {
    default_directory = I_DoomExeDir();
  }

  std::string result;
  int i = M_CheckParm(argHint);
  if (i != 0 && i < myargc - 1) {
    struct stat sbuf {};
    if (!stat(myargv[i + 1], &sbuf) && S_ISDIR(sbuf.st_mode)) {
      result = myargv[i + 1];
    } else {
      lprintf(LO_ERROR,
              "Error: path does not exist: %s; using default directory %s\n",
              argHint, default_directory);
    }
  }

  if (result.empty()) {
    result = default_directory;
  }

  normalizeSlashes(&result);

  return strToC(result);
}
const char* data_DataDir(void) {
  if (wad_data_dir.empty()) {
    initWadDataDir();
  }
  return wad_data_dir.c_str();
}
std::string_view saveDir() {
  if (organized_saves) {
    if (wad_save_dir.empty()) {
      wad_save_dir = data_DataDir();
    }
    return wad_save_dir;
  }
  return base_save_dir;
}
char* data_SaveGameName(int slot, bool demoSave) {
  if (slot < 0 || slot > 9999) {
    I_Error("data_SaveGameName: invalid slot: %d\n", slot);
  }

  auto sd = saveDir();
  const char* st = demoSave ? "demosav" : savegamename;
  std::stringstream name;
  name << sd << "/" << st << slot << ".dsg";
  return strToC(name.str());
}
