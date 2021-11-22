#include <stdio.h>
#include "input.c"
int input_x(int x)
{
    int position_x; //input x coord for moving
    printf("Enter x coordinate of the penguin you want to choose: ");
    scanf("%d", &position_x);
    if (position_x > 1 && position_x <= x)
    {
        return position_x;   
    }
    else
    {
        printf("invalid cooordinates\n");
        input_x(x);
    }
}
int input_y(int y) //input y coord for moving
{
    int position_y;
    printf("Enter y coordinate of the penguin you want to choose: ");
    scanf("%d", &position_y);
    if (position_y > 1 && position_y <= y)
    {
        return position_y;
    }
    else
    {
        printf("invalid cooordinates\n");
        input_y(y);
    }
}
int movement_game_status() // check if there are tiles left to go onto
{  
    //int result;

    // return result;  
}
int choosing_penguin() // read coord of a penguin, the player is going to move
{
}
int movement_possible() // check if the penguin has a tile to go onto
{
}
int valid_movement() // check if it is possible to move onto this tile
{
}
int execute_movement() // move the penguin to a tile, collect fish, remove the tile the penguin was on before
{
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
