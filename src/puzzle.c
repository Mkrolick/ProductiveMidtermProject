// Zachary Sayyah zsayyah1
// Malcolm Krolick mkrolick1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ppm_io.h"
#include "puzzle.h"

//TODO: look over all error codes in context to requirements


int main(int argc, char **argv) {
  if (argc < 1 || argc > 2) {
    fprintf(stderr, "Usage: ./puzzle [<command file>]\n");
    return 1;
  }

  FILE* fp = fopen(argv[1], "r");

  if (!fp) {
    fprintf(stderr, "Txt file couldn't be opened\n");
    return 1;
  }

  
  //int puzzle_created = 0;
  char command;
  int val = 1;
  //int size;
  int res = fscanf(fp, " %c", &command);

  Puzzle** p = NULL;
  Image** img = NULL;
  

  //exits if res = EOF as EOF != 1
  while (res == 1){
    switch (command)
    {
    case 'C':
      val = handle_C_command(fp, p);
      break;
    case 'T':
      val = handle_T_command(fp, *p);
      break;
    case 'I':
      val = handle_I_command(fp, img);
      break;
    case 'P':
      val = handle_P_command(*p);
      break;
    case 'W':
      //val = handle_W_command(fp, *img, *p);
      break;
    case 'S':
      val = handle_W_command(fp, *img, *p);
      break;
    case 'K':
      printf("lmao");
      //val = handle_K_command(*p);
      break;
    case 'V':
      printf("lmao");

      //val = handle_V_command(*p);
      break;
    case 'Q':
      printf("lmao");
      return 0;
      break;
    default:
      fprintf(stderr, "Invalid command '%c", command);
      return 1;
      break;
    }

    if (val != 0) {
      return 1;
    }

    //load up res again
    int res = fscanf(fp, " %c", &command);
  }

  return 0;
}

/******************************************************************
 * 
 * Command Handlers
 * 
*******************************************************************/

int handle_C_command(FILE *in, Puzzle **p) {
  

  // differences in return are to help in debugging
  int size = 0;

  // Checking if size is read in properly
  if ((fscanf(in, " %d", &size) != 1)) {
    fprintf(stderr, "Invalid input");
    return 1;
  }

  // Checking if size is out of bounds
  if (size < 2 || size > 20) {
    fprintf(stderr, "Invalid puzzle size");
    return 2;
  }

  // Assume pointer is valid - as no error code
  // check if another error with invalid dimension sizes exist - IE 4 by 4 image 3 section splices.
  *p = puzzle_create(size);

  return 0;
}

int handle_T_command(FILE *in, Puzzle *p) {
  if (!(p->created)) {
    fprintf(stderr, "No puzzle");
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

          if (fscanf(in, " %d", &temp) == 1) {

            // calculates the address in memory for the temp_arr where val is present
            // pointer is not acessed unless temp is valid
            int* current_pointer = temp_arr + (size*(temp/size)) + temp/size;

            if (temp > 15 || temp < 0) {
              // is that invalid input or invalid tile value
              fprintf(stderr, "Invalid tile value");
              return 2;
            }
            else if (*current_pointer == 0) {
              puzzle_set_tile(p, col, row, temp);
              *current_pointer += 1;
            } else {
              fprintf(stderr, "Invalid tile value");
              return 3;
            }

          } else {
            fprintf(stderr, "Invalid input");
            return 4;
            
          }
      }
    }

    free(temp_arr);

    return 0;
}

// Do I make this return back the image_ptr
int handle_I_command(FILE *in, Image** im) {
  // check if this is correct array size
  char arr[256];

  if (fscanf(in, " %s", arr) != 1) {
    fprintf(stderr, "Invalid input");
    return 1;
  }

  // change read to write in the future?
  FILE* img_file_ptr = fopen(arr, "r");  

  *im = ReadPPM(img_file_ptr);

  if (*im == NULL) {
    fprintf(stderr, "Could not open image file '%s'", arr);
    return 1;
    
  }

  free(img_file_ptr);
  return 0; // indicates success
}


int handle_P_command(Puzzle *p) {
  if (!(p->created)) {
    fprintf(stderr, "No puzzle");
    return 1;
  }

  for (int row = 0; row < p->size; row++) {
    for (int col = 0; col < p->size; col++) {
      int tile_val = puzzle_get_tile(p, row, col);

      fprintf(stdout, "%c", tile_val);

      if ((row != (p->size) - 1) && (col != (p->size) -1)){
        fprintf(stdout, " ");
      } else {
        fprintf(stdout, "\n");
      }
    }
  }

  return 1;
}

int handle_W_command(FILE* in, Image *im, Puzzle *p) {
  if (!(p->created)) {
    fprintf(stderr, "No puzzle");
    return 1;
  }


  return 0;

}

int handle_S_command(FILE* in, Puzzle *p) {
  // double check with hand book for errors
  char command;
  if (fscanf(in, " %c", &command) != 1) {
    fprintf(stderr, "Invalid input");
    return 1;
  }
  
  // might need to use a pointer array for this
  char temp[p->size];

  int tile_found = 0;
  int found_col;
  int found_row;


  switch (command) {
    case 'u':

      for (int row = 0; row < ((p->size) - 1); row++) {
        for (int col = 0; col < (p->size); col++) {
          if (puzzle_get_tile(p, col, row) == 0) {
            found_col = col;
            found_row = col;
            tile_found = 1;
          } 
        } 
      }

      if (!tile_found) {
        fprintf(stderr, "Puzzle cannot be moved in specified direction");
        return 1;
      }

      temp[0] = 0;

      for (int row = 1; row < (p->size); row++) {
        if (puzzle_get_tile(p, found_col, row) != 0) {
          temp[row] = puzzle_get_tile(p, found_col, row);
        }
      }
      
      for (int row = 0; row < (p->size); row++) {
        puzzle_set_tile(p, found_col, ((p->size)-1)-row, temp[row]);
      }
      
    case 'd':

      for (int row = 1; row < (p->size); row++) {
        for (int col = 0; col < (p->size); col++) {
          if (puzzle_get_tile(p, col, row) == 0) {
            found_col = col;
            found_row = col;
            tile_found = 1;
          } 
        } 
      }

      if (!tile_found) {
        fprintf(stderr, "Puzzle cannot be moved in specified direction");
        return 1;
      }

      temp[0] = 0;

      for (int row = 1; row < (p->size); row++) {
        if (puzzle_get_tile(p, found_col, row) != 0) {
          temp[row] = puzzle_get_tile(p, found_col, row);
        }
      }
      
      for (int row = 0; row < (p->size); row++) {
        puzzle_set_tile(p, found_col, row, temp[row]);
      }

      break;

    case 'l':

      // NEed to UPDATE YAY

      for (int row = 0; row < (p->size); row++) {
        for (int col = 0; col < ((p->size) -1); col++) {
          if (puzzle_get_tile(p, col, row) == 0) {
            found_col = col;
            found_row = col;
            tile_found = 1;
          } 
        } 
      }

      if (!tile_found) {
        fprintf(stderr, "Puzzle cannot be moved in specified direction");
        return 1;
      }

      temp[0] = 0;

      for (int col = 1; col < (p->size); col++) {
        if (puzzle_get_tile(p, col, found_row) != 0) {
          temp[col] = puzzle_get_tile(p, col, found_row);
        }
      }
      
      for (int row = 0; row < (p->size); row++) {
        puzzle_set_tile(p, found_col, ((p->size)-1)-row, temp[row]);
      }
      
      break;

    case 'r':

      // UPdate YAY
      for (int row = 1; row < (p->size); row++) {
        for (int col = 0; col < (p->size); col++) {
          if (puzzle_get_tile(p, col, row) == 0) {
            found_col = col;
            found_row = col;
            tile_found = 1;
          } 
        } 
      }

      if (!tile_found) {
        fprintf(stderr, "Puzzle cannot be moved in specified direction");
        return 1;
      }

      temp[0] = 0;

      for (int row = 1; row < (p->size); row++) {
        if (puzzle_get_tile(p, found_col, row) != 0) {
          temp[row] = puzzle_get_tile(p, found_col, row);
        }
      }
      
      for (int col = 0; col < (p->size); col++) {
        puzzle_set_tile(p, col, found_row, temp[col]);
      }

      break;
    default:

      fprintf(stderr, "Invalid command '%c", command);
      return 2;
      break;

    }

    return 0;
}



