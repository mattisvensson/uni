/* pointers.c
   TO DO 1:  Extend/modify the address_list.c program such that the student data is not stored 
             in a global but in local data structures in main.
   TO DO 2:  Use pointers/call by reference to pass student data to the different functions.    
   TO DO 3:  use typedef to define a type for 'struct person' and use this type
   
   Some code snippets are given below.  
*/

#include <stdio.h>

typedef struct {
  char first_name[100];
  char last_name[100];
} person;

void print_student(int *s)
{     
  // printf("%s", s->first_name);

  // printf("%s", (*s).first_name );
  // // as the notation (*s).firstname is somewhat clumsy, there is a special operator for this frequently used * . operation:
  // printf("%s", s->first_name );

}

int main()
{

  person students[4];

  // // students[0].first_name = "Max"; 

  // strcpy(students[0].first_name, "Max");
  // strcpy(students[0].last_name, "Mustermann");

  // strcpy(students[1].first_name, "Moritz");
  // strcpy(students[1].last_name, "Musterfrau");

  // strcpy(students[2].first_name, "Klaus");
  // strcpy(students[2].last_name, "Kleber");

  // strcpy(students[3].first_name, "Robert");
  // strcpy(students[3].last_name, "Redford");

  // for (int i = 0; i < 4; i++) {
  //   // printf("%p", &students[i]);
  //   print_student(&students[i]);
  //   // // or simpler:
  //   // print_student(students+i);      // Note, that this addition of i to a pointer is special as it considers the size of type pointed to
  // }

}
 

   

