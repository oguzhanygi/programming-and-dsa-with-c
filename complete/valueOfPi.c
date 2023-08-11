/* This program estimates value of pi.
 * You'll need to enter realy big numbers
 * to get a more accurate result. */

#include <stdio.h>

int main(void) {

  long double pi = 0.0;

  unsigned int precision = 0;

  printf("Enter the desired precision: ");
  scanf("%u", &precision);

  printf("%s", "Some of first n term(s)\t\tValue\n");
  for (int i = 0; i < precision; i++) {
    if ((2 * i + 1) % 4 == 1) {
      pi = pi + 4.0 / (2 * i + 1);
    } else {
      pi = pi - 4.0 / (2 * i + 1);
    }
    printf("%d\t\t\t\t%.10Lf\n", i + 1, pi);
  }
}
