#ifndef PUZZLE_R
#define PUZZLE_R

#include "ppm_io.h"  // for Image data type
#include "puzzle.h"
#include "puzzle_funcs.h"

/* puzzle_solved
 * Given a puzzle pointer checks if the puzzle is in a solved configuration
 * Returns int indicating success
 */
int puzzle_solved(Puzzle* p);

/* handle_C_command
 * Handles puzzle creation command
 * Returns int indicating success
 */
int handle_C_command(FILE *in, Puzzle **p, int standin);

/* handle_T_command
 * Handles puzzle configuration initialization command
 * Returns int indicating success
 */
int handle_T_command(FILE *in, Puzzle *p, int standin);

/* handle_I_command
 * Handles puzzle background loading command
 * Returns int indicating success
 */
int handle_I_command(FILE *in, Image **im, int standin);

/* handle_P_command
 * Handles command for printing the current positions
 * Returns int indicating success
 */
int handle_P_command(Puzzle *p);

/* handle_W_command
 * Handles command for saving current puzzle configuration as image
 * Returns int indicating success
 */
int handle_W_command(FILE *in, Image *im, Puzzle *p, int standin);

/* handle_S_command
 * Handles command for moving current puzzle configuration in accordance with the puzzle
 * Returns int indicating success
 */
int handle_S_command(FILE *in, Puzzle *p, int standin);

/* handle_K_command
 * Handles command for checking if the puzzle's current state is solved
 * Returns int indicating success
 */
int handle_K_command(Puzzle *p);

/* handle_V_command
 * Handles command for returning solution to the current puzzle if possible
 * Returns int indicating success
 */
int handle_V_command(Puzzle *p);

#endif  // PUZZLE_H
