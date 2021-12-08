#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "placement.h"
// #include "gameplay_functions.h"

// executing placement
void execute_placement(struct board_tile** board, struct player* players, int curr_player, struct placement p) {
	board[p.to.y][p.to.x].occupied = players[curr_player].id; // show player's id on the board
	board[p.to.y][p.to.x].fishes = 0;
	players[curr_player].pen_not_placed--; // reduce number of penguins of current player after every successful placement
	players[curr_player].fish_collected++; // update the score of the current player	
}

int placement_game_status(struct board_tile** board, int x, int y, struct player* players, int n) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (board[i][j].fishes == 1) {
				for (int i = 0; i < n; i++) {
					if (players[i].pen_not_placed != 0) {
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

int placement_possible(struct board_tile** board, int x, int y, struct player* players, int curr_player) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (board[i][j].fishes == 1) {
				if (players[curr_player].pen_not_placed == 0)
					return 0;
				else
					return 1;
			}
		}
	}
	return 0;
}

int valid_placement(struct board_tile** board, int x, int y, struct placement p) {
	if ((p.to.x > 0) && (p.to.y > 0) && (p.to.x < x) && (p.to.y < y) && board[p.to.y][p.to.x].fishes == 1 && board[p.to.y][p.to.x].occupied == 0)
		return 1;
	else
		return 0;
}



/*struct placement get_placement() {
	int placement_x, placement_y;
	printf("Please enter X coordinate (only tiles with 1 fish): \n");
	scanf("%d", &placement_x);
	printf("Please enter Y coordinate (only tiles with 1 fish): \n");
	scanf("%d", &placement_y);
	struct placement coord = { placement_x, placement_y };
	return coord;
} */
