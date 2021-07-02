#include "./draw_game_tray.h"
#include <stdio.h>
#include "./../macros/colors.h"

void draw_game_tray(GameTray* gameTray){
  printf("\n");
  for(int i=(*gameTray).height-1; i>=0; i--){
    for(int j=0; j<(*gameTray).width; j++){
      switch((*gameTray).board[i][j]){
        case Empty:
          printf(ANSI_COLOR_EMPTY "  " ANSI_COLOR_RESET " ");
          break;
        case Player1:
          printf(ANSI_COLOR_PLAYER1 "  " ANSI_COLOR_RESET " ");
          break;
        case Player2:
          printf(ANSI_COLOR_PLAYER2 "  " ANSI_COLOR_RESET " ");
      }
    }
    printf("\n\n");
  }
  for(int i=1; i<=gameTray->width; i++){
    printf(" %d ", i);
  }
  printf("\n");
}