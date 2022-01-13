//
// Created by timur on 1/3/22.
//
#include "structures.h"
#include "defines.h"
#include "bots.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void execute_autonomous_command(struct GameState* state, int argc, char **argv) {

}

void invalid_cla_check(int argc, char **argv) {
	if (argc == 2) {
		if (strcmp(argv[1], "name") != 0) {
			fprintf(stderr, "[ERROR] Invalid command arguments! For the program to return player name first argument should be name.\n");
		}
        exit( CLA_FAILURE );
	}
	//placement
	if (argc == 5) {
		if (strcmp(argv[1], "phase=placement") != 0) {
			fprintf(stderr, "[ERROR] Invalid command arguments! First argument is should be phase=placement.Possibly too many arguments.\n");
            exit( CLA_FAILURE );
		}
		char* nptr;
		strstr(argv[2], "penguins=", nptr);
		if (nptr == NULL) {
			fprintf(stderr, "[ERROR] Invalid command arguments! The number of penguins is incorrect!\n");
            exit( CLA_FAILURE );
		}
	}
	//movement
	if (argc == 4) {
		if (strcmp(argv[1], "phase=movement") != 0) {
			fprintf(stderr, "[ERROR]Invalid command arguments! First argument is should be phase=movement.Possibly too few arguments.\n");
            exit( CLA_FAILURE );
		}
	}
}

int nick_used(struct player* players, int n, char *nick) {
    for (int i=0; i<n; ++i) {
        if (strcmp(players[i], nick) == 0)
            return 1;
    }
    return 0;
}

void add_new_player(struct player** players, int *n, int id, char *name, char *full_name, int penguins, int pen_not_placed, int movement_status, int bot, int bot_level) {
    *players = realloc(players, sizeof(struct player)*(*n+1));
    (*players)[(*n)++] = (struct player){id, name, full_name, penguins, pen_not_placed, movment_status, bot, bot_level}; 
}
