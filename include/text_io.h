#ifndef TEXT_IO_H
#define TEXT_IO_H
#include <stdio.h>

void write_game(int* array, int size, FILE* file);
int* read_moves(FILE* file, int size);

#endif // TEXT_IO_H
