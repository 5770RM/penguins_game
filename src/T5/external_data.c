//
// Created by timur on 1/3/22.
//
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "external_data.h"

// reads content of the file given in name, fills game state with date from a text file which path is specified in name
// arguments: game state, name of the file
// return: no value 
void read_board(struct GameState* gs, char* name) {
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
    player* players_array = malloc(sizeof(struct player)*number_of_players);
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
        *players_array = pl;
        number_of_players++;
    }
    gs->n = number_of_players;
    gs->players = playersArray;

    fclose(fp);
}

// input parameters: struct GameState* state, char* name
// return: none
// writes a new file to location specified in name
void write_board(struct GameState* gs, char* name) {
    FILE *fp;
    fp = fopen(name, "w");

    //writing number of columns
    char board_x_array[255];
    int board_x = gs->board_x;
    sprintf(board_x_array,"%d",board_x);
    fputs(board_x_array, fp);

    //space
    fputc(' ',fp);

    //writing number of rows
    char board_y_array[255];
    int board_y = gs->board_y;
    sprintf(board_y_array,"%d",board_y);
    fputs(board_y_array, fp);

    //new line
    fputc('\n',fp);

    //writing the map
    for(int i = 0; i < board_x; i++) {
        for (int j = 0; j < board_y; j++) {
            int number_of_fishes = gs->board[i][j].fishes;
            int occupied = gs->board[i][j].occupied;

            fputc('0' + number_of_fishes,fp); //adding '0' to convert int to char
            fputc('0' + occupied,fp);

            fputc(' ', fp);
        }
        fputc('\n',fp);
    }

    //writing player's name, number of collected fish and id
    int number_of_players = gs->n;
    for (int i = 0; i < number_of_players; i++) {
        fputs(gs->players[i].full_name, fp);
        fputc(' ', fp);

        int fish_collected = gs->players[i].fish_collected;
        char fish_collected_array[255];
        sprintf(fish_collected_array,"%d",fish_collected);
        fputs(fish_collected_array,fp);
        fputc(' ', fp);

        int player_id = gs->players[i].id;
        char player_id_array[255];
        sprintf(player_id_array,"%d",player_id);
        fputc('\n', fp);
    }

    fclose(fp);
}

