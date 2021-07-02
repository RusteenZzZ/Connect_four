#include "if_game_is_finished.h"
#include <stdio.h>

bool ifGameIsFinished(GameTray* gameTray, int col, int row, holeState player){
  // Horisontal check
  int numOfSequentialTokens = 0;

  for(int c=col-3; c<=col+3; c++){
    // Check if the column value is valid
    if(c < 0 || c >= (*gameTray).width) continue;

    if(get_value(gameTray, c, row) == player) numOfSequentialTokens++;
    else numOfSequentialTokens = 0;

    if(numOfSequentialTokens == 4){
      printf("The winner is Player%d!!!\n", player);
      return true;
    }
  }

  // Vertical check
  numOfSequentialTokens = 0;

  for(int r=row-3; r<=row+3; r++){
    // Check if the row value is valid
    if(r < 0 || r >= (*gameTray).height) continue;

    if(get_value(gameTray, col, r) == player) numOfSequentialTokens++;
    else numOfSequentialTokens = 0;

    if(numOfSequentialTokens == 4){
      printf("The winner is Player%d!!!\n", player);
      return true;
    }
  }

  // Diagonal check of slope 1
  numOfSequentialTokens = 0;

  int c = col+3;
  int r = row+3;

  for(int t=0; t<7; t++){
    // Check if the column value is valid
    if(c < 0 || c >= (*gameTray).width) continue;

    // Check if the row value is valid
    if(r < 0 || r >= (*gameTray).height) continue;

    if(get_value(gameTray, c, r) == player) numOfSequentialTokens++;
    else numOfSequentialTokens = 0;

    if(numOfSequentialTokens == 4){
      printf("The winner is Player%d!!!\n", player);
      return true;
    }

    c--;
    r--;
  }

  // Diagonal check of slope -1
  numOfSequentialTokens = 0;

  c = col-3;
  r = row+3;

  for(int t=0; t<4; t++){
    // Check if the column value is valid
    if(c < 0 || c >= (*gameTray).width) continue;

    // Check if the row value is valid
    if(r < 0 || r >= (*gameTray).height) continue;

    if(get_value(gameTray, c, r) == player) numOfSequentialTokens++;
    else numOfSequentialTokens = 0;

    if(numOfSequentialTokens == 4){
      printf("The winner is Player%d!!!\n", player);
      return true;
    }

    c++;
    r--;
  }

  // Check for the draw
  int i = 0;
  for(i; i<(*gameTray).width; i++){
    if(playable(gameTray, i)) break;
  }

  // If i has reached the value of width, it means that there was no
  // any playable column left, so it's draw
  if(i == (*gameTray).width) {
    printf("Draw!!!\n");
    return true;
  }

  return false;
};