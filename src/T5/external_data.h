#ifndef EXTFILES
#define EXTFILES
// reads content of the file given in name, returns the state of the game given in the file
// arguments: name of the file
// return: state of the game in the file 
struct GameState* read_board(char* name);
// writes a new file to location specified in name
// arguments: current game state, name of the file to write this state
// returns: no value
void write_board(struct GameState* state, char* name);
#endif
