/* Game of life
The "game of life" is an old and very simple approach of simulating evolution
A 2-dimensional field of cells is regarded with a cell being either empty/dead (0) or occupied/alive (1)
The intial state can be chosen e.g. manually or using some random operations.

The further evolution is governed by the following rules:

Every cell interacts with its eight neighbours, which are the cells that are directly horizontally, vertically, or diagonally adjacent.
At each step in time, the following transitions occur:
   1. Any live cell with fewer than two live neighbours dies, as if by needs caused by underpopulation.
   2. Any live cell with more than three live neighbours dies, as if by overcrowding.
   3. Any live cell with two or three live neighbours lives, unchanged, to the next generation.
   4. Any empty/dead cell with exactly three live neighbours cells will be populated with a living cell.

The initial pattern constitutes the 'seed' of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed � births and deaths happen simultaneously, and the discrete moment at which this happens is sometimes called a tick. (In other words, each generation is a pure function of the one before.)  The rules continue to be applied repeatedly to create further generations.

see: http://en.wikipedia.org/wiki/Conway's_Game_of_Life
*/

// TO DO: Complete the programm such that it simulates the game of life.
//        Do it as teamwork (e.g. in teams with 2 or 3)
//        and benefit from being able to develop functions independently and integrate them into the final program.
// TO DO optional 1: extend the program, such that it detects 'stable states', i.e. the system is oscillating between a few states.
// TO DO optional 2: let the program find a start state such that the system stays alive and unstable for as long as possible
// TO DO optional 3: Create a flicker-free output: Do not print each character separately, but write the output into a string, which is printed all at once
// TO DO optional 4: extend the program such that the content of the cells can be edited by the user.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 50

int count_neighbour_cells(int x, int y);

// Global 2-dim-array which contains the cells
int cells[ROWS][COLS];
int cells_helper[ROWS][COLS];

// TO DO: initialize cells, set most to 0, some to 1
void initialize_cells()
{
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      if (rand() % 10 == 0)
        cells[i][j] = 1;
      else
        cells[i][j] = 0;
    }
  }
}

// TO DO: Write output function to show the cells
void display_cells()
{
  system("clear"); // sends Clear screen to the console (Windows), Linux: "clear"
                   
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      if (cells[i][j] == 1)
        printf("O");
      else
        printf(" ");
    }
    printf("\n");
  }
}

// TO DO: Write a function to calculate the next evolution step
void evolution_step()
{
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      cells_helper[i][j] = cells[i][j];

      if (cells[i][j] == 1) {
        int neighbour_count = count_neighbour_cells(i, j);

        if (neighbour_count < 2 || neighbour_count > 3)
          cells_helper[i][j] = 0;
        else if (neighbour_count == 3)
          cells_helper[i][j] = 1;
        
      } else {
        int neighbour_count = count_neighbour_cells(i, j);

        if (neighbour_count == 3)
          cells_helper[i][j] = 1;
      }
    }
  }

  // Copy cells_helper to cells
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      cells[i][j] = cells_helper[i][j];
    }
  }
}

int count_neighbour_cells(int x, int y) {
  int count = 0;

  if (x > 0 && y > 0 && cells[x - 1][y - 1] == 1) count++;                // top left
  if (x > 0 && cells[x - 1][y] == 1) count++;                             // top
  if (x > 0 && y < COLS - 1 && cells[x - 1][y + 1] == 1) count++;         // top right
  if (y > 0 && cells[x][y - 1] == 1) count++;                             // left
  if (y < COLS - 1 && cells[x][y + 1] == 1) count++;                      // right
  if (x < ROWS - 1 && y > 0 && cells[x + 1][y - 1] == 1) count++;         // bottom left
  if (x < ROWS - 1 && cells[x + 1][y] == 1) count++;                      // bottom
  if (x < ROWS - 1 && y < COLS - 1 && cells[x + 1][y + 1] == 1) count++;  // bottom right

  return count;
}

// TO DO: Write a function that counts the occupied cells
int count_cells()
{
  int count = 0;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      count += cells[i][j];
    }
  }

  return count;
}

// Main program
int main()
{
  srand(time(0));
  initialize_cells();

  while (1)
  {
    display_cells();

    // Leave loop if there are no more occupied cells
    if (count_cells() == 0)
      break;

    nanosleep((const struct timespec[]){{0, 100000000L}}, NULL); // sleep for 0.5 seconds
    evolution_step();
  }
}