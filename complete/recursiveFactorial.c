/* This program implements a recursive
 * factorial function. */

#include <stdio.h>

unsigned int factorial(unsigned int number) {
  if (number > 1)
    return number * factorial(number - 1);
  else
    return 1;
}

int main(void) {

  unsigned int number = 0;
  printf("%s", "Enter a number: ");
  scanf("%u", &number);

  printf("Factorial of the given number is: %u\n", factorial(number));
}
