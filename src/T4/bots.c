#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"
int bot_possible_placement(struct board_tile **board, struct player *players, int x_size, int y_size)
{
    srand(time(0));
    struct bot_placement *placements = (struct bot_placement *)malloc(x_size * y_size * sizeof(struct bot_placement));
    int place_counter = 0;
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            if (board[i][j].fishes == 1)
            {
                placements[place_counter].x = j;
                placements[place_counter].y = i;
                place_counter++;
            }
        }
    }
    return place_counter;
}
void bot1_placement_execution(struct board_tile **board, struct player *players, struct bot_placement *placements, struct placement p, int curr_player, int place_counter)
{
    int placement_decision = (rand() % (place_counter + 1));
    p.to.x = placements[placement_decision].x;
    p.to.y = placements[placement_decision].y;
    board[p.to.x][p.to.y].occupied = players[curr_player].id; // show player's id on the board
    players[curr_player].pen_not_placed--;                    // reduce number of penguins of current player after every successful placement
    players[curr_player].fish_collected++;
}
int bot1_choosing_penguin(struct board_tile **board, struct player *players, int x_size, int y_size, int curr_player)
{
    struct bot_choosing *choice = (struct bot_choosing *)malloc(x_size * y_size * sizeof(struct bot_choosing));
    int choosing_counter = 0;
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            if (board[i][j].occupied == players[curr_player].id)
            {
                choice[choosing_counter].x = j;
                choice[choosing_counter].y = i;
                choosing_counter++;
            }
        }
    }
    int penguin_decision = (rand() % (choosing_counter + 1));
    return penguin_decision;
}
void bot1_choosing_execution(struct board_tile **board, struct player *players, struct bot_choosing *choice, struct movement m, int curr_player, int choosing_counter)
{
    int penguin_decision = (rand() % (choosing_counter + 1));
    m.from.x = choice[penguin_decision].x;
    m.from.y = choice[penguin_decision].y;
}
int bot1_choosing_movement(struct board_tile **board, struct player *players, struct movement m, int x_size, int y_size, int curr_player)
{
    int movement_counter = 0;
    int up = 0;
    int down = 0;
    int right = 0;
    int left = 0;
    struct bot_movement *mov_choice = (struct bot_movement *)malloc(x_size * y_size * sizeof(struct bot_movement));
    while ((board[m.from.y + up][m.from.x].fishes != 0) && (board[m.from.y + up][m.from.x].occupied == 0))
    {
        mov_choice[movement_counter].x = (m.from.x);
        mov_choice[movement_counter].y = (m.from.y + up);
        up++;
        movement_counter++;
    }
    while ((board[m.from.y - down][m.from.x].fishes != 0) && (board[m.from.y - down][m.from.x].occupied == 0))
    {
        mov_choice[movement_counter].x = (m.from.x);
        mov_choice[movement_counter].y = (m.from.y - down);
        down++;
        movement_counter++;
    }
    while ((board[m.from.y][m.from.x + right].fishes != 0) && (board[m.from.y][m.from.x + right].occupied == 0))
    {
        mov_choice[movement_counter].x = (m.from.x + right);
        mov_choice[movement_counter].y = (m.from.y);
        right++;
        movement_counter++;
    }
    while ((board[m.from.y][m.from.x - left].fishes != 0) && (board[m.from.y][m.from.x - left].occupied == 0))
    {
        mov_choice[movement_counter].x = (m.from.x - left);
        mov_choice[movement_counter].y = (m.from.y);
        left++;
        movement_counter++;
    }
    int movement_decision = (rand() % (movement_counter + 1));
    return movement_decision;
}
void bot_mov_choosing_execution(struct board_tile **board, struct player *players, struct bot_movement *mov_choice, struct movement m, int curr_player, int movement_decision)
{
    m.to.x = mov_choice[movement_decision].x;
    m.to.y = mov_choice[movement_decision].y;
}
