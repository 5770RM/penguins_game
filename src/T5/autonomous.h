#ifndef AUTOFUN
#define AUTOFUN
// fucntion is run by main if game is played in autonomous mode, executes command given in command line arguments
// arguemtns: game state, number of command line arguments, command line arguemtns
// returns: no value
void execute_autonomous_command(struct GameState* state, int argc, char **argv);
#endif
