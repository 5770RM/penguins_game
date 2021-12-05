//
// Created by timur on 12/5/21.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "command_line_ui.h"

/*
input parameters: none
return: integer
this function asks a user for an input and returns an integer for number of players.
*/
int get_nbr_of_players() {
    int number_of_players;
    printf("Enter the number of players(from 1 to 9):");
    scanf("%i", &number_of_players);
    while (number_of_players < 1 || number_of_players >= 9) {
        printf("Wrong number of players. Please try again:");
        scanf("%i", &number_of_players);
    }
    return number_of_players;

}

/*
input parameters: none
return: integer
this function asks a user for an input and returns an integer for number of penguins.
*/
int get_nbr_of_penguins() {
    int number_of_penguins;
    printf("Enter the number of penguins(from 1 to 5):");
    scanf("%i", &number_of_penguins);
    while (number_of_penguins < 1 || number_of_penguins >= 5) {
        printf("Wrong number of penguins. Please try again:");
        scanf("%i", &number_of_penguins);
    }
    return number_of_penguins;
}

/*
input parameters: struct player* players, int number_of_players
return: none
this function gets an array and number of players as an input and asks each player for name, simultaneously assigning names to array.
*/
void init_players(struct player* players, int number_of_players) {
    for (int i = 0; i < number_of_players; i++) {
        char ch;
        printf("Enter the name of the %ist player(only one character):", i + 1);
        scanf(" %c", &ch);
        while (ch < 'A' || ch > 'z') {
            printf("Invalid name, try again:");
            scanf("%c", &ch);
        }
        players[i].name = ch;
    }
}

/*
input parameters: none
return: integer
this function asks a user for number of columns of a board.
*/
int get_x_dimension() {
    int x;
    printf("Enter how many columns you want in the board(from 2 to 16):");
    scanf("%i", &x);
    while (x < 2 || x > 16) {
        printf("Wrong number of columns. Please try again:");
        scanf("%i", &x);
    }
    return x;
}

/*
input parameters: none
return: integer
this function asks a user for number of rows of a board.
*/
int get_y_dimension() {
    int y;
    printf("Enter how many rows you want in the board(from 2 to 16):");
    scanf("%i", &y);
    while (y < 2 || y > 16) {
        printf("Wrong number of rows. Please try again:");
        scanf("%i", &y);
    }
    return y;
}

/*
input parameters: int number_of_columns, int number_of_rows
return: movement type
this function asks a user for a movement and returns it.
*/
struct movement get_movement(int number_of_columns, int number_of_rows) {
    int x, y;
    printf("Enter x-coordinate you want to place your penguin on:");
    scanf("%i",&x);
    while (x > number_of_columns - 1 || x < 0) {
        printf("Wrong coordinates, please try again:");
        scanf("%i", &x);
    }

    printf("Enter y-coordinate you want to place your penguin on:");
    scanf("%i",&y);
    while (y > number_of_rows - 1 || y < 0) {
        printf("Wrong coordinates, please try again:");
        scanf("%i", &y);
    }

    struct movement m = {x, y};
    return m;
}

/*
input parameters: int number_of_columns, int number_of_rows
return: placement type
this function asks a user for a placement of a penguin and returns it.
*/
struct placement get_placement(int number_of_columns, int number_of_rows) {
    int x, y;
    printf("Enter x-coordinate you want to place your penguin on:");
    scanf("%i",&x);
    while (x > number_of_columns - 1 || x < 0)) {
        printf("Wrong coordinates, please try again:");
        scanf("%i", &x);
    }

    printf("Enter y-coordinate you want to place your penguin on:");
    scanf("%i",&y);
    while (y > number_of_rows - 1|| y < 0) {
        printf("Wrong coordinates, please try again:");
        scanf("%i", &y);
    }

    struct placement p = {x, y};
    return p;
}

//int get_difficulty_level() {
//    int level;
//    printf("Enter the level of difficulty(from 1 to 3): ");
//    scanf("%i", &level);
//
//    while (level <= 0 || level > 3) {
//        printf("Wrong level of difficulty. Please try again");
//        scanf("%i", &level);
//    }
//
//}

//int check_if_ai() {
//    printf("");
//}
