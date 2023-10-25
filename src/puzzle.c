// Zachary Sayyah zsayyah1
// Malcolm Krolick mkrolick1
#include "puzzle.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "ppm_io.h"

// TODO: look over all error codes in context to requirements

int main(int argc, char** argv) {
  if (argc == 0 || argc > 2) {
    fprintf(stderr, "Usage: ./puzzle [<command file>]\n");
    return 1;
  }

  char command;
  int val = 1;
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

    // int puzzle_created = 0;

    // int size;
    res = fscanf(fp, " %c", &command);
  } else {
    standin = 1;

    res = scanf(" %c", &command);
  }

  Puzzle** p = malloc(sizeof(Puzzle*));
  Image** img = malloc(sizeof(Image*));  // TODO seems like a problem

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
        return 0;
        break;
      default:
        fprintf(stderr, "Invalid command '%c'\n", command);
        return 1;
        break;
    }

    if (val != 0) {
      return 1;
    }

    // load up res again
    res = standin ? scanf(" %c", &command) : fscanf(fp, " %c", &command);
  }

  return 0;
}
