#include "structures.h"
//#include "gameplay_functions.h"
#include "command_line_ui.h"
#include "evaluation.h"
#include "map.h"
#include "miscellaneous.h"
#include "movement.h"
#include "placement.h"
#include "defines.h"
#include <stdlib.h>
#include <stdio.h>

int main(int agrc, char **argv) {   
    //init();
    
    //int GUI = 0;
    int n = get_nbr_of_players();
    struct player* players = (struct player*)malloc(n * sizeof(struct player));

    init_players(players, n);
    int x = get_x_dimension();
    int y = get_y_dimension();
    
    //pair dims = get_board_dims();
    //int x = dims.x;
    //int y = dims.y;

    // allocate memory for board and fill with elements using generate_board
    struct board_tile** board = new_board(x, y);
    // board has ocean tiles on all of its borders
    generate_board(board, x, y);
    // show_board(board, x, y);
    
    // in the movement phase we might want to choose ones again the first player to make a move
    int curr_player = choose_first_player(n);
    
    /*
        PLACEMENT PHASE
    */
    placement_init();
    // as long as at least one player can place one of their penguins
    while (placement_game_status(board, x, y, players, n) != END_PP) {
        // check if current player can place a penguin
        if (placement_possible(board, x, y, players, curr_player) == TRUE) {
            // until chosen placement is invalid ask for a new one
            int valid;
            struct placement p;
            display_curr_player(players, curr_player);
            do {
                show_board(board, x, y);
                p = get_placement(x, y);
                valid = valid_placement(board, x, y, p);
                if  (!valid) print_invalid_placement();
            } while (valid == FALSE);
            execute_placement(board, players, curr_player, p);
        }
        next_player(&curr_player, n);
    }
   
    /*
        MOVEMENT PHASE
    */
    movement_init(board, x, y, players, n);
    // as long as at least one player can make a move 
    while (movement_game_status(board, players, n) != END_MP) {
        // check if currnet player can make a move        
        if (movement_possible(board, x, y, players, curr_player) == TRUE) {
            // unitl chosen move is invalid ask for another            
            int valid;
            struct movement m;
            display_curr_player(players, curr_player);
            do {
                show_board(board, x, y);
                m = get_movement(x, y);
                valid = valid_movement(board, players, m, curr_player);
                if (!valid) print_invalid_movement();
            } while (valid == FALSE);
            execute_movement(board, players, curr_player, m);
        }
        next_player(&curr_player, n);
    }
    
    int winner = determine_winner(players, n);
    end_game();

    free_board(board, x, y);
    
    return 0;      
}
