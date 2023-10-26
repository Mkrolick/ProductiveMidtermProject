#include "read_utils.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ppm_io.h"
#include "puzzle.h"

// The differences in return are to help in debugging

int handle_C_command(FILE *in, Puzzle **p, int standin) {
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

  *p = puzzle_create(size);

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
    temp_arr[i] = 0;
  }

  int temp;
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      // checks if it's coming from standard in, this relies on short circuit to
      // prevent unintended behavior
      if ((!(standin) && (fscanf(in, " %d", &temp) == 1)) ||
          (standin && (scanf(" %d", &temp) == 1))) {
        // calculates the address in memory for the temp_arr where val is
        // present pointer is not acessed unless temp is valid
        int *current_pointer = temp_arr + (size * (temp / size)) + temp % size;

        if (temp > (size * size) || temp < 0) {
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
  if (p->tiles) {
    for (int i = 0; i <= ((p->size) * (p->size)); i++) {
      if (p->tiles[i].imageBlock) {
        free(p->tiles[i].imageBlock);
      }
    }   
    free(p->tiles);
    p->tiles = NULL;
  }
  
  const int size = p->size;
  const int dims = img->cols;
  const int blockSize = dims / size;

  // making sure to reserve one for the black image
  Tile *tiles = malloc(sizeof(Tile) * size * size + sizeof(Tile));
  int offset = 0;
  for (int i = 1; i <= (size * size); i++) {
    tiles[i].blockSize = blockSize;
    tiles[i].imageBlock = malloc(sizeof(Pixel) * blockSize * blockSize);

    int pixel_offset = 0;

    int top_left_int = (i - 1) * (blockSize) + offset;
    // creates a pointer to the top left corner of the tile
    Pixel *topleft = &(img->data[top_left_int]);
    for (int k = 0; k < blockSize; k++) {
      for (int j = 0; j < (blockSize); j++) {
        // calculates the index of the desired tile pixel in the image
        int pixel_index_greater_image = j + pixel_offset;

        // copies over individual RGB values for pixels
        tiles[i].imageBlock[j + k * blockSize].r =
            topleft[pixel_index_greater_image].r;
        tiles[i].imageBlock[j + k * blockSize].g =
            topleft[pixel_index_greater_image].g;
        tiles[i].imageBlock[j + k * blockSize].b =
            topleft[pixel_index_greater_image].b;
      }
      pixel_offset += dims;
    }
    if (i != 0 && !(i % size)) {
      offset += dims * (blockSize - 1);
    }
  }
  tiles[0].blockSize = blockSize;
  tiles[0].imageBlock = malloc(sizeof(Pixel) * blockSize * blockSize);
  for (int i = 0; i < (blockSize * blockSize); i++) {
    tiles[0].imageBlock[i].r = 0;
    tiles[0].imageBlock[i].g = 0;
    tiles[0].imageBlock[i].b = 0;
  }
  p->tiles = tiles;
  return 0;
}

int handle_I_command(FILE *in, Image **im, int standin) {
  char arr[256];

  // checks if it's coming from standard in, this relies on short circuit to
  // prevent unintended behavior
  if ((!(standin) && fscanf(in, " %s", arr) != 1) ||
      (standin && scanf(" %s", arr) != 1)) {
    fprintf(stderr, "Invalid input\n");
    return 1;
  }

  FILE *img_file_ptr = fopen(arr, "r");

  if (!img_file_ptr) {
    fprintf(stderr, "Could not open image file '%s'\n", arr);
    return 2;
  }

  *im = ReadPPM(img_file_ptr);

  // checks if image file is valid
  if (*im == NULL) {
    return 3;
  }

  fclose(img_file_ptr);
  return 0; 
}

int handle_P_command(Puzzle *p) {
  if (!p) {
    fprintf(stderr, "No puzzle\n");
    return 1;
  }

  for (int row = 0; row < p->size; row++) {
    for (int col = 0; col < p->size; col++) {
      int tile_val = puzzle_get_tile(p, col, row);

      fprintf(stdout, "%d", tile_val);

      if ((row == (p->size) - 1) && (col == (p->size) - 1)) {
        fprintf(stdout, "\n");
      } else {
        fprintf(stdout, " ");
      }
    }
  }

  return 0;
}

int handle_W_command(FILE *in, Image *im, Puzzle *p, int standin) {
  // check if background image hasn’t been read
  if (!im) {
    fprintf(stderr, "No image\n");
    return 2;
  }

  // check if puzzle has not been created
  if (!p) {
    fprintf(stderr, "No puzzle\n");
    return 3;
  }

  // background image rows or columns not evenly divisible by puzzle
  // rows/columns
  if (im->rows != im->cols || im->rows % p->size != 0) {
    fprintf(stderr, "Invalid image dimensions\n");
    return 1;
  }

  // populates tiles within puzzle object properly
  initialzeTiles(p, im);

  // assures dimensions within puzzle are correct
  assert(((p->size * p->tiles->blockSize) * (p->size * p->tiles->blockSize)) ==
         im->rows * im->cols);

  char filename[256];
  if ((!(standin) && fscanf(in, " %s", filename) != 1) ||
      (standin && (scanf(" %s", filename) != 1))) {
    fprintf(stderr, "Invalid input\n");
    return 4;
  }

  char filename_pos[256];
  if ((!(standin) && (fscanf(in, " %s", filename_pos) != 1)) ||
      (standin && (scanf(" %s", filename_pos) != 1))) {
    fprintf(stderr, "Invalid input\n");
    return 5;
  }

  // opens file for writing
  FILE *img_file_ptr = fopen(filename, "w");
  if (!img_file_ptr) {
    fprintf(stderr, "Could not open output image file '%s'\n", filename);
    return 6;
  }

  // writes result to image
  Image *newImage = exportImage(p);
  int result = WritePPM(img_file_ptr, newImage);

  // write PPM failed which means that we must return but not write errors
  if (result == -1) {
     return 8;
  }

  // validates number of pixels written is expected
  assert(result ==
         ((p->size * p->tiles->blockSize) * (p->size * p->tiles->blockSize)));

  // frees created image
  free(newImage->data);
  free(newImage);

  fclose(img_file_ptr);

  FILE *img_file_ptr_pos = fopen(filename_pos, "w");
  if (!img_file_ptr_pos) {
    fprintf(stderr, "Could not open output image file '%s'\n", filename_pos);
    return 7;
  }

  write_game(p->positions, p->size, img_file_ptr_pos);
  fclose(img_file_ptr_pos);

  // indicates success
  return 0;  
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

  int res = move_puzzle(p, command);
  if (res == 2) {
    fprintf(stderr, "Puzzle cannot be moved in specified direction\n");
  } else if (res == 3) {
    fprintf(stderr, "Invalid command '%c'\n", command);
  }

  return res;
}

int handle_V_command(Puzzle *p) {
  // puzzle has not been created
  if (!p) {
    fprintf(stderr, "No puzzle\n");
    return 3;
  }

  const int max_steps = 30;
  char *final_steps = malloc(sizeof(char) * max_steps);
  int required_steps = solve_puzzle(p, final_steps, max_steps, 0, '\0');

  if (required_steps == max_steps) {
    printf("No solution found\n");
    return 1;
  }

  // ensure that the null terminator is correct
  assert((int)strlen(final_steps) == required_steps);

  for (int i = 0; i < required_steps; i++) {
    printf("S %c\n", final_steps[i]);
  }
  free(final_steps);
  return 0;
}

int handle_K_command(Puzzle *p) {
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
