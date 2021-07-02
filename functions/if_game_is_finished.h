#ifndef IF_GAME_IS_FINISHED
#define IF_GAME_IS_FINISHED

#include <stdbool.h>
#include "./../game_tray_structure.h"
#include "./../hole_state_enum.h"
#include "./little_functions.h"

bool ifGameIsFinished(GameTray* gameTray, int col, int row, holeState player);

#endif