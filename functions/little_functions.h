#ifndef LITTLE_FUNCTIONS
#define LITTLE_FUNCTIONS

#include <stdbool.h>
#include "./../game_tray_structure.h"
#include "./../hole_state_enum.h"

bool playable(GameTray* gameTray, int col);

int get_value(GameTray* gameTray, int col, int row);

#endif