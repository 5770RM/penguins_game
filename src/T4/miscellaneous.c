#include "structures.h"
#include "miscellaneous.h"
#include <stdlib.h>
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

// IMPORTANT! in 2D array of the map first [] is for y, second [] is for x
struct board_tile** new_board(int x, int y) {
    struct board_tile** board = (struct board_tile**)malloc(y * sizeof(struct board_tile*));
    int i;
    for (i = 0; i < y; i++)
        board[i] = (struct board_tile*)malloc(x * sizeof(struct board_tile));

    return board;
}

void free_board(struct board_tile** board, int x, int y) {
    int i;
    for (i = 0; i < y; i++)
        free(board[i]);

    free(board);
}

void init_game() {}
void end_game() {}
