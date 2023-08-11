/* This program finds greatest common divisor of
 * two numbers with a recursive function using
 * euclidean algortithm. */

#include <stdio.h>

unsigned int gcd(unsigned int x, unsigned int y) {

  // either x or y should be 0 (see euclidean algorithm)
  if (x == 0 || y == 0) {
    if (x)
      return x; // if x is nonzero, it is the gcd
    if (y)
      return y; // if y is nonzero, it is the gcd
    else
      return 0; // if both numbers are 0, gcd is 0
  }
  if (x > y) {
    gcd(y, x % y);
  } else {
    gcd(x, y % x);
  }
}

int main(void) {

  unsigned int x = 0, y = 0;

  printf("%s", "Enter the first number: ");
  scanf("%u", &x);

  printf("%s", "Enter the second number: ");
  scanf("%u", &y);

  printf("Greatest common divisor of %u and %u is: %u\n", x, y, gcd(x, y));
}
