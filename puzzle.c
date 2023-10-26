// Zachary Sayyah zsayyah1
// Malcolm Krolick mkrolick1
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "puzzle.h"
#include "read_utils.h"


/* main
 * body of the function acting as the 15 puzzle simulator
 * can be ran in either file reading mode or from user input
 * with a variety of different commands
 */
int main(int argc, char** argv) {
  if (argc == 0 || argc > 2) {
    fprintf(stderr, "Usage: ./puzzle [<command file>]\n");
    return 1;
  }

  int exit = 0;
  int val = 0;

  char command;
  int standin;
  int res;
  
  FILE* fp = NULL;

  if (argc == 2) {
    fp = fopen(argv[1], "r");
    standin = 0;

    if (!fp) {
      fprintf(stderr, "Txt file couldn't be opened\n");
      return 1;
    }

    res = fscanf(fp, " %c", &command);
  } else {
    standin = 1;

    res = scanf(" %c", &command);
  }

  Puzzle** p = malloc(sizeof(Puzzle*));
  Image** img = malloc(sizeof(Image*)); 

  // exits if res = EOF as EOF != 1
  while (res == 1) {
    switch (command) {
      case 'C':
        val = handle_C_command(fp, p, standin);
        break;
      case 'T':
        val = handle_T_command(fp, *p, standin);
        break;
      case 'I':
        val = handle_I_command(fp, img, standin);
        break;
      case 'P':
        val = handle_P_command(*p);
        break;
      case 'W':
        val = handle_W_command(fp, *img, *p, standin);
        break;
      case 'S':
        val = handle_S_command(fp, *p, standin);
        break;
      case 'K':
        val = handle_K_command(*p);
        break;
      case 'V':
        val = handle_V_command(*p);
        break;
      case 'Q':
        exit = 1;
        break;
      default:
        fprintf(stderr, "Invalid command '%c'\n", command);
        val = 1;
        break;
    }

    if (val != 0) {
      exit = 1;
    }
    
    if (exit) {
      break;
    }

    // load up res again
    res = standin ? scanf(" %c", &command) : fscanf(fp, " %c", &command);
  }
  

  //closing file pointer
  fclose(fp);
  
  //clearing image
  if ((*img != NULL) && (*img)->data) {
    free((*img) -> data);
  }

  if (*img) {
    free(*img);
  }

  free(img);

  //removing puzzle and associated pointers
  puzzle_destroy(*p);
  
  free(p);

  return val;
}
