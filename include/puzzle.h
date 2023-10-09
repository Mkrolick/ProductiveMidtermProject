#ifndef PUZZLE_H
#define PUZZLE_H

#include "ppm_io.h" // for Image data type

typedef struct _tile {
  *Pixel imageBlock;
  int blockSize;
} Tile;

void exportTile(Tile *t, *Image image);
*Image exportImage(Puzzle puzzle);

typedef struct _puzzle {
  Tile tiles[][]; // 2D array of tiles
  int positions[][];
} Puzzle;

Puzzle *puzzle_create(int size);

void puzzle_destroy(Puzzle *p);
void puzzle_set_tile(Puzzle *p, int col, int row, int value);
int puzzle_get_tile(const Puzzle *p, int col, int row);

#endif // PUZZLE_H
