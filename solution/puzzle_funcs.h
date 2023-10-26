#ifndef PUZZLE_F
#define PUZZLE_F 

#include "stdio.h"
#include "puzzle.h"



/* puzzle_create
 * creates and initialized a heap allocated 
 * pointer to a puzzle and assigns basic values
 */
Puzzle *puzzle_create(int size);

/* puzzle_destroy
 * given a pointer to a puzzle the function
 * frees the associated memory blocks
 */
void puzzle_destroy(Puzzle *p);

/* puzzle_get_tile
 * returns the int value of a position in a created
 * puzzle given a puzzle pointer, column and row
 */
int puzzle_get_tile(const Puzzle *p, int col, int row);

/* puzzle_set_tile
 * sets the value at a position in a created puzzle
 * given a column, row, and value
 */
void puzzle_set_tile(Puzzle *p, int col, int row, int value);


/* export_image
 * creates image object given a puzzle
 * uses tiles and positions from puzzle
 */
Image *exportImage(Puzzle *p);

/* puzzle_solved
 * returns an int value 1 (truthy) or 0 (falsy)
 * if the puzzle is in a correct arangement or not
 */
int puzzle_solved(Puzzle* p);

/* move_puzzle
 * given a puzzle pointer and a command
 * the command acts to shift the puzzles by swaping 
 * with the gap in the opposite direction than specified
 */
int move_puzzle(Puzzle *p, char command);


int solve_puzzle(Puzzle *p, char steps[], int max_steps, int cur_steps, char prev_move);

void exportTile(Tile *t, Image *image);

void write_game(int** array, int size, FILE* file);


Puzzle* half_deep_copy_puzzle(Puzzle *p);
void destroy_copy(Puzzle *p);

#endif  // PUZZLE_H
