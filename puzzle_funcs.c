// Zachary Sayyah zsayyah1
// Malcolm Krolick mkrolick1
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "puzzle.h"
#include "puzzle_funcs.h"
#include "read_utils.h"

// TODO: implement functions

Puzzle *puzzle_create(int size) {
  // need to check if pointers worked or failed
  Puzzle *new_puzzle = malloc(sizeof(Puzzle));

  Tile* tiles = malloc(sizeof(Tile) * size * size);

  // creating 2D array of tile positions
  int **positions = malloc(sizeof(int *) * size);
  for (int i = 0; i < size; i++) {
    positions[i] = malloc(sizeof(int) * size);
  }

  // Assigning each value in positions to 0
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      positions[i][j] = 0;
    }
  }

  // assigns each to the new puzzle
  new_puzzle->tiles = tiles;
  new_puzzle->positions = positions;
  new_puzzle->size = size;

  return new_puzzle;
}

void puzzle_destroy(Puzzle *p) {
  // freeing positions
  if (p) {
    for (int i = 0; i < p->size; i++) {
      free(p->positions[i]);
    }
    
    free(p->positions);

    // frees tiles
    assert(0);
    if (p->tiles) {
      for (int i = 0; i < ((p->size) * (p->size)); i++) {
        if (p->tiles[i].imageBlock) {
          free(p->tiles[i].imageBlock);
        }
      }   
    }
    

    free(p->tiles);
  
  // finally frees puzzle
  }

  free(p);
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
  newImage->data =
      (Pixel *) malloc(sizeof(Pixel) * newImage->rows * newImage->cols);

  // Verifies malloc succeeded
  assert(newImage->data);

  // TODO Actually store blocksize in puzzle object
  // as it stands this just gets the first tile
  int blocksize = p->tiles->blockSize;
  int numBlocks = p->size;

  // Now stuff gets fun
  for (int i = 0; i < numBlocks; i++) {
    for (int j = 0; j < numBlocks; j++) {
      // Gets index from positions and accesses that element
      Tile currentTile = p->tiles[p->positions[j][i]];

      // offset for later use to describe location within wider image
      // initialized to the top left of that block within the image
      int offset = i * blocksize + j * blocksize * newImage->rows;

      for (int row = 0; row < blocksize; row++) {
        for (int k = 0; k < (blocksize); k++) {
          newImage->data[offset + k] = currentTile.imageBlock[k + row * blocksize];
        }
        offset += newImage->rows;
      }
    }
  }

  return newImage;
}

int puzzle_solved(Puzzle* p) {
  // set correct as true
  int correct = 1;

  //if puzzle_get_tile !=  correct val and puzzle_get_tile != 0
  //set correct to false
  for (int row = 0; row < (p->size); row++) {
    for (int col = 0; col < (p->size); col++) {
      int tile_val = puzzle_get_tile(p, col, row);
      int correct_val = 1 + col + row * (p->size);

      if (tile_val != 0) {
        if (correct_val != tile_val) {
          correct = 0;
        } 
      }      
    }
  }

  //return truth value
  return correct;
}

// Parameters:
//   p - a Puzzle
//   steps - array of directions (u/d/l/r)
//   max_steps - maximum number of steps to try
//   cur_steps - how many steps have been considered so far


int move_puzzle(Puzzle *p, char command) {

  int temp_int;
  int tile_found = 0;
  int found_col;
  int found_row;

  switch (command) {
    case 'u':

      for (int row = 0; row < ((p->size) - 1); row++) {
        for (int col = 0; col < (p->size); col++) {
          if (puzzle_get_tile(p, col, row) == 0) {
            found_col = col;
            found_row = row;
            tile_found = 1;
          }
        }
      }

      if (!tile_found) {
        return 2;
      }

      temp_int = puzzle_get_tile(p, found_col, found_row + 1);

      puzzle_set_tile(p, found_col, found_row + 1, 0);

      puzzle_set_tile(p, found_col, found_row, temp_int);

      break;

    case 'd':
      
      for (int row = 1; row < (p->size); row++) {
        for (int col = 0; col < (p->size); col++) {
          if (puzzle_get_tile(p, col, row) == 0) {
            found_col = col;
            found_row = row;
            tile_found = 1;
          }
        }
      }

      if (!tile_found) {
        
        return 2;
      }
      

      temp_int = puzzle_get_tile(p, found_col, found_row - 1);
      
      puzzle_set_tile(p, found_col, found_row - 1, 0);
      
      puzzle_set_tile(p, found_col, found_row, temp_int);
      
      break;

    case 'l':

      // NEed to UPDATE YAY

      for (int row = 0; row < (p->size); row++) {
        for (int col = 0; col < ((p->size) - 1); col++) {
          if (puzzle_get_tile(p, col, row) == 0) {
            found_col = col;
            found_row = row;
            tile_found = 1;
          }
        }
      }

      if (!tile_found) {
        
        return 2;
      }
      
      
      
      temp_int = puzzle_get_tile(p, found_col + 1, found_row);

      puzzle_set_tile(p, found_col + 1, found_row, 0);
      
      puzzle_set_tile(p, found_col, found_row, temp_int);

      break;

    case 'r':

      // UPdate YAY
      for (int row = 0; row < (p->size); row++) {
        for (int col = 1; col < (p->size); col++) {
          if (puzzle_get_tile(p, col, row) == 0) {
            found_col = col;
            found_row = row;
            tile_found = 1;
          }
        }
      }

      if (!tile_found) {
        
        return 2;
      }

      temp_int = puzzle_get_tile(p, found_col - 1, found_row);

      puzzle_set_tile(p, found_col - 1, found_row, 0);
      
      puzzle_set_tile(p, found_col, found_row, temp_int);

      break;
    default:

      
      return 3;
      break;
  }

  return 0;
}


int solve_puzzle(Puzzle *p, char steps[], int max_steps, int cur_steps, char prev_move) {

  //printf("%d\n", cur_steps);
  if (puzzle_solved(p)) {
    steps[cur_steps] = '\0';
    //printf("reached\n");
    return cur_steps; // steps array has a complete sequence of steps
  }

  if (cur_steps >= max_steps) {
    return max_steps; // we reached the max number of steps
  }

  char direction[] = {'u', 'd', 'l', 'r' };

  char no_go;


  switch (prev_move)
  {
  case 'u':
    no_go = 'd';
    break;
  case 'd':
    no_go = 'u';
    break;
  case 'l':
    no_go = 'r';
    break;
  case 'r':
    no_go = 'l';
    break;
  default:
    no_go = '\0';
  }
  


  for (int i = 0; i < 4; i++) {
    if (direction[i] == no_go) {
      continue;
    }
    



    Puzzle* p_copy = malloc(sizeof(Puzzle));
    p_copy = half_deep_copy_puzzle(p);

    if (move_puzzle(p_copy, direction[i]) == 0) {
      int totalsteps = solve_puzzle(p_copy, steps, max_steps, cur_steps + 1, direction[i]);
      if (totalsteps != max_steps) {
        // found a solution recursively!
        steps[cur_steps] = direction[i];
        destroy_copy(p_copy);
        //printf("%d, %d, %d", totalsteps, cur_steps, max_steps);
        
        return totalsteps;
      } 
    } 
  }

  return max_steps; // attempts to solve recursively did not succeed
}

void destroy_copy(Puzzle *p) {

  
  // freeing positions
  for (int i = 0; i < p->size; i++) {
    free(p->positions[i]);
  }

  free(p->positions);
}



Puzzle* half_deep_copy_puzzle(Puzzle *p) {
  Puzzle* new_puzzle = puzzle_create(p->size);

  const int size = p->size;
  // copies positions
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      new_puzzle->positions[i][j] = p->positions[i][j];
    }
  }

  // shallow copy of tiles copies tiles - save memory and time
  new_puzzle->tiles = NULL;

  new_puzzle->size = size;
  

  return new_puzzle;

}




void write_game(int** array, int size, FILE* file) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      fprintf(file, "%d ", array[i][j]);
    }
  }
  fprintf(file, "\n");
}

