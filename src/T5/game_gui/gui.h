#ifndef GUI_H
#define GUI_H

typedef enum { INPUT_PHASE, PLACEMENT_PHASE, MOVEMENT_PHASE, END_PHASE } Phase;

void init_gui(const int, const int, char *, int);
void draw_input_phase(struct board_tile ***board, int *x, int *y, struct player **players, int *n, int *curr_player, Phase *phase);
void draw_placement_phase(struct board_tile ***board, int *x, int *y, struct player **players, int *n);
void draw_movement_phase(struct board_tile ***board, int *x, int *y, struct player **players, int *n);

#endif
