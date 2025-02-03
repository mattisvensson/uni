/* bitwise_operators.c binary operations */
/* TO DO 1: Something is wrong with the output 
	  Hint: put the output first into an additional variable m, 
	  use bitwise operators and count the digits */
/* TO DO 2: A second number should be entered and 
	  both numbers should be combined with the various bitwise
	  operators before providing the output */
/* TO DO 3: Use signed integers and see how negative numbers 
    are presented in binary format */

#include <stdio.h>

void Todo1();
void Todo2();
void Todo3();

int main() 
{
  // Todo1();
  // Todo2();
  Todo3();
}

void Todo1() {
  unsigned int n, m, size;

  printf("\n\n\nTODO 1:\n");
	printf("Please enter an integer number:");
	scanf("%u",&n);
	
  printf("\nBinary representation: ");

  m = n;
  size = n;
  
	while(n>0) {
    m = m << 1;    
    m = m | (n&1);
    n = n >> 1;
	}

  do {
    printf("%d", m&1);
    m>>=1;
    size>>=1;
  } while (size > 0);
}

void Todo2() {
  unsigned int a, b;

  printf("\n\n\nTODO 2:\n");
  printf("Please enter an integer number:");
  scanf("%u",&a);
  printf("Please enter another integer number:");
  scanf("%u",&b);


  printf("a = %u, b = %u\n", a, b);
  printf("a&b = %u\n", a & b);
}

void Todo3() {
  unsigned int n, m, size;

  printf("\n\n\nTODO 3:\n");
	printf("Please enter an integer number:");
	scanf("%u",&n);

  n = -n;
	
  printf("\nBinary representation: ");

  m = n;
  size = n;
  
	while(n>0) {
    printf("%u", n&1);
    n = n >> 1;
	}
	// while(n>0) {
  //   m = m << 1;    
  //   m = m | (n&1);
  //   n = n >> 1;
	// }

  // do {
  //   printf("%d", m&1);
  //   m>>=1;
  //   size>>=1;
  // } while (size > 0);
}