/* This program checks if a given number
 * is prime or not */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  unsigned int number = 0;

  printf("%s", "Enter a positive number: ");
  scanf("%u", &number);

  double time_spent = 0.0;
  clock_t begin = clock();

  int divider = number / 2;

  int stop = 0;

  int result;

  while (stop == 0) {

    if (number < 2) {
      printf("%s", "The number is not a prime.\n");
      break;
    }

    result = number / divider;

    if (number == result * divider && number != 2) {
      printf("%s", "The number is not a prime.\n");
      stop = 1;
    } else if (divider % 2 == 0) {
      divider = divider - 1;
    } else {
      divider = divider - 2;
    }
    if (divider < 2) {
      stop = 1;
    }
  }

  if (divider < 2 || number == 2) {
    if (stop == 1) {
      printf("%s", "The number is a prime.\n");
    }
  }

  clock_t end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("The elapsed time is %f seconds\n", time_spent);
}
