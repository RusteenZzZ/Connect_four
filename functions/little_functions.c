#include "./little_functions.h"

bool playable(GameTray* gameTray, int col){
  return get_value(gameTray, col, (*gameTray).height - 1) == Empty;
}

int get_value(GameTray* gameTray, int col, int row){
  return (*gameTray).board[row][col];
}