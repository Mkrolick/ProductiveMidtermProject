// Zachary Sayyah zsayyah1
// Malcolm Krolick mkrolick1
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
  //Tile** tiles = malloc(sizeof(Tile*) * size);
  //for (int i = 0; i < size; i++) {
  //  tiles[i] = malloc(sizeof(Tile) * size);
  //}
  //
  //new_puzzle->tiles = tiles;

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

  new_puzzle->created = 0;

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
        // Free temp_tile image ptr
        free(temp_tile->imageBlock);

        
        free(p->tiles[i]);
    }
    free(p->tiles);

    // Aet the freed pointers to NULL
    p->positions = NULL;
    p->tiles = NULL;

}

void puzzle_set_tile(Puzzle *p, int col, int row, int value) {
    p->positions[row][col] = value;
    
    // Add code to move tile into a Tile opbject assigned in tiles
}

int puzzle_get_tile(const Puzzle *p, int col, int row) {
    // check if p or positions is NULL
    return p->positions[row][col];
}

Image *exportImage(Puzzle *p) {
    Image *newImage = malloc(sizeof(Image));

    assert(p->size);
    // Copying format data from original image
    newImage->rows = p->size * p->tiles->blockSize;
    newImage->cols = p->size * p->tiles->blockSize;
    newImage->data = (Pixel*) malloc(sizeof(Pixel) * newImage->rows * newImage->cols);
    
    // Verifies malloc succeeded
    assert(newImage->data);

    // TODO Actually store blocksize in puzzle object
    // as it stands this just gets the first tile
    int blocksize = p->tiles->blockSize;
    int numBlocks = blocksize / (newImage->rows * newImage->cols);

    // Now stuff gets fun
    for (int i = 0; i < numBlocks; i++) {
        for (int j = 0; j < numBlocks; j++) {
            // Gets index from positions and accesses that element
            Tile currentTile = p->tiles[p->positions[i][j]];
            
            // offset for later use to describe location within wider image
            // initialized to the top left of that block within the image
            int offset = i * blocksize + j * blocksize * newImage -> rows;

            for (int row=0; row < blocksize; row++){
                for (int k = 0; k < (blocksize); k++) {
                    newImage->data[offset + k] = currentTile.imageBlock[k];
                }
                offset += newImage->rows;
            }
        }
    }
    return newImage;
}
