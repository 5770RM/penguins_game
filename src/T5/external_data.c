//
// Created by timur on 1/3/22.
//
#include "stdio.h"
#include "external_data.h"
#include "structures.h"
// input parameters: char* name
// return: state of the game in the file
// reads content of the file given in name, returns the state of the game given in the file
struct GameState* read_board(char* name) {
    struct GameState* gs;
    FILE *fp;
    char buff[255];
    fp = fopen(name, "r");

    //reads the number of columns from the file and assigns it
    fscanf(fp, "%s", buff);
    int board_x;
    sscanf(buff, "%d", &board_x);
    gs->board_x = board_x;

    //reads the number of rows from the file and assigns it
    fscanf(fp, "%s", buff);
    int board_y;
    sscanf(buff, "%d", &board_y);
    gs->board_y = board_y;

    //assigning map to board_tile**
    for(int i = 0; i < board_x; i++) {
        for (int j = 0; j < board_y; j++) {
            char tile[2];
            fscanf(fp,"%s", tile);
            gs->board[i][j].fishes = tile[0];
            gs->board[i][j].occupied = tile[1] == 0? 0 : tile[1];
        }
    }



    return gs;
}

// input parameters: struct GameState* state, char* name
// return: none
// writes a new file to location specified in name
void write_board(struct GameState* state, char* name) {

}

