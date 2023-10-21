#ifndef PUZZLE_H
#define PUZZLE_H

#include "ppm_io.h" // for Image data type
#include "stdio.h"

typedef struct _tile {
  Pixel* imageBlock;
  int blockSize;
} Tile;

typedef struct _puzzle {
  Tile** tiles; // 2D array of tiles - replacing tiles[][] with Tile ** tiles as left most dimension needed to be specified 
  // can debug this later if want to revert to previous format 
  int positions[][];
} Puzzle;

void exportTile(Tile *t, Image* image);
Image* exportImage(Puzzle puzzle);

Puzzle *puzzle_create(int size);

void puzzle_destroy(Puzzle *p);
void puzzle_set_tile(Puzzle *p, int col, int row, int value);
int puzzle_get_tile(const Puzzle *p, int col, int row);

#endif // PUZZLE_H
