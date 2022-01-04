//
// Created by timur on 1/3/22.
//
#include "stdio.h"
#include "structures.h"
#include "external_data.h"
// input parameters: char* name
// return: state of the game in the file
// reads content of the file given in name, returns the state of the game given in the file
struct GameState* read_board(struct GameState* gs, char* name) {
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
    player* playersArray;
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
        *playersArray = pl;
        number_of_players++;
    }
    gs->n = number_of_players;
    gs->players = playersArray;

    fclose(fp);
    return gs;
}

// input parameters: struct GameState* state, char* name
// return: none
// writes a new file to location specified in name
void write_board(struct GameState* gs, char* name) {
    FILE *fp;
    fp = fopen(name, "w");

    //writing number of columns
    char board_x_array[BUFSIZ];
    int board_x = gs->board_x;
    sprintf(board_x_array,"%d",board_x);
    fputs(board_x_array, fp);

    //space
    fputc(' ',fp);

    //writing number of rows
    char board_y_array[BUFSIZ];
    int board_y = gs->board_y;
    sprintf(board_y_array,"%d",board_y);
    fputs(board_y_array, fp);

    //writing the map
    for(int i = 0; i < board_x; i++) {
        for (int j = 0; j < board_y; j++) {
            int number_of_fishes = gs->board[i][j].fishes;
            int occupied = gs->board[i][j].occupied;

            fputc('0' + number_of_fishes,fp); //adding '0' to convert int to char
            fputc('0' + occupied,fp);
        }
        fputc('\n',fp);
    }

//    int number_of_players = gs->n;
//    for (int i = 0; i < number_of_players; i++) {
//        for (int j = 0; j < 3; j++) {
//            fputs(gs->players[i].)
//        }
//    }


}

