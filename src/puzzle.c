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
  Image** img = NULL; // TODO seems like a problem
  

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




