/* This program compares preincrementing and
 * postincrementing in C */

#include "stdio.h"

int main(void) {

  int number = 10;

  printf("(number) Number BEFORE preincrementing = %d\n", number);
  printf("(++number) Number DURING preincrementing = %d\n", ++number);
  printf("(number) Number AFTER preincrementing = %d\n", number);

  printf("\n");

  printf("(number) Number BEFORE postincrementing = %d\n", number);
  printf("(number++) Number DURING postincrementing = %d\n", number++);
  printf("(number) Number AFTER postincrementing = %d\n", number);
}
