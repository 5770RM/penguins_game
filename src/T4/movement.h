#ifndef MOVFUNCTIONS
#define MOVFUNCTIONS
// for a given state of the game, decides if movement phase should be stopped = none of the players can move one of their penguins
// arguments: board, array of players
// returns: 1 if none of the players can move one of their penguins, 0 otherwise 
int movement_game_status(struct board_tile** board, struct player* players, int amount_of_players);

// for a given state of the game, decides if current player can move one of their penguins 
// arguments: board, array of players, number of players, size of the map
// returns: 1 if current players can move one of their penguins, 0 otherwise
int movement_possible(struct board_tile** board, struct player* players, int curr_player,int x,int y);

// decides if the movement m is possible = origin tile is occupied by one of current player's penguins, ther is no other penguins on a second tile and secone tile must be an ice floe
// agruments: movement m, current player number
// returns: 1 if movement is valid, 0 otherwise
int valid_movement(struct board_tile** board, struct movement m, int curr_player);

// displays the board to command line
void show_board(struct board_tile** board, int x, int y);
#endif
