/* number_puzzle.c
   Write a number puzzle program by completing the TO DOs
   TO DO 1: Initialize the puzzle, such that the numbers 1 to 15 are randomly distributed in the array.
            -1 should mark the empty field.
   TO DO 2: get key and move pieces accordingly (if keystroke is valid)
   TO DO 3: Check, if puzzle is in correct order -> set sorted=1
   TO DO 4: Create a more fancy output, e.g. by creating frames around the numbers
                (Use a special character e.g. a block rather than '*')
                (Also, mark the empty field rather than showing -1)

            *********************
            *  1 *  2 *  3 *  4 *
            *********************
            *  5 *  6 *  7 *  8 *
            *********************
            *  9 * 10 * 11 * 12 *
            *********************
            * 13 * 14 * 15 ******
            *********************

   TO DO 5, optional: created an automatic, intelligent puzzle solver, which solves the puzzle without user interaction.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int move(char direction, int print_errors);

int puzzle[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, -1}};

int shuffle(int puzzle[4][4])
{
  for(int i = 0; i < 100; i++) {
    move("wasd"[rand() % 4], 0);
  }
  
  return 0;
}

int print(int puzzle[4][4])
{
  for (int i = 0; i < 4; i++)
  {
    printf("*********************\n");
    for (int j = 0; j < 4; j++)
    {
      printf("* ");
      if (puzzle[i][j] == -1)
        printf("   ");
      else
        printf("%2d ", puzzle[i][j]);

    }
    printf("*\n");
  }
  printf("*********************\n");

  return 0;
}

int is_sorted(int puzzle[4][4])
{
  int sorted = 1;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if ((i == 3 && j == 3 && puzzle[i][j] != -1) && (puzzle[i][j] != i * 4 + j + 1))
      {
        sorted = 0;
      }
    }
  }
  return sorted;
}

int move(char key, int print_errors)
{

  int empty_pos = 15;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (puzzle[i][j] == -1)
      {
        empty_pos = i * 4 + j;
      }
    }
  }

  int start_row = empty_pos / 4;
  int start_column = empty_pos % 4;
  int tmp;

  int row = start_row;
  int column = start_column;

  switch (key)
  {
  case 'w':
    row = start_row - 1;
    break;
  case 's':
    row = start_row + 1;
    break;
  case 'a':
    column = start_column - 1;
    break;
  case 'd':
    column = start_column + 1;
    break;
  default:
    printf("Invalid key\n");
    break;
  }

  if (column > 3 || column < 0 || row > 3 || row < 0)
  {
    if (print_errors)
      printf("Invalid move\n");
    return 1;
  }

  puzzle[start_row][start_column] = puzzle[row][column];
  puzzle[row][column] = -1;

  return 0;
}

int main()
{
  srand(time(0));

  char key;        // This holds the current key entered by the player.
  char sorted = 0; // This flag indicates whether the field is sorted.
  
  shuffle(puzzle);
  print(puzzle);

  while (!sorted)
  {
    printf("move into direction? (w=up, s=down, a=left, d=right): ");
    scanf(" %c", &key); // Read a single character and ignore leading whitespace

    move(key, 1);

    print(puzzle);

    sorted = is_sorted(puzzle);

    if (sorted)
    {
      printf("Congratulations, you solved the puzzle!\n");
    }
  }
}