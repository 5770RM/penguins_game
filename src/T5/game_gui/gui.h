#ifndef GUI_H
#define GUI_H

typedef enum { INPUT_PHASE, PLACEMENT_PHASE, MOVEMENT_PHASE, END_PHASE } Phase;


void init_gui(const int, const int, char *, int);
void draw_input_phase(struct board_tile ***board, int *x, int *y, struct player **players, int *n, int *curr_player, Phase *phase);

struct placement get_placement(struct board_tile **board, int x, int y);
void draw_console(struct player *players, int n, int curr_player, char *title);
void draw_movement_phase(struct board_tile ***board, int *x, int *y, struct player **players, int *n);

#endif
