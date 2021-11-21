// arguments: none
// returns: number of players
int get_nbr_of_players();

// arguments: none
// returns: number of penguins
int get_nbr_of_penguins();

// aguments: pointer to array's first index and number n of players to be initialized - score, penguins left etc.
// returns: no value 
void init_players(struct player* array, int n);

// arguments: none
// returns: the size of the map's x dimension
int get_x_dimension();

// arguments: none
// returns: the size of the map's y dimension
int get_y_dimension();

// each tile for the board is filled with new values
// arguments: board, board's x and y dimension
// returns: no value
void generate_board(struct board_tile** board, int x, int y);

// argumenst: number of players
// returns: random number from range 0..n-1
int choose_first_player(int n);

// for a given state of the game, decides if placement phase should be stopped = none of the players can place one of their penguins
// arguments: board, array of players
// returns: 1 if none of the players can place a penguin, 0 otherwise 
int placement_game_status(struct board_tile** board, struct player* players);

// for a given state of the game, decides if current player can place one of their penguins 
// arguments: board, array of players
// retusn: 1 if current players can place one of their penguins, 0 otherwise
int placement_possible(struct board_tile** board, struct player* players, int curr_player);

// asks user for coordinates of placement of one of their unplaced penguins
// arguments: none
// returns: placement type 
struct placement get_placement();

// decides if the placement p is possible = no other penguins on a tile and tile is an ice floe
// agruments: board, placement
// returns: 1 if placement is valid, 0 otherwise
int valid_placement(struct board_tile** board, struct placement p);

// based of the premise that placement p is valid, places the penguin on board at coordinates specified in p, updates score of current player
// arguments: board, array of players, current player, valid placement
// returns: no value
void execute_placement(struct board_tile** board, struct player* players, int curr_player, struct placement p);

// for a given state of the game, decides if movement phase should be stopped = none of the players can move one of their penguins
// arguments: board, array of players
// returns: 1 if none of the players can move one of their penguins, 0 otherwise 
int movement_game_status(struct board_tile** board, struct player* players);

// for a given state of the game, decides if current player can move one of their penguins 
// arguments: board, array of players
// retusn: 1 if current players can move one of their penguins, 0 otherwise
int movement_possible(struct board_tile** board, struct player* players, int curr_player);

// asks user for coordinates of the tile the penguins is being move from and coordinates of the tile the penguins is moved to
// arguments: none
// returns: movement  
struct movement get_movement();

// decides if the movement m is possible = origin tile is occupied by one of current player's penguins, ther is no other penguins on a second tile and secone tile must be an ice floe
// agruments: movement m, current player number
// returns: 1 if movement is valid, 0 otherwise
int valid_movement(struct board_tile** board, struct movement m, int curr_player);

// based of the premise that movement m is valid, places the penguin on board at coordinates specified in m, remove the ice floe the penguin was standing on, update score of current player
// arguments: board, array of players, current player, valid movement
// returns: no value
void execute_movement(struct board_tile** board, struct player* players, int curr_player, struct movement m);

// base on the number of players takes the next one, for example (curr_player+1)%n
void next_player(int curr_player, int n);

// displays the board to command line
void show_board(struct board_tile** board, int x, int y);

// looks at score of every player and decides which one should win
// arguments: array of players, number of players
// returns: id of the winner
int determine_winner(struct player* players, int n);

// TO-DO
void init_game();
void end_game();
