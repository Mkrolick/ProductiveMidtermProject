#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ppm_io.h"
#include "puzzle.h"

//Note: look over all error codes in context to requirements


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

  
  int puzzle_created = 0;
  int command;
  int size;
  int res = fscanf(" %c", command);

  Puzzle* p = NULL;
  

  //exits if res = EOF as EOF != 1
  while (res == 1){
    switch (command)
    {
    case 'C':

      // Checking if size is read in properly
      if ((fscanf(" %d", &size) != 1)) {
        fprintf(stderr, "Invalid input");
        return 1;
      }

      // Checking if size is out of bounds
      if (size < 2 || size > 20) {
        fprintf(stderr, "Invalid puzzle size");
        return 1;
      }

      p = puzzle_create(size);

      puzzle_created = 1;
      break;
    case 'T':
      if (!puzzle_created) {
        fprintf(stderr, "No puzzle");
        return 1;
      }


      break;
    case 'I':
      break;
    case 'P':
      if (!puzzle_created) {
        fprintf(stderr, "No puzzle");
        return 1;
      }

      break;
    case 'W':
      if (!puzzle_created) {
        fprintf(stderr, "No puzzle");
        return 1;
      }

      break;
    case 'S':
      break;
    case 'K':
      if (!puzzle_created) {
        fprintf(stderr, "No puzzle");
        return 1;
      }

      break;
    case 'V':
      if (!puzzle_created) {
        fprintf(stderr, "No puzzle");
        return 1;
      }

      break;
    case 'Q':
      break;
    default:
      break;
    }

    //load up res again
    int res = fscanf(" %c", command);
  }


  
  return 0;
}


