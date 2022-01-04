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
    //reading information about player and assigning it to players*
    int number_of_players = 0;
    int counter_of_row = 0;
    int flag = 1;
    while (flag) {
        struct player pl;
        for(int i = 0; i < 3; i++) {
            if(fscanf(fp, "%s", buff) == EOF) {
                flag = 0;
                break;
            }
            if(counter_of_row == 0) {
                pl.full_name = buff;
                counter_of_row++;
            } else if(counter_of_row == 1) {
                pl.id = buff[0];//because id is from 0 to 9
                counter_of_row++;
            } else {
                int number_of_fish_collected;
                sscanf(buff, "%d", &number_of_fish_collected);
                pl.fish_collected = number_of_fish_collected;
                counter_of_row = 0;
            }
        }
        gs->players[number_of_players] = pl;
        number_of_players++;
    }
    gs->n = number_of_players;
    return gs;
}

// input parameters: struct GameState* state, char* name
// return: none
// writes a new file to location specified in name
void write_board(struct GameState* state, char* name) {

}

