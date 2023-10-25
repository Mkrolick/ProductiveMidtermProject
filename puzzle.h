#ifndef PUZZLE_H
#define PUZZLE_H

#include "ppm_io.h"  // for Image data type
#include "stdio.h"

typedef struct _tile {
  Pixel *imageBlock;
  int blockSize;
} Tile;

typedef struct _puzzle {
  int size;

  Tile *tiles;  // 2D array of tiles - replacing tiles[][] with Tile ** tiles as
                // left most dimension needed to be specified
  // can debug this later if want to revert to previous format

  // needs to be pointer - cant use initializer list
  int **positions;
} Puzzle;

#endif  // PUZZLE_H
