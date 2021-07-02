UNAME := $(shell uname)

ifeq ($(UNAME),Linux)
	FILES := main.c clear_screen_posix.c ./functions/draw_game_tray.c ./functions/if_game_is_finished.c ./functions/little_functions.c
else ifeq ($(UNAME), Windows)
	FILES := main.c clear_screen_windows.c ./functions/draw_game_tray.c ./functions/if_game_is_finished.c ./functions/little_functions.c
else ifeq ($(UNAME), Darwin)
	FILES := main.c clear_screen_posix.c ./functions/draw_game_tray.c ./functions/if_game_is_finished.c ./functions/little_functions.c
endif

all: exec

object:
	gcc $(FILES) -c

exec: object
	gcc *.o -o main

dist:
	zip -r compressed.zip ./

clear:
	rm *.o