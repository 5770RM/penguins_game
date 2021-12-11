#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"
#include "movement.h"
#include "placement.h"
// Bot level 1
int bot_possible_placement(struct board_tile **board, struct player *players, struct bot_placement *placements, int x_size, int y_size)
{
    srand(time(0));
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
    int placement_decision = (rand() % (place_counter));
    return placement_decision;
}
void bot1_placement_execution(struct board_tile **board, struct player *players, struct bot_placement *placements, struct placement p, int curr_player, int placement_decision)
{
    p.to.x = placements[placement_decision].x;
    p.to.y = placements[placement_decision].y;
    board[p.to.y][p.to.x].occupied = players[curr_player - 1].id;
    players[curr_player - 1].fish_collected++; // show player's id on the board
    players[curr_player - 1].pen_not_placed--; // reduce number of penguins of current player after every successful placement
    board[p.to.y][p.to.x].fishes = 0;
}
int bot1_choosing_penguin(struct board_tile **board, struct player *players, struct bot_choosing *choice, int x_size, int y_size, int curr_player)
{
    srand(time(0));
    int choosing_counter = 0;
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            if (board[i][j].occupied == players[curr_player - 1].id) // CHANGE LINES BELOW
            {
                if (((board[i + 1][j].fishes != 0) && ((board[i + 1][j].occupied == 0))) || ((board[i - 1][j].fishes != 0) && (board[i - 1][j].occupied == 0)) || ((board[i][j + 1].fishes != 0) && (board[i][j + 1].occupied == 0)) || ((board[i][j - 1].fishes != 0) && (board[i][j - 1].occupied == 0)))
                {
                    choice[choosing_counter].x = j;
                    choice[choosing_counter].y = i;
                    choosing_counter++;
                }
            }
        }
    }
    int penguin_decision = (rand() % (choosing_counter));
    return penguin_decision;
}
struct movement bot1_choosing_execution(struct board_tile **board, struct player *players, struct bot_choosing *choice, struct movement m, int curr_player, int penguin_decision)
{
    m.from.x = choice[penguin_decision].x;
    m.from.y = choice[penguin_decision].y;
    return m;
}
int bot1_choosing_movement(struct board_tile **board, struct player *players, struct movement m, struct bot_movement *mov_choice, int x_size, int y_size, int curr_player)
{
    srand(time(0));
    int movement_counter = 0;
    int up = 1;
    int down = 1;
    int right = 1;
    int left = 1;

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
    int movement_decision = (rand() % (movement_counter));
    return movement_decision;
}
struct movement bot_mov_choosing_execution(struct board_tile **board, struct player *players, struct bot_movement *mov_choice, struct movement m, int curr_player, int movement_decision)
{

    m.to.x = mov_choice[movement_decision].x;
    m.to.y = mov_choice[movement_decision].y;
    return m;
}
// bot level 2

/*
 * BOT GENERAL FUNCTIONS
 */
void execute_placement_bot(struct board_tile** board, int x, int y, struct player* players, int n, int curr_player) {
    struct placement p;
    struct bot_placement *placements = (struct bot_placement *)malloc(x * y * sizeof(struct bot_placement));
    int placement_decision = bot_possible_placement(board, players, placements, x, y);
    bot1_placement_execution(board, players, placements, p, curr_player, placement_decision);
    
    // free the memory
    free(placements);
}

void execute_movement_bot(struct board_tile** board, int x, int y, struct player* players, int n, int curr_player) {
    struct movement m;
    struct bot_choosing *choice = (struct bot_choosing *)malloc(x * y * sizeof(struct bot_choosing));
    struct bot_movement *mov_choice = (struct bot_movement *)malloc(x * y * sizeof(struct bot_movement));
    int penguin_decision = bot1_choosing_penguin(board, players, choice, x, y, curr_player);
    m = bot1_choosing_execution(board, players, choice, m, curr_player, penguin_decision);
    int movement_deicision = bot1_choosing_movement(board, players, m, mov_choice, x, y, curr_player);
    m = bot_mov_choosing_execution(board, players, mov_choice, m, curr_player, movement_deicision);
    execute_movement(board, players, curr_player, m); 
    
    // free the memory
    free(choice);
    free(mov_choice);
}
