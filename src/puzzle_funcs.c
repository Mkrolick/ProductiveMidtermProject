#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "puzzle.h"

// TODO: implement functions

Puzzle* puzzle_create(int size) {

  // need to check if pointers worked or failed
  Puzzle* new_puzzle = malloc(sizeof(Puzzle));

  //creating 1D array of tile poninters
  new_puzzle->tiles = malloc(sizeof(Tile*) * size);

  // creating 2D array of tile positions
  int** positions = malloc(sizeof(int*) * size);
  for (int i = 0; i < size; i++) {
    positions[i] = malloc(sizeof(int) * size);
  }

  new_puzzle->positions = positions;

  return new_puzzle;

}