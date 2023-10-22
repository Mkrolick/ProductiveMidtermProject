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

  //creating 2D array of tile pointers
  Tile** tiles = malloc(sizeof(Tile*) * size);
  for (int i = 0; i < size; i++) {
    tiles[i] = malloc(sizeof(Tile) * size);
  }

  new_puzzle->tiles = tiles;

  // creating 2D array of tile positions
  int** positions = malloc(sizeof(int*) * size);
  for (int i = 0; i < size; i++) {
    positions[i] = malloc(sizeof(int) * size);
  }

  // Assigning each value in positions to 0
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; i++) {
        positions[i][j] = 0;
    }
  }


  new_puzzle->positions = positions;

  return new_puzzle;

}

void puzzle_destroy(Puzzle *p) {

    //freeing positions
    for (int i = 0; i < (p->size); i++) {
        free(p->positions[i]);
    }
    free(p->positions);

    // freeing tiles
    for (int i = 0; i < (p->size); i++) {
        // Note: how to check if valid tile?

        Tile* temp_tile = p->tiles[i];
        // free temp_tile image ptr
        free(temp_tile->imageBlock);

        
        free(p->tiles[i]);
    }
    free(p->tiles);

    // set the freed pointers to NULL
    p->positions = NULL;
    p->tiles = NULL;

}

void puzzle_set_tile(Puzzle *p, int col, int row, int value) {
    p->positions[row][col] = value;
    
    // add code to move tile into a Tile opbject assigned in tiles
}

int puzzle_get_tile(const Puzzle *p, int col, int row) {

    // check if p or positions is NULL
    return p->positions[row][col];
}

// allows for -> syntax looks nicer
Image* exportImage(Puzzle *p) {
    p-> 
}
