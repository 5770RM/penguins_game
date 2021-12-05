#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"
//#include "command_line_ui.c"
//#include <conio.h>
//#include "input.c"
void generate_board(struct board_tile **board, int x_size, int y_size)
{
    srand(time(0));
    for (int i = 0; i < y_size; i++) // Map generation
    {
        for (int j = 0; j < x_size; j++)
        {
            board[i][j].fishes = (rand() % 3 + 1); // random value for fish on a tile
            board[i][j].occupied = 0;
            if ((j == 0) || (j == (x_size - 1)) || (i == 0) || (i == (y_size - 1)))
            {
                board[i][j].fishes = 0; // making tiles on the perimetr ocean
            }
        }
    }
}
void show_board(struct board_tile **board, int x_size, int y_size)
{
    printf("   ");
    for (int j = 0; j < x_size; j++)
    {
        printf("%4d", j); // x counter
        if (j == x_size - 1)
        {
            printf("\n");
        }
    }
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            if ((i == 0) && (j == 0))
            {
                printf("%-4d", j); // first line, index
                printf("|%d %d", board[i][j].fishes, board[i][j].occupied);
            }
            else
            {
                printf("|%d %d", board[i][j].fishes, board[i][j].occupied);
            }
            if (j == x_size - 1)
            {
                printf("|\n");
                if (i != (y_size - 1))
                {
                    printf("%-4d", i + 1);
                }
            }
        }
    }
}
/*struct board_tile **new_board(int x, int y)
{
    struct board_tile **board = (struct board_tile **)malloc(y * sizeof(struct board_tile *));
    int i;
    for (i = 0; i < y; i++)
        board[i] = (struct board_tile *)malloc(x * sizeof(struct board_tile));

    return board;
}
int main()
{
    printf("enter: ");
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    struct board_tile **board = new_board(x, y);
    generate_board(board, x, y);
    show_board(board, x, y);
}
*/
