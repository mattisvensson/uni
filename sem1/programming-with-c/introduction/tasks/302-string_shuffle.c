/* Shuffles a string */
// TO DO 1: Extend the program such that spaces in the strings are not moved/shuffled.
// TO DO 2: Extend the program such that the first characters of names are not shuffled
//          (a name1 may consist of several parts separated by spaces).
// TO DO 3: Extend the program such that two names can be entered and shuffling happens between these two
// TO DO 4: How can a user make the program crash? What could be done against that problem?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char name1[100], name2[100], tmp1, tmp2;
  int i, p1, p2;

  printf("Please enter your name:\n");
  fgets(name1, 100, stdin); // Read max. 99 chars + space for 0-byte
  name1[strcspn(name1, "\n")] = '\0';
  
  printf("Please enter another name:\n");
  fgets(name2, 100, stdin); // Read max. 99 chars + space for 0-byte
  name2[strcspn(name2, "\n")] = '\0';
  
  // Safer alternatives, with some issues -> lecture:
  // scanf("%99[^\n]", name1);
  // fgets(name1, 100, stdin);  // ReadM max. 99 chars + space for 0-byte

  int n1len = strlen(name1);
  int n2len = strlen(name2);

  
  for (i = 0; i < n1len + n2len; i++)
  {

    p1 = rand() % n1len; // strlen counts the number of characters in the string
    p2 = rand() % n2len;

    if (
        name1[p1] == ' ' ||
        name2[p2] == ' ' ||
        !p1 ||
        !p2 ||
        name1[p1 - 1] == ' ' ||
        name2[p2 - 1] == ' ')
      continue;

    tmp1 = name1[p1];
    tmp2 = name2[p2];
    name1[p1] = tmp2;
    name2[p2] = tmp1;

    printf("Hello %s and %s\n", name1, name2);
  }
}