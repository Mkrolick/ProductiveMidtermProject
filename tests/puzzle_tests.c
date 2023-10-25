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
void test_C_command(void) {
  // test if puzzle create has valid output
  FILE* fp;
  Puzzle** p;
  int res;


  fp = fopen("../tests/function_tests/c_cmd_1", "r");
  p = NULL;
  

  res = handle_C_command(fp, p, 0);
  assert(res == 1);
  fclose(fp);

  fp = fopen("../tests/function_tests/c_cmd_2", "r");
  p = NULL;

  res = handle_C_command(fp, p, 0);
  assert(res == 2);
  fclose(fp);

  fp = fopen("../tests/function_tests/c_cmd_3", "r");
  p = NULL;

  res = handle_C_command(fp, p, 0);
  assert(res == 2);
  fclose(fp);

  fp = fopen("../tests/function_tests/c_cmd_4", "r");
  p = NULL;

  res = handle_C_command(fp, p, 0);
  assert(res == 0);
  fclose(fp);

  //handle_P_command(*p);

}






void test_T_command(void) {
  FILE* fp = fopen("../tests/function_tests/t_cmd_1", "r");
  Puzzle* p = NULL;


  int res = handle_T_command(fp, p, 0);
  assert(res == 1);

  fp = fopen("../tests/function_tests/t_cmd_2", "r");
  p = puzzle_create(4);

  
  res = handle_T_command(fp, p, 0);
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

  Image** im = malloc(sizeof(Image*));
  FILE* fp = fopen("../tests/function_tests/i_cmd_1","r");

  int res = handle_I_command(fp, im, 0);

  assert(res == 1);


  fp = fopen("../tests/function_tests/i_cmd_2","r");

  res = handle_I_command(fp, im, 0);

  assert(res == 2);


  fp = fopen("../tests/function_tests/i_cmd_3","r");

  res = handle_I_command(fp, im, 0);

  assert(res == 2);
  

  fp = fopen("../tests/function_tests/i_cmd_4","r");

  res = handle_I_command(fp, im, 0);

  assert(res == 3);


  fp = fopen("../tests/function_tests/i_cmd_5","r");

  res = handle_I_command(fp, im, 0);

  assert(res == 0);
}


void test_P_command(void) {
  FILE* fp = fopen("../tests/function_tests/t_cmd_5", "r");
  Puzzle* p = NULL;

  int res = handle_T_command(fp, p, 0);
  assert(res == 0);

  res = handle_P_command(p);
  assert(res == 0);
}


void test_S_command(void) {

  // testing down function
  FILE* fp = fopen("../tests/function_tests/t_cmd_5", "r");
  Puzzle* p = NULL;

  int res = handle_T_command(fp, p, 0);
  assert(res == 0);



  // First batch where 0 is bottom right
  fp = fopen("../tests/function_tests/s_cmd_1_d", "r");

  res = handle_S_command(fp, p, 0);
  assert(res == 0);

  fp = fopen("../tests/function_tests/s_cmd_4_l", "r");

  res = handle_S_command(fp, p, 0);
  assert(res == 2);


  // First batch where 0 is top right
  fp = fopen("../tests/function_tests/s_cmd_2_r", "r");

  res = handle_S_command(fp, p, 0);
  assert(res == 0);

  fp = fopen("../tests/function_tests/s_cmd_1_d", "r");

  res = handle_S_command(fp, p, 0);
  assert(res == 2);


  // First batch where 0 is top left
  fp = fopen("../tests/function_tests/s_cmd_3_u", "r");

  res = handle_S_command(fp, p, 0);
  assert(res == 0);

  fp = fopen("../tests/function_tests/s_cmd_2_r", "r");

  res = handle_S_command(fp, p, 0);
  assert(res == 2);

  
  // First batch where 0 is bottom left
  fp = fopen("../tests/function_tests/s_cmd_4_l", "r");

  res = handle_S_command(fp, p, 0);
  assert(res == 0);

  fp = fopen("../tests/function_tests/s_cmd_3_u", "r");

  res = handle_S_command(fp, p, 0);
  assert(res == 2);

  //Invalid input
  fp = fopen("../tests/function_tests/s_cmd_5", "r");

  res = handle_S_command(fp, p, 0);
  assert(res == 3);
}


void test_K_command(void) {

  // testing down function
  FILE* fp = fopen("../tests/function_tests/t_cmd_5", "r");
  Puzzle* p = NULL;

  int res = handle_K_command(p);
  assert(res == 0);

  fp = fopen("../tests/function_tests/t_cmd_3", "r");
  p = NULL;

  res = handle_K_command(p);
  assert(res == 0);

  p = NULL;

  res = handle_K_command(p);
  assert(res = 1);
}


void test_W_command(void) {
  FILE* fp;
  Puzzle** p;
  Image** im;
  int res;
  

  fp = fopen("w_cmd_1_1", "r");
  res = handle_C_command(fp, p, 0);

  fp = fopen("w_cmd_1_2", "r");
  res = handle_T_command(fp, *p, 0);

  fp = fopen("w_cmd_1_3", "r");
  res = handle_I_command(fp, im, 0);
  
  fp = fopen("w_cmd_1_4", "r");
  res = handle_W_command(fp, *im, *p, 0);
}





int main(void) {
  
  //test_puzzle_create();
  //test_puzzle_set_tile();

  //test_C_command();
  //test_T_command();
  //test_I_command();
  //test_P_command();
  test_W_command();
  //test_S_command();
  //test_K_command();
  //test_V_command();  
  

  printf("All tests passed!\n");
  return 0;
}
