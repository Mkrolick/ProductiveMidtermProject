#ifndef PUZZLE_F
#define PUZZLE_F 

#include "stdio.h"
#include "puzzle.h"


Puzzle *puzzle_create(int size);
void puzzle_destroy(Puzzle *p);
int puzzle_get_tile(const Puzzle *p, int col, int row);

void puzzle_set_tile(Puzzle *p, int col, int row, int value);

Image *exportImage(Puzzle *p);
int puzzle_solved(Puzzle* p);
int move_puzzle(Puzzle *p, char command);
int solve_puzzle(Puzzle *p, char steps[], int max_steps, int cur_steps, char prev_move);

void exportTile(Tile *t, Image *image);

void write_game(int** array, int size, FILE* file);


Puzzle* half_deep_copy_puzzle(Puzzle *p);
void destroy_copy(Puzzle *p);

#endif  // PUZZLE_H
