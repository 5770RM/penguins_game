#ifndef STRUCTS
#define STRUCTS
struct player {
    int id;
    char name;
    int fish_collected;
    int penguins;       //number of penguins, should not be changed
    int pen_not_placed; //number of penguins which are not placed
};

struct board_tile {
    int occupied;   //id of player which occupies this tile or -1 if it is not occupied
    int fishes;     //if it is equal to 0 then it is an ice floe, if it is equal to 1 or 2 or 3 then it has this amount of fish on it, otherwise it is equal to -1
};

struct coordinate {
    int x;
    int y;
};

struct placement {
    struct coordinate to;
};

struct movement {
    struct coordinate from;
    struct coordinate to;
};

struct GameState {
    struct board_tile** board;
    struct player* players;
    int board_x, board_y; // board dims
    int n;  // number of players
};

#endif