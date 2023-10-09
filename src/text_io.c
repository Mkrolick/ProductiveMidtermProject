#include "text_io.h"

void write_game(int* array, int size, FILE* file) {
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", array[i]);
    }
    fprintf(file, "\n");
}
int* read_moves(FILE* file) {
    
}