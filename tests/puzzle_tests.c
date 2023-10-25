#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "puzzle.h"


// also tests puzzle_destroy
void test_puzzle_create(void) {
  
  // replace postions with tiles
  Puzzle *p3 = puzzle_create(3);
  Puzzle *p5 = puzzle_create(5);
  
  assert(p3->size == 3);
  for (int i = 0; i < 9; ++i) {
    //printf("%d\n", (p3->positions)[i/3][i%3]);
    assert(p3->positions[i/3][i%3] == 0);
  }

  assert(p5->size == 5);
  for (int i = 0; i < 25; ++i) {
    assert(p5->positions[i/5][i%5] == 0);
  }

  puzzle_destroy(p3);
  puzzle_destroy(p5);
}

// also tests puzzle_get_tile
void test_puzzle_set_tile(void) {
  int init[4][4] = {
    { 5, 7, 1, 2 },
    { 13, 9, 3, 4 },
    { 0, 8, 6, 11 },
    { 14, 15, 10, 12 },
  };

  Puzzle *p4 = puzzle_create(4);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      puzzle_set_tile(p4, j, i, init[i][j]);
    }
  }

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      assert(puzzle_get_tile(p4, j, i) == init[i][j]);
    }
  }
  puzzle_destroy(p4);

}

// ...other test functions...

void test_T_command(void) {
  FILE* fp = fopen("../tests/function_tests/t_cmd_1", "r");
  Puzzle* p = NULL;


  int res = handle_T_command(fp, p, 0);
  assert(res == 1);

  fp = fopen("../tests/function_tests/t_cmd_2", "r");
  p = puzzle_create(4);

  
  res = handle_T_command(fp, p, 0);
  printf("\n%d\n", res);
  assert(res == 2);

  fp = fopen("../tests/function_tests/t_cmd_3", "r");
  p = puzzle_create(4);

  res = handle_T_command(fp, p, 0);
  assert(res == 3);

  fp = fopen("../tests/function_tests/t_cmd_4", "r");
  p = puzzle_create(4);

  res = handle_T_command(fp, p, 0);
  assert(res == 4);

  fp = fopen("../tests/function_tests/t_cmd_5", "r");
  p = puzzle_create(4);

  res = handle_T_command(fp, p, 0);
  assert(res == 0);
}

void test_I_command(void) {

  Image** im = NULL;
  FILE* fp = fopen("../tests/function_tests/i_cmd_1","r");

  int res = handle_I_command(fp, im, 0);

  assert(res == 1);

  im = NULL;
  fp = fopen("../tests/function_tests/i_cmd_2","r");

  res = handle_I_command(fp, im, 0);

  assert(res == 2);

  im = NULL;
  fp = fopen("../tests/function_tests/i_cmd_3","r");

  res = handle_I_command(fp, im, 0);

  assert(res == 2);
  
  im = NULL;
  fp = fopen("../tests/function_tests/i_cmd_4","r");

  res = handle_I_command(fp, im, 0);

  assert(res == 0);
}







int main(void) {
  
  
  //test_puzzle_create();
  printf("Segfault Passed\n");
  //test_puzzle_set_tile();

  test_T_command();
  //test_I_command();
  
  
  

  printf("All tests passed!\n");
  return 0;
}
