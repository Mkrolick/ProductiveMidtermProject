#ifndef PUZZLE_R
#define PUZZLE_R

#include "ppm_io.h"  // for Image data type
#include "puzzle.h"
#include "puzzle_funcs.h"

int puzzle_solved(Puzzle* p);

// functions for handling input
int handle_C_command(FILE *in, Puzzle **p, int standin);
int handle_T_command(FILE *in, Puzzle *p, int standin);
int handle_I_command(FILE *in, Image **im, int standin);
int handle_P_command(Puzzle *p);
int handle_W_command(FILE *in, Image *im, Puzzle *p, int standin);
int handle_S_command(FILE *in, Puzzle *p, int standin);
int handle_K_command(Puzzle *p);
int handle_V_command(Puzzle *p);

#endif  // PUZZLE_H
