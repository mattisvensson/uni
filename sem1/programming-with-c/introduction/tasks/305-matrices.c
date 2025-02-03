/* matrices */
// TO DO 1: Extend the programm such that the result is printed
// TO DO 2: Extend the programm such that it also calculates the product of the two 3x3 matrices.
// TO DO 3: What happens when you make a mistake with the indices, e.g. read/write m1[3][0], m1[4][0], m1[0][4] etc.?

#include <stdio.h>

int main()
{
  float m1[3][3] = {
    {12, 5.3, 10.0}, 
    {5, 10.2, -2}, 
    {1, -1, 3}
  };
  float m2[3][3] = {
    {2.1, -3, 1.5}, 
    {10, -12, 3.1}, 
    {4, 8.2, -2}
  };
  float sum[3][3];
  float product[3][3];

  int i, j;

  for (i = 0; i < 3; i = i + 1)
    for (j = 0; j < 3; j = j + 1)
      sum[i][j] = m1[i][j] + m2[i][j];


  // function matmult(A,B,l,m,n)
  //   C = zeroes(l,n)                         // Ergebnismatrix C mit Nullen initialisieren
  //   for i = 1 to l                          // Schleife über die Zeilen von C
  //     for k = 1 to n                        // Schleife über die Spalten von C
  //       for j = 1 to m                      // Schleife über die Spalten von A / Zeilen von B
  //         C(i,k) = C(i,k) + A(i,j) * B(j,k) // Bildung der Produktsumme
  //       end
  //     end
  //   end
  //   return C

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      product[i][j] = 0;
      for (int k = 0; k < 3; k++) {
        product[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }

  printf("Sum:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++)
      printf("%6.2f ", sum[i][j]);
    printf("\n");
  }

  printf("Product:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++)
      printf("%6.2f ", product[i][j]);
    printf("\n");
  }
}