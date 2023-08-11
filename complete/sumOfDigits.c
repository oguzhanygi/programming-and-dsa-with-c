/* This program takes a 4-digit number as an input and prints
 * sum of individual digits of given number. */

#include <stdio.h>

int main(void) {

  int number = 0;

  printf("%s", "Please enter a 4-digit number: ");
  scanf("%d", &number);

  int digit1 = number / 1000;

  // change the number's value so we can ignore previous digit.
  number = number % 1000;

  int digit2 = number / 100;

  number = number % 100;

  int digit3 = number / 10;

  // since it is a two digit number, remainder is equal to last digit.
  int digit4 = number % 10;

  int sumOfDigits = digit1 + digit2 + digit3 + digit4;

  printf("Some of the givent number's digits is: %d\n", sumOfDigits);
}
