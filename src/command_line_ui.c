#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "gameplay_functions.h"

//int main() {
//    char names_of_players[9]; //Put 9 here because it is max number of players
//    int num = get_number_of_players();
//    get_names_of_players(names_of_players, num);
//    get_x_dimension();
//    get_y_dimension();
//   return 0;
//}

int get_nbr_of_players () {
    int number_of_players;
    printf("Enter the number of players(from 1 to 9): ");
    scanf("%i", &number_of_players);
    while (number_of_players <= 1 || number_of_players >= 9) {
        printf("Wrong number of players. Please try again: ");
        scanf("%i", &number_of_players);
    }
    return number_of_players;
}

void init_players (struct player* players, int number_of_players) {
    for (int i = 0; i < number_of_players; i++) {
        //if you only ask for one char you dont need an array of chars
        char ch;
        printf("Enter the name of the %ist player(only one character): ", i + 1);
        scanf(" %c", &ch);
        while (ch < 'A' || ch > 'z') {
            printf("Invalid name, try again: ");
            scanf("%c", &ch);
        }
        players[i].name = ch;
    }
}

int get_x_dimension () {
    int x;
    printf("Enter how many columns you want in the board(from 2 to 16):");
    scanf("%i", &x);
    while (x < 2 || x > 16) {
        printf("Wrong number of columns. Please try again: ");
        scanf("%i", &x);
    }
    return x;
}

int get_y_dimension () {
    int y;
    printf("Enter how many rows you want in the board(from 2 to 16):");
    scanf("%i", &y);
    while (y < 2 || y > 16) {
        printf("Wrong number of columns. Please try again: ");
        scanf("%i", &y);
    }
    return y;
}
