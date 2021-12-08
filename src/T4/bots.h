#ifndef BOTS
#define BOTS
// find which tiles the bot can place its penguins on
int bot_possible_placement(struct board_tile **board, struct player *players, int x_size, int y_size);
// place bot's penguins
void bot1_placement_execution(struct board_tile **board, struct player *players, struct bot_placement *placements, struct placement p, int curr_player, int place_counter);
// find all penguins the bot can move and store them in an array
int bot1_choosing_penguin(struct board_tile **board, struct player *players, int x_size, int y_size, int curr_player);
// choose penguin which the bot will operate next and store penguins cords
void bot1_choosing_execution(struct board_tile **board, struct player *players, struct bot_choosing *choice, struct movement m, int curr_player, int choosing_counter);
// find all the tiles the penguin could move onto
int bot1_choosing_movement(struct board_tile **board, struct player *players, struct movement m, int x_size, int y_size, int curr_player);
// 
void bot1_mov_choosing_execution(struct board_tile **board, struct player *players, struct bot_movement *mov_choice, struct movement m, int curr_player, int movement_counter);
#endif
