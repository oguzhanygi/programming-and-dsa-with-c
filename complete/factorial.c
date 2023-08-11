/* This program calculates a given
 * number's factorial. */

#include "stdio.h"

int main(void) {

  unsigned int number = 1;
  unsigned int result = 1;

  printf("%s", "Enter a positive number: ");
  scanf("%u", &number);

  while (number > 1) {
    result = result * number;
    --number;
  }

  printf("Factorial of the given number is: %u\n", result);
}
