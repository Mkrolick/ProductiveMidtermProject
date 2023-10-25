#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ppm_io.h"
#include "puzzle.h"

int handle_C_command(FILE *in, Puzzle **p, int standin) {
  // differences in return are to help in debugging
  int size = 0;
  
  // checking if from file or stdin
  if (!(standin)) {
    // Checking if size is read in properly
    if ((fscanf(in, " %d", &size) != 1)) {
      fprintf(stderr, "Invalid input\n");
      return 1;
    }
  } else {
    // Checking if size is read in properly
    if ((scanf(" %d", &size) != 1)) {
      fprintf(stderr, "Invalid input\n");
      return 1;
    }
  }

  
  // Checking if size is out of bounds
  if (size < 2 || size > 20) {
    fprintf(stderr, "Invalid puzzle size\n");
    return 2;
  }

  // Assume pointer is valid - as no error code
  // check if another error with invalid dimension sizes exist - IE 4 by 4 image
  // 3 section splices.

  Puzzle* c = malloc(sizeof(Puzzle*));

  c = puzzle_create(size);

  p = &c;

  return 0;
}

int handle_T_command(FILE *in, Puzzle *p, int standin) {
  if (!p) {
    fprintf(stderr, "No puzzle\n");
    return 1;
  }

  int size = p->size;

  int *temp_arr = malloc(sizeof(int) * size * size);

  // seting up empty array to compare values from
  for (int i = 0; i < size * size; i++) {
    *(temp_arr + i) = 0;
  }

  int temp;

  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      // checks if it's coming from standard in, this relies on short circuit to prevent unintended behavior
      if (!(standin) && fscanf(in, " %d", &temp) == 1 || standin && scanf(" %d", &temp)) {
        // calculates the address in memory for the temp_arr where val is
        // present pointer is not acessed unless temp is valid
        int *current_pointer = temp_arr + (size * (temp / size)) + temp % size;  

        if (temp > 15 || temp < 0) {
          // is that invalid input or invalid tile value
          fprintf(stderr, "Invalid tile value\n");
          return 2;
        } else if (*current_pointer == 0) {
          puzzle_set_tile(p, col, row, temp);
          *current_pointer += 1;
        } else {
          fprintf(stderr, "Invalid tile value\n");
          return 3;
        }

      } else {
        fprintf(stderr, "Invalid input\n");
        return 4;
      }
    }
  }

  free(temp_arr);

  return 0;
}

int initialzeTiles(Puzzle *p, Image *img) {
  // TODO check if dims are equal
  // check if dims match puzzle and size
  // check if they are divisible
  const int size = p->size;
  const int dims = img->cols;
  const int blockSize = dims/size;

  // Being sure to reserve one for the black image
  Tile * tiles = malloc(sizeof(Tile) * size * size + 1);
  int offset = 0;
  for (int i=1; i < (size * size); i++) {
    tiles[i].blockSize = dims/size;
    tiles[i].imageBlock = malloc(sizeof(Pixel) * blockSize * blockSize);
    
    int pixel_offset = 0;
    Pixel *topleft = &(img->data[(i-1) * (dims/size) + offset]);
    for (int j=0; j < (blockSize * blockSize); j++) {
      tiles[i].imageBlock[j] = topleft[j + pixel_offset];

      if (!(size % j) && j != 0) {
        pixel_offset += dims;
      }
    }
    if (!(size % i) && i != 0) {
      offset += dims * size;
    }
  }

  tiles[0].imageBlock = malloc(sizeof(Pixel) * blockSize * blockSize);
  for (int i = 0; i < (blockSize * blockSize); i++) {
    tiles[0].imageBlock[i].r = 0;
    tiles[0].imageBlock[i].g = 0;
    tiles[0].imageBlock[i].b = 0;
  }
  p->tiles = tiles;
  return 0;
}

// Do I make this return back the image_ptr
int handle_I_command(FILE *in, Image **im, int standin) {
  // check if this is correct array size
  char arr[256];
  
  // checks if it's coming from standard in, this relies on short circuit to prevent unintended behavior
  if (!(standin) && fscanf(in, " %s", arr) != 1 || standin && scanf(" %s", arr) != 1) {
    fprintf(stderr, "Invalid input\n");
    return 1;
  }

  FILE *img_file_ptr = fopen(arr, "r");

  *im = ReadPPM(img_file_ptr);
  
  // checks if image file is valid
  if (*im == NULL) {
    fprintf(stderr, "Could not open image file '%s'\n", arr);
    return 2;
  }

  fclose(img_file_ptr);
  return 0;  // indicates success
}

int handle_P_command(Puzzle *p) {
  if (!p) {
    fprintf(stderr, "No puzzle\n");
    return 1;
  }

  for (int row = 0; row < p->size; row++) {
    for (int col = 0; col < p->size; col++) {
      int tile_val = puzzle_get_tile(p, col, row);

      fprintf(stdout, "%c", tile_val);

      if ((row != (p->size) - 1) && (col != (p->size) - 1)) {
        fprintf(stdout, " ");
      } else {
        fprintf(stdout, "\n");
      }
    }
  }

  return 1;
}

int handle_W_command(FILE *in, Image *im, Puzzle *p, int standin) {
  // background image rows or columns not evenly divisible by puzzle rows/columns	
  if (im->rows != im->cols || im->rows % p->size != 0) {
    fprintf(stderr, "Invalid image dimensions\n");
    return 1;
  }
  
  // background image hasn’t been read
  if(!im) {
    fprintf(stderr, "No image\n");
    return 2;
  }

  // puzzle has not been created
  if (!p) {
    fprintf(stderr, "No puzzle\n");
    return 3;
  }

  // assures dimensions within puzzle are correct
  assert(((p->size * p->tiles->blockSize) * (p->size * p->tiles->blockSize)) == im->rows * im->cols);
  
  char filename[256];
  if (!(standin) && fscanf(in, " %s", filename) != 1 || standin && scanf(" %s", filename) != 1) {
    fprintf(stderr, "Invalid input\n");
    return 4;
  }
  
  // populates tiles within puzzle object properly
  initialzeTiles(p, im);
  
  // opens file for writing
  FILE *img_file_ptr = fopen(filename, "w");
  if (!img_file_ptr) {
    fprintf(stderr, "Could not open output image file %s\n", filename);
    return 5;
  }
  
  // writes result
  Image *newImage = exportImage(p);
  int result = WritePPM(img_file_ptr, newImage);

  // validates number of pixels written is expected
  assert(result == ((p->size * p->tiles->blockSize) * (p->size * p->tiles->blockSize)));

  // frees created image
  free(newImage->data);
  free(newImage);

  fclose(img_file_ptr);
  return 0; // indicates success
}

int handle_S_command(FILE *in, Puzzle *p, int standin) {
  // double check with hand book for errors
  char command;
  if (!(standin)) {
    if (fscanf(in, " %c", &command) != 1) {
      fprintf(stderr, "Invalid input\n");
      return 1;
    }
  } else {
    if (scanf(" %c", &command) != 1) {
      fprintf(stderr, "Invalid input\n");
      return 1;
    }
  }

  return move_puzzle(p, command);
}

int handle_V_command(Puzzle* p) {
  const int max_steps = 32;
  char * final_steps = malloc(sizeof(char) * max_steps);
  int required_steps = solve_puzzle(p, final_steps, max_steps, 0);

  if (required_steps == max_steps) {
    printf("No solution found\n");
    return 1;
  }

  // sanity check to assure that the null terminator is correct
  assert(strlen(final_steps) == required_steps);

  // while (1) {
  //   char *steps = malloc(sizeof(char) * max_steps);
  //   assert(steps);

  //   int required_steps = solve_puzzle(p, steps, max_steps, 0);
  //   if (required_steps != max_steps) {
  //     final_required_steps = required_steps;
  //     final_steps = steps;
  //     break;
  //   }
  //   free(steps);
  //   max_steps++;
  // }

  for (int i=0; i < required_steps; i++) {
    printf("S %c\n", final_steps[i]);
  }
  return 0;
}

int handle_K_command(Puzzle* p) {
  if (!p) {
    fprintf(stderr, "No puzzle\n");
    return 1;
  }

  if (puzzle_solved(p)) {
    printf("Solved\n");
    return 0;  
  } else {
    printf("Not solved\n");
    return 0; 
  }
}
