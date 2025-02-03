/* address_list.c */
// This program should be completed such that it maintains a list of students
// TO DO 1: Write a function inputStudent(int i), which allows the user to enter first name and last name and stores it at position i in the array.
// TO DO 2: Use a variable to count the number of students stored in the array.
// TO DO 3: Write a function printStudent(i), which prints student i stored in the array
// TO DO 4: Write functions addStudent(), for adding a student at the first free position, and printAllStudents() for printing all students stored.
// TO DO 5: Write a function menu(), which allows the user to select one of the actions
//            - add Student
//            - print all students
//            - quit program
// TO DO 6: Extend the student data and the corresponding functions with the gender male/female (using "enum").
// TO DO 7: Create a structure for handling dates (day, month, year) and use it for birth date, date of enrollment etc.
// TO DO 8: Extend the program such it also handles address information (street, number, zip-code and city).
// TO DO 9: optional: Add a function and menu item for deleting a selected student.
// TO DO 10: optional: Add a function to sort the data according to given criteria

#include <stdio.h>

typedef enum
{
  male,
  female,
  divers
} Gender;

char gender_strings[3][6] = {"male", "female", "divers"};

typedef struct
{
  int day;
  int month;
  int year;
} Date;

struct person
{
  int set;
  int id;
  char first_name[30];
  char last_name[30];
  Gender gender;
  Date birthday;
};

struct person students[100];

int student_count = 0;

void addStudent(int i)
{
  static int student_id = 0;
  int gender_int;
  printf("Enter first name: ");
  scanf("%s", students[i].first_name);
  printf("Enter last name: ");
  scanf("%s", students[i].last_name);
  printf("Enter the gender:\n[0] - Male\n[1] - Female\n[2] - Divers\nGender: ");
  scanf("%d", &gender_int);
  printf("Enter the day of birth: ");
  scanf("%d", &students[i].birthday.day);
  printf("Enter the month of birth: ");
  scanf("%d", &students[i].birthday.month);
  printf("Enter the year of birth: ");
  scanf("%d", &students[i].birthday.year);

  switch (gender_int)
  {
  case 0:
    students[i].gender = male;
    break;
  case 1:
    students[i].gender = female;
    break;

  default:
    students[i].gender = divers;
    break;
  }

  students[i].set = 1;
  students[i].id = student_id++;

  printf("\nStudent '%s %s' with id %d successfully added.", students[i].first_name, students[i].last_name, i);
}

void deleteStudent(int i) {
  students[i].set = 0;
}

void printStudent(int i)
{
  if (students[i].set) {
    printf("ID: %d\n", students[i].id);
    printf("Name: %s %s\n", students[i].first_name, students[i].last_name);
    printf("Gender: %s\n", gender_strings[students[i].gender]);
    printf("Birthday: %d.%d.%d\n", students[i].birthday.day, students[i].birthday.month, students[i].birthday.year);
  }
}

void printAllStudents()
{
  for (int i = 0; i < student_count; i++)
  {
    if (students[i].set) {
      printStudent(i);
      printf("\n----\n");
    }
  }
}

int menu()
{
  int selected = 0;

  printf("Menu:\n[1] - add student\n[2] - delete student\n[3] - show student\n[4] - show all students\n[0] - exit\n\nEnter action number: ");
  scanf("%d", &selected);

  return selected;
}

int main()
{
  while (1)
  {
    printf("\n\n----------------------\n\n");

    int action = menu();

    printf("\n\n----------------------\n\n");

    switch (action)
    {
    case 0:
      return 0;
      break;
    case 1:
      addStudent(student_count);
      student_count++;
      break;
    case 2:
      int del_id = 0;
      printf("Enter the student id you want to delete:");
      scanf("%d", &del_id);
      deleteStudent(del_id);
      break;
    case 3:
      int show_id = 0;
      printf("There are %d total entries.\n", student_count);
      printf("Enter the student id: ");
      scanf("%d", &show_id);
      printStudent(show_id);
      break;
    case 4:
      printAllStudents();
      break;

    default:
      break;
    }
  }
}