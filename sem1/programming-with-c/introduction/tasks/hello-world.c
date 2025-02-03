#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *getMemory(int n);

void aufgabe2() {
    for (int i = 0; i < 6; i++)
  {
    int count = 0;
    for (int j = 0; count < 50; j++)
    {

      printf("%d", j % 10); 
      count++;

      if (count < 50) {
        for(int k = 0; k < i; k++) {
          if (count < 50) {
            printf("-");
            count++;
          }
        }
      }
    }
    printf("\n");
  }
}

void aufgabe3b() {
  char str1[] = "Dasisteinstring";

  int run = 1;
  int idx = 0;
  while(run) {
    if (str1[idx] == 0) {
      run = 0;
    } else {
      idx++;
    };
  }

  printf("%d", idx);
}

void aufgabe4() {
  struct person {
    char name[30];
    int age;
  };

  struct person arr[10];

  for(int i = 0; i < 10; i++) {
    strcpy(arr[i].name, "Nicole");
    arr[i].age = i * 10;
  }

  for(int i = 0; i < 10; i++) {
    printf("Person %d: Name = %s, Age = %d\n", i, arr[i].name, arr[i].age);
  }
}

//Aufgabe 5
// (a) Definieren Sie einen Datentypen namens t_mytype.
// (b) Schreiben Sie eine Funktion getmemory(int n), die Speicherplatz für n Werte vom Typ t_mytype
// reserviert und einen Zeiger zurückgibt.
// (c) Schreiben Sie eine Funktion, die getmemory und usememory (nicht zu implementieren) verwendet.
// Beachten Sie die Abfragen und Aufräumarbeiten.
// (d) Ändern Sie die Funktion in (b) derartig, dass Speicher für Zeiger auf den Datentyp zurückgegeben
// wird.

typedef int t_mytype;

void aufgabe5() {
  t_mytype *a = getMemory(5);
  printf("%p", a);
}

t_mytype* getMemory(int n) {
  t_mytype *ptr = malloc(n * sizeof(t_mytype));

  if (ptr == NULL) {
    perror("Error");
  } else {
    return ptr;
  }
}






typedef struct {
  float data;
  item *ptr;
} item;

item arr[10];


item getMin(){

}


void aufgabe6() {

}














// Aufgabe A
// Schreiben Sie eine Funktion, die einen Wert n übergeben bekommt, Speicher für n float-Werte reserviert und diese mit 2.0, 4.0, 6.0 usw. initialisiert.
// void a(int n) {

//   for(int i = 0; i <= n; i++) {
//     float *ptr = malloc(sizeof(float));

//     if (ptr != NULL) {
//       *ptr = i * 2;
//     }
//   }
// }

// struct mydata {
//   int a; 
//   char b; 
//   char c;
// };
// void swap(char one, char two, struct mydata *data) {
  
// }


int main() {
  // aufgabe2();
  // aufgabe3b();
  // aufgabe4();
  // aufgabe5();
  // aufgabe6();


  for(int i = 1; i < 6; i++) {
    int start = i;
    for(int j = 1; j < 10; j++) {
      for(int k = 0; k < j; k++) {
        printf("%d", start % 10);
      }
      if (j < 9) {
        printf("-");
      }
      start++;
    }
    printf("\n");
  }
  
  return 0;
}