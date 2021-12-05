#include "structures.h"
#include "evaluation.h"

int determine_winner(struct player* players, int n) {
    int winner_id = 1;
    int i;
    for (i = 1; i <= n; ++i)
        if (player[winner_id - 1].fish_collected < player[i - 1].fish_collected)
            winner_id = i;

    return winner_id;
}
