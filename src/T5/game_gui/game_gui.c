#include "../structures.h"
#include "../command_line_ui.h"
#include "../evaluation.h"
#include "../map.h"
#include "../miscellaneous.h"
#include "../movement.h"
#include "../placement.h"
#include "../bots.h"
#include "../defines.h"
#include "../external_data.h"
#include "../autonomous.h"
#include <stdlib.h>
#include <stdio.h>
#include <queue.h>
#include <vector.h>
#include "raylib.h"
#include <assert.h>

#define RAYGUI_IMPLEMENTATION
//#define RAYGUI_CUSTOM_ICONS     // It requires providing gui_icons.h in the same directory
//#include "gui_icons.h"          // External icons data provided, it can be generated with rGuiIcons tool
#include "raygui.h"

#include <string.h>             // Required for: strcpy()

#include "gui.h"
void draw_map(RectangleElem *map) {
    DrawRectangle(map->x, map->y, map->width, map->height, map->color);
}

void draw_console(RectangleElem *console) {
    DrawRectangle(console->x, console->y, console->width, console->height, console->color);
};
   
void draw_title(TextElem *title) {
    DrawText(title->value, title->x, title->y, title->fontSize, title->fontColor);
} 

void draw_spinner_players(SpinnerElem *spinner) {
    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_CENTER);
    GuiSetStyle(TEXTBOX, COLOR_SELECTED_FG, 0xffffffff);
    GuiSetStyle(TEXTBOX, COLOR_SELECTED_BG, 0xffffffff);
    GuiSetStyle(DEFAULT, BACKGROUND_COLOR, 0xffffffff);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);     
    
    if (GuiSpinner((Rectangle){ spinner->rect.x, spinner->rect.y, spinner->rect.width, spinner->rect.height }, 
                    NULL, 
                    &(spinner->value), 
                    spinner->rMin, 
                    spinner->rMax, 
                    spinner->editMode)) spinner->editMode ^= 1;
}

void draw_text1(TextElem *text) {
    DrawText(text->value, text->x, text->y, text->fontSize, text->fontColor);
}

void draw_text2(TextElem *text) {
    DrawText(text->value, text->x, text->y, text->fontSize, text->fontColor);
}

void draw_spinner_penguins(SpinnerElem *spinner) {
    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_CENTER);
    GuiSetStyle(TEXTBOX, COLOR_SELECTED_FG, 0xffffffff);
    GuiSetStyle(TEXTBOX, COLOR_SELECTED_BG, 0xffffffff);
    GuiSetStyle(DEFAULT, BACKGROUND_COLOR, 0xffffffff);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);     
    if (GuiSpinner((Rectangle){ spinner->rect.x, spinner->rect.y, spinner->rect.width, spinner->rect.height }, 
                    NULL, 
                    &(spinner->value), 
                    spinner->rMin, 
                    spinner->rMax, 
                    spinner->editMode)) spinner->editMode ^= 1;
}

void draw_players_title(TextElem *text) {
    DrawText(text->value, text->x, text->y, text->fontSize, text->fontColor);
}

void draw_player(TextBoxElem *player) {
    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_LEFT);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);    
    char s[64]; 
    strcpy(s, player->text);
    if (GuiTextBox((Rectangle){ player->rect.x, player->rect.y, player->rect.width, player->rect.height}, 
                                (player->editMode) ? s : player->placeHolder, 
                                64,
                                player->editMode)) player->editMode ^= 1;
}

void draw_text3(TextElem *text) {
    DrawText(text->value, text->x, text->y, text->fontSize, text->fontColor);
}

void draw_spinner_xdim(SpinnerElem *spinner) {
    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_CENTER);
    GuiSetStyle(TEXTBOX, COLOR_SELECTED_FG, 0xffffffff);
    GuiSetStyle(TEXTBOX, COLOR_SELECTED_BG, 0xffffffff);
    GuiSetStyle(DEFAULT, BACKGROUND_COLOR, 0xffffffff);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);     
     
    if (GuiSpinner((Rectangle){ spinner->rect.x, spinner->rect.y, spinner->rect.width, spinner->rect.height }, 
                    NULL, 
                    &(spinner->value), 
                    spinner->rMin, 
                    spinner->rMax, 
                    spinner->editMode)) spinner->editMode ^= 1;
}

void draw_text4(TextElem *text) {
    DrawText(text->value, text->x, text->y, text->fontSize, text->fontColor);
}

void draw_spinner_ydim(SpinnerElem *spinner) {
    GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_CENTER);
    GuiSetStyle(TEXTBOX, COLOR_SELECTED_FG, 0xffffffff);
    GuiSetStyle(TEXTBOX, COLOR_SELECTED_BG, 0xffffffff);
    GuiSetStyle(DEFAULT, BACKGROUND_COLOR, 0xffffffff);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);     
    if (GuiSpinner((Rectangle){ spinner->rect.x, spinner->rect.y, spinner->rect.width, spinner->rect.height }, 
                    NULL, 
                    &(spinner->value), 
                    spinner->rMin, 
                    spinner->rMax, 
                    spinner->editMode)) spinner->editMode ^= 1;
}

void draw_play_button(ButtonElem *button) {
    GuiSetState(GUI_STATE_NORMAL);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 30);     
    button->clicked = GuiButton(button->rect, button->text);
}

void draw_turn(TextElem *text) {
    DrawText(text->value, text->x, text->y, text->fontSize, text->fontColor);
}

void draw_player_position(TextElem *text) {
    DrawText(text->value, text->x, text->y, text->fontSize, text->fontColor);
}

void init_input_phase(GuiContainer *gui) {
    int phase = 0;
    RectangleElem *map = RectangleElem_create(0, 0, 800, 800, SKYBLUE);
    vector_push(gui->elems, GuiElem_create('r', 1, phase, map, draw_map, RectangleElem_destroy));
    
    RectangleElem *console = RectangleElem_create(800, 0, 400, 800, WHITE);
    vector_push(gui->elems, GuiElem_create('r', 2, phase, console, draw_console, RectangleElem_destroy));
    
        TextElem *title = TextElem_create("Game setup", 820, 20, 30, DARKPURPLE);
        vector_push(gui->elems, GuiElem_create('t', 1, phase, title, draw_title, TextElem_destroy));
    
        TextElem *text1 = TextElem_create("Number of players", 820, 60, 15, DARKPURPLE);
        vector_push(gui->elems, GuiElem_create('t', 2, phase, text1, draw_text1, TextElem_destroy));
        
        SpinnerElem *spinner_players = SpinnerElem_create((Rectangle){820, 80, 170, 30}, NULL, 1, 1, 9, false);
        vector_push(gui->elems, GuiElem_create('s', 1, phase, spinner_players, draw_spinner_players, SpinnerElem_destroy));
 
        TextElem *text2 = TextElem_create("Number of penguins", 1010, 60, 15, DARKPURPLE);
        vector_push(gui->elems, GuiElem_create('t', 3, phase, text2, draw_text2, TextElem_destroy));

        SpinnerElem *spinner_penguins = SpinnerElem_create((Rectangle){1010, 80, 170, 30}, NULL, 1, 1, 9, false);
        vector_push(gui->elems, GuiElem_create('s', 3, phase, spinner_penguins, draw_spinner_penguins, SpinnerElem_destroy));

        TextElem *players_title = TextElem_create("List of players", 820, 150, 20, DARKPURPLE);
        vector_push(gui->elems, GuiElem_create('t', 4, phase, players_title, draw_players_title, TextElem_destroy));

        int x = 820, y = 175, width = 125, height = 40;
        int dy = 50;
        // first column
        for (int i=0; i<9; i+=2) {
            TextBoxElem *player = TextBoxElem_create((Rectangle){x, y+i/2*dy, width, height}, false, "", "Type name");
            vector_push(gui->elems, GuiElem_create('b', i, phase, player, draw_player, TextBoxElem_destroy));
        }
        x = 1010;
        // second column
        for (int i=1; i<9; i+=2) {
            TextBoxElem *player = TextBoxElem_create((Rectangle){x, y+i/2*dy, width, height}, false, "", "Type name");
            vector_push(gui->elems, GuiElem_create('b', i, phase, player, draw_player, TextBoxElem_destroy));
        }
        
        TextElem *text3 = TextElem_create("Board x-dim", 820, 450, 15, DARKPURPLE);
        vector_push(gui->elems, GuiElem_create('t', 5, phase, text3, draw_text3, TextElem_destroy));
    
        SpinnerElem *spinner_xdim = SpinnerElem_create((Rectangle){820, 470, 170, 30}, NULL, 5, 5, 16, false);
        vector_push(gui->elems, GuiElem_create('s', 4, phase, spinner_xdim, draw_spinner_xdim, SpinnerElem_destroy));

        TextElem *text4 = TextElem_create("Board y-dim", 1010, 450, 15, DARKPURPLE);
        vector_push(gui->elems, GuiElem_create('t', 6, phase, text4, draw_text4, TextElem_destroy));
    
        SpinnerElem *spinner_ydim = SpinnerElem_create((Rectangle){1010, 470, 170, 30}, NULL, 5, 5, 16, false);
        vector_push(gui->elems, GuiElem_create('s', 5, phase, spinner_ydim, draw_spinner_ydim, SpinnerElem_destroy));

        ButtonElem *play_button = ButtonElem_create((Rectangle){ 820, 680, 360, 100}, "PLAY", 0);
        vector_push(gui->elems, GuiElem_create('x', 1, phase, play_button, draw_play_button, ButtonElem_destroy));
}

void init_placement_phase(GuiContainer *gui) {
    int phase = 1;
    RectangleElem *map = RectangleElem_create(0, 0, 800, 800, SKYBLUE);
    vector_push(gui->elems, GuiElem_create('r', 11, phase, map, draw_map, RectangleElem_destroy));
    
    RectangleElem *console = RectangleElem_create(800, 0, 400, 800, WHITE);
    vector_push(gui->elems, GuiElem_create('r', 12, phase, console, draw_console, RectangleElem_destroy));
    
        TextElem *turn = TextElem_create("TURN: ", 820, 20, 30, DARKPURPLE);
        vector_push(gui->elems, GuiElem_create('t', 11, phase, turn, draw_turn, TextElem_destroy));
    
        TextElem *rankking = TextElem_create("Ranking", 820, 80, 25, DARKPURPLE);
        vector_push(gui->elems, GuiElem_create('t', 12, phase, ranking, draw_ranking, TextElem_destroy));
        
        // draw positions of the players in the ranking
        int x = 820, y = 110;
        int dy = 50;
        // first column
        for (int i=0; i<9; ++i) {
            TexElem *player = TextElem_create("", x, y + i*dy, 20, DARKPURPLE);
            vector_push(gui->elems, GuiElem_create('b', 10+i, phase, player, draw_player_position, TextElem_destroy));
        }
}

void *new_players(struct player *players, int n) {
    return realloc(players, sizeof(struct player)*n);
}


void draw_tiles(struct board_tile **board, int x, int y, struct player *players, int n) {
    int tx = (int)(800. / (float)x);
    int ty = (int)(800.0 / (float)y);
    tx = (tx < ty) ? tx : ty;
    ty = tx;
    int padding = ty / 8.0;
    int tw = tx - padding;
    int th = ty - padding;
    for (int i=0; i<y; ++i) {
        for (int j=0; j<x; ++j) {
            DrawRectangle(j * tx + padding, i * ty + padding, tw, th, (board[i][j].fishes>0)? WHITE : SKYBLUE);
            char s[2];
            sprintf(s, "%d", board[i][j].fishes);
            if (board[i][j].fishes)
                DrawText(s, j*tx + padding + tw/4.0, i*ty + padding + th/4.0, tw/1.5, BLACK);
        }
    }
}

void init_draw(GuiContainer *gui, struct board_tile ***board, int *x, int *y, struct player **players, int *n, int *phase) {
    int size = vector_size(gui->elems); // number of GUI elements 
    // interat through every GUI element and display it if necessary
    for (int i=0; i<size; ++i) {
        GuiElem elem;
        vector_at_n(gui->elems, &elem, i);
        int new_n, new_x, new_y, pengs;
                 
        if (elem.type == 's' && elem.id == 1) { 
            new_n = ((SpinnerElem *)elem.elem)->value;
                
            if (new_n != *n) {
                *n = new_n;
                *players = new_players(*players, *n);
            }
        }
        if (elem.type == 's' && elem.id == 2) {
            pengs = ((SpinnerElem *)elem.elem)->value;
        }
        if (elem.type == 's' && elem.id == 4) {
            new_x = ((SpinnerElem *)elem.elem)->value;
            
            if (new_x != *x) {
                free_board(*board, *x, *y);
                *x = new_x;
                *board = new_board(*x, *y);
                generate_board(*board, *x, *y);
            }
        } 
        else if (elem.type == 's' && elem.id == 5) { 
            new_y = ((SpinnerElem *)elem.elem)->value;
            
            if (new_y != *y) {
                free_board(*board, *x, *y);
                *y = new_y;
                *board = new_board(*x, *y);
                generate_board(*board, *x, *y);
            } 
        }
        if (elem.type == 'b' && elem.id+1 > *n)
            continue;
        if (elem.type == 'x' && elem.id == 1 && ((ButtonElem *)elem.elem)->clicked == 1) {
            // copy values from spinners
            for (int j=0; j<*n; ++j) {
                players[j]->id = j+1;
                players[j]->name = 'a' + j;
                players[j]->fish_collected = 0;
                players[j]->penguins = pengs;
                players[j]->pen_not_placed = pengs;
                players[j]->bot = 0;
                players[j]->bot_level = 0;
            }
            init_placement_phase(gui); 
            *phase = 1;
        }
        elem.draw(elem.elem);
    }
    draw_tiles(*board, *x, *y, *players, *n);
}

coordinate get_position_from(struct board_tile **board, int x, int y, struct player *players, int n) {
    coordinate pos = 
    int tx = (int)(800. / (float)x);
    int ty = (int)(800.0 / (float)y);
    tx = (tx < ty) ? tx : ty;
    ty = tx;
    int padding = ty / 8.0;
    int tw = tx - padding;
    int th = ty - padding;
    for (int i=0; i<y; ++i) {
        for (int j=0; j<x; ++j) {
            if (CheckCollisionPointRec(GetMousePosition(), (Rectangle){j * tx + padding, i * ty + padding, tw, th}) {
                if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) 
            }
            DrawRectangle(j * tx + padding, i * ty + padding, tw, th, (board[i][j].fishes>0)? WHITE : SKYBLUE);
            char s[2];
            sprintf(s, "%d", board[i][j].fishes);
            if (board[i][j].fishes)
                DrawText(s, j*tx + padding + tw/4.0, i*ty + padding + th/4.0, tw/1.5, BLACK);
        }
    }
}

typedef enum { INPUT_PHASE, PLACEMENT_PHASE, MOVEMENT_PHASE, END_PHASE } Phase;

int main(int agrc, char **argv) {   
#if INTERACTIVE_MODE
    int n = 1;                                          // number of players
    struct player* players = new_players(players, n);   // array of players
    int x = 5, y = 5;                                   // x and y size of the map          
    struct board_tile** board = new_board(x, y);        // board stores a pointer to a 2D array
    generate_board(board, x, y);                        // map is fill with values
   
    // set parameters for the game window 
    const int screenWidth = 1200;
    const int screenHeight = 800;
    int frameRate = 60;
    // initiazlize the window
    init_gui(screenWidth, screenHeight, "Game", frameRate);
    
    bool exitWindow = false;

    Phase phase = INPUT_PHASE;

    // as long as the window should stay 
    while (!exitWindow) {
        exitWindow = WindowShouldClose();
        
        BeginDrawing();
            if (phase == INPUT_PHASE) {
                draw_input_phase(&board, &x, &y, &players, &n, &phase);
            }   
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
            if (phase == 0)
                init_draw(gui, &board, &x, &y, &players, &n, &phase); 
            if (phase == 1) {
                                
            }
                

        EndDrawing();
    }   
           
    CloseWindow();        // Close window and OpenGL context
     
#endif
   
    return 0;      
}
