//
// Created by timur on 1/3/22.
//
#include "autonomous.h"

void execute_autonomous_command(struct GameState* state, int argc, char **argv) {

}

int invalid_cla(int argc, char **argv) {
	if (argc == 2) {
		if (strcmp(argv[1], "name") != 0) {
			fprintf(stderr, "[ERROR] Invalid command arguments! For the program to return player name first argument should be name.\n");
		}
	}
	//placement
	if (argc == 5) {
		if (strcmp(argv[1], "phase=placement") != 0) {
			fprintf(stderr, "[ERROR] Invalid command arguments! First argument is should be phase=placement.Possibly too many arguments.\n");
			return 0;
		}
		char* nptr;
		strstr(argv[2], "penguins=", nptr);
		if (nptr == NULL) {
			fprintf(stderr, "[ERROR] Invalid command arguments! The number of penguins is incorrect!\n");
			return 0;
		}
	}
	//movement
	if (argc == 4) {
		if (strcmp(argv[1], "phase=movement") != 0) {
			fprintf(stderr, "[ERROR]Invalid command arguments! First argument is should be phase=movement.Possibly too few arguments.\n");
			return 0;
		}
	}
	return 1;
}
