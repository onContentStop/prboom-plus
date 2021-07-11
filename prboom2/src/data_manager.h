//
// Created by kyle2 on 7/11/21.
//

#ifndef PRBOOM_PLUS_DATA_MANAGER_H
#define PRBOOM_PLUS_DATA_MANAGER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

extern int organized_saves;

void data_InitSaveDir(void);
char *data_SaveGameName(int slot, bool demoSave);
char *data_DetectDirectory(const char *envHint, const char *argHint);
void data_InitDataDir(void);
const char *data_DataDir(void);

#ifdef __cplusplus
}
#endif

#endif  // PRBOOM_PLUS_DATA_MANAGER_H
