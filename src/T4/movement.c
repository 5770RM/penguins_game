#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structures.h"
// #include "gameplay_functions.h"
#include "movement.h"

int movement_game_status(struct board_tile **board, struct player *players, int amount_of_players) // check if there are tiles left to go onto
{
    int status_counter = 0;
    int status = 0;
    for (int i = 0; i < amount_of_players; i++)
    {
        if (players[i].movement_status == 1)
        {
            status_counter++;
        }
    }
    if (status_counter == amount_of_players)
    {
        status = 1;
    }
    return status;
}
int movement_possible(struct board_tile **board, int x, int y, struct player *players, int n, int curr_player) // check if the player has a tile to go onto
{
    int id = players[curr_player].id;
    int result = 0;
    for (int j = 1; j < x - 1; j++)
    {
        for (int i = 1; i < y - 1; i++)
            if (board[j][i].occupied == id)
            {
                if ((board[i + 1][j].fishes != 0) || (board[i - 1][j].fishes != 0) || (board[i][j + 1].fishes != 0) || (board[i][j - 1].fishes != 0))
                {
                    result = 1;
                    players[curr_player].movement_status = 0;
                    return result;
                }
            }
    }
    return result;
}
int valid_movement(struct board_tile **board, struct movement m, int curr_player) // check if it is possible to move onto this tile
{
    int flag = 0;
    if ((m.from.x == m.to.x) || (m.from.y == m.to.y))
    {
        if (m.from.x == m.to.x)
        {
            if (m.from.x - m.to.x > 0)
            {
                for (int i = 0; i < abs(m.from.x - m.to.x); i++)
                {
                    if ((board[m.to.y-i][m.to.x].fishes == 0) || ((board[m.from.y-i][m.from.x].occupied > 0)))
                    {
                        flag = 1;
                    }
                }
            }
            else
            {
                for (int i = 0; i < abs(m.from.x - m.to.x); i++)
                {
                    if ((board[m.to.y+i][m.from.x].fishes == 0) || ((board[m.to.y+i][m.from.x].occupied > 0)))
                    {
                        flag = 1;
                    }
                }
            }
        }
        else
        {
            if (m.from.y - m.to.y > 0)
            {
                for (int i = 0; i < abs(m.from.y - m.to.y); i++)
                {
                    if ((board[m.to.y][m.to.x-i].fishes == 0) || ((board[m.to.y][m.to.x-i].occupied > 0)))
                    {
                        flag = 1;
                    }
                }
            }
            else
            {
                for (int i = 0; i < abs(m.from.y - m.to.y); i++)
                {
                    if ((board[m.to.y][m.to.x+i].fishes == 0) || ((board[m.to.y][m.to.x+1].occupied > 0)))
                    {
                        flag = 1;
                    }
                }
            }
        }
    }
    else
    {
        return flag;
    }
    return flag;
}
void execute_movement(struct board_tile **board, struct player *players, int curr_player, struct movement m) // move the penguin to a tile, collect fish, remove the tile the penguin was on before
{
    board[m.from.y][m.from.x].occupied = 0;
    board[m.to.y][m.to.x].occupied = players[curr_player].id;
    players[curr_player].fish_collected = players[curr_player].fish_collected + board[m.to.y][m.to.x].fishes;
    board[m.to.y][m.to.x].fishes = 0;
}

/* int main()
{
    int x = get_x_dimension();
    int y = get_y_dimension();
    int position_x = input_x(x);
    int position_y = input_y(y);
    // checking what is the current player
    // checking if there are any penguins left who can move
    // getting cords
    // checking if there is a current player's penguin on that tile
    // getting cords to move on
    // checking if cords are valid
    // switch players
} */
