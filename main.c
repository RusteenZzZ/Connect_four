#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "game_tray_structure.h"
#include "clear_screen.h"
#include "./macros/colors.h"
#include "./macros/game_board_size.h"
#include "./hole_state_enum.h"
#include "./functions/draw_game_tray.h"
#include "./functions/if_game_is_finished.h"
#include "./functions/little_functions.h"

GameTray gameTray;

GameTray* new_game_tray(int width, int height){
  gameTray.width = width;
  gameTray.height = height;

  
  gameTray.board = (int **)malloc(height * sizeof(int *));
  for(int i=0; i<height; i++){
    gameTray.board[i] = (int *)malloc(width * sizeof(int));
  }

  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      gameTray.board[i][j] = Empty;
    }
  }

  return &gameTray;
};

void delete_game_tray(GameTray* gameTray){
  free((*gameTray).board);
  return;
}

void set_value(GameTray* gameTray, int col, int row, enum holeState token){
  (*gameTray).board[row][col] = token;
  return;
}

int first_free(GameTray* gameTray, int col){
  for(int row=0; row<(*gameTray).height; row++){
    if((*gameTray).board[row][col] == Empty) return row;
  }
}

// Returns true if the token was put successfully
// Returns false if the chosen column was not able to put a token
bool play(GameTray* gameTray, int col, holeState player){
  if(!playable(gameTray, col)) return false;

  set_value(gameTray, col, first_free(gameTray, col), player);
  return true;
}

int main(){
  GameTray* myGameTray = new_game_tray(NUM_OF_COLUMNS, NUM_OF_ROWS);

  int player = 1;
  int col, row;

  while(true){
    clear_screen();

    draw_game_tray(myGameTray);

    if(player == 1){

      while(true){
        printf("Player1, choose the column:\n");
        scanf("%d", &col);
        col--;

        if(col < 0 || col >= myGameTray->width){
          printf("Try again!\n");
          continue;
        };
        if(playable(myGameTray, col)) break;
      }
      
      row = first_free(myGameTray, col);

      set_value(myGameTray, col, row, Player1);

      if(ifGameIsFinished(myGameTray, col, row, Player1)) break;
    }else{

      while(true){
        printf("Player2, choose the column:\n");
        scanf("%d", &col);
        col--;

        if(col < 0 || col >= myGameTray->width){
          printf("Try again!\n");
          continue;
        };

        if(playable(myGameTray, col)) break;
      }

      row = first_free(myGameTray, col);

      set_value(myGameTray, col, row, Player2);

      if(ifGameIsFinished(myGameTray, col, row, Player2)) break;
    }

    player = -player;
  }

  draw_game_tray(myGameTray);

  delete_game_tray(myGameTray);

  return 0;
}