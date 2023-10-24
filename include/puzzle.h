#ifndef PUZZLE_H
#define PUZZLE_H

#include "ppm_io.h" // for Image data type
#include "stdio.h"

typedef struct _tile {
  Pixel* imageBlock;
  int blockSize;
} Tile;

typedef struct _puzzle {
  int created;
  int size;
  
  Tile* tiles; // 2D array of tiles - replacing tiles[][] with Tile ** tiles as left most dimension needed to be specified 
  // can debug this later if want to revert to previous format 

  // needs to be pointer - cant use initializer list
  int** positions;
} Puzzle;

void exportTile(Tile *t, Image* image);

// changed type to pointer as allows for consistency
Image* exportImage(Puzzle *p);

Puzzle *puzzle_create(int size);

void puzzle_destroy(Puzzle *p);
void puzzle_set_tile(Puzzle *p, int col, int row, int value);
int puzzle_get_tile(const Puzzle *p, int col, int row);

//functions for handling input
int handle_C_command(FILE *in, Puzzle **p);
int handle_T_command(FILE *in, Puzzle *p);
int handle_I_command(FILE *in, Image **im);
int handle_P_command(Puzzle *p);
int handle_W_command(FILE* in, Image *im,Puzzle *p);
int handle_S_command(FILE *in, Puzzle *p);
int handle_K_command(Puzzle *p);
int handle_V_command(Puzzle *p);

<<<<<<< HEAD


=======
int pain(void);
int cry(void);
>>>>>>> 78f440db870f96956ee193030bf5df4c78d983c8

#endif // PUZZLE_H
