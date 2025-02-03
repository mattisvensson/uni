// hanoi.c Towers of hanoi
// TO DO: Extend the programm such that it creates a graphical output of the disks on the three disks
//        introduce a function display(), which is called from hanoi()
//        Use global or static variables to keep the status of the disk towers.

#include <stdio.h>
#include <stdlib.h>

int disks = 1;

#define ROWS 3
#define COLS 11

int towers[ROWS][COLS];

void initialize_towers(int disks)
{
  // Initialize the towers with some values for demonstration
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      towers[i][j] = 0;
    }
  }

  // Example initialization: tower 1 has disks, others are empty
  for (int i = 0; i < disks; i++)
  {
    towers[0][i] = disks - i;
  }

  // Print the towers
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      printf("%d ", towers[i][j]);
    }
    printf("\n");
  }
}

void display(int start, int goal)
{
  int tmp;

  printf("----------------------------------\n");

  for (int i = 0; i < COLS; i++)
  {
    if (towers[start][i] == 0)
    {
      tmp = towers[start][i - 1];
      towers[start][i - 1] = 0;
      break;
    }
  }

  for (int i = 0; i < COLS; i++)
  {
    if (towers[goal][i] == 0)
    {
      towers[goal][i] = tmp;
      break;
    }
  }

  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      printf("%d ", towers[i][j]);
    }
    printf("\n");
  }
}

void hanoi(int disks, int start, int goal, int helper)
{

  if (disks > 0)
  {
    hanoi(disks - 1, start, helper, goal);
    // printf("move disk from %d to %d\n", start, goal);
    display(start, goal);
    hanoi(disks - 1, helper, goal, start);
  }
}

int main()
{
  printf("How many disks? (%d max): ", COLS - 1);

  scanf("%d", &disks);

  if (disks > COLS - 1)
  {
    printf("Too many disks\n");
    return EXIT_FAILURE;
  }

  initialize_towers(disks);

  hanoi(disks, 0, 1, 2);

  return EXIT_SUCCESS;
}