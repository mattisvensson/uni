/* Malloc_eratosthenes.c

   TO DO 1: Change the Eratosthenes program such that 'max' is a variable and can be entered by the user.
            Use malloc and pointers to allocate the memory for is_prime depending on max.
            Do not forget to use 'free' to free the memory afterwards.
   TO DO 2: What happens if you don't use free and if you allocate the memory several times, e.g.
            by putting the whole content of the main function in a loop?
            - How long can you allocate memory?
            - print the addresses where the memory is allocated.
            - Have a look at the task manager and monitor the memory usage of your program (process).
   TO DO 3: Have a look at your 'game of life' program:
            - What needs to be done to set the cell array flexibly using malloc?
            - How to deal with two-dimensional arrays?
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  while(1) {
    int Max;

    printf("Enter the max number: ");
    scanf("%d", &Max);

    int *ptr = malloc(Max * sizeof(int));

    if (ptr == NULL) {
      printf("Error allocating memory");
      return 0;
    };

    int i, j;
    unsigned char is_prime[Max];

    /* Initialize Array */
    for (i = 0; i < Max; i++)
      is_prime[i] = 1;

    for (i = 2; i < Max; ++i)
      for (j = 2 * i; j < Max; j = j + i)
        is_prime[j] = 0;

    printf("Prime numbers are: ");
    for (i = 2; i < Max; i++)
      if (is_prime[i] > 0)
        printf("%d ", i);
  }
}
