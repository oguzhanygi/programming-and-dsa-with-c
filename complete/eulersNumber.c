/* This program estimates powers of euler's number
 * using Taylor's series. */

#include <stdio.h>

int main(void) {

  // exponent
  int x = 0;
  // nth element of sum (starting from 1)
  int index = 1;
  // using long doubles to have a more accurate result.
  long double numerator = 1.0;
  long double denominator = 1.0;
  // result
  long double sum = 1.0;

  printf("%s", "Enter the exponent of the number: ");
  scanf("%d", &x);

  while (index < 30) {
    numerator = numerator * x;
    denominator = denominator * index;
    sum = sum + numerator / denominator;
    index++;
  }

  printf("e^%d = %Lf\n", x, sum);
}
