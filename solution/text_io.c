// Zachary Sayyah zsayyah1
// Malcolm Krolick mkrolick1
#include "text_io.h"

void write_game_1(int* array, int size, FILE* file) {
  // confirms that we received a valid file handle
  for (int i = 0; i < size; i++) {
    fprintf(file, "%d ", array[i]);
  }
  fprintf(file, "\n");
}

int* read_moves(FILE* file) { return NULL; }