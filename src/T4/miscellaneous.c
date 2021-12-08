#include "structures.h"
#include "miscellaneous.h"
#include <stdio.h>

int choose_first_player(int n) {
	int first_player = 1;
	return first_player;
}

void next_player(int* curr_player, int n) {
	*curr_player = (*curr_player - 1 + 1) % n + 1;
}

void placement_init() {
    printf("-------------------\n");        
    printf("| PLACEMENT PHASE |\n");    
    printf("-------------------\n");    
}

void movement_init() {
    printf("------------------\n");        
    printf("| MOVEMENT PHASE |\n");    
    printf("------------------\n");    
}

void init_game() {}
void end_game() {}
