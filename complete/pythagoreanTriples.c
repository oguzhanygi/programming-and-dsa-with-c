/* This program lists all the pythgorean triples
 * that it's any side is no larger than 50.
 * It is an example of "brute-force" computing */

#include <stdio.h>

int main(void) {

  int hypotenuseSquared = 0;

  printf("%s", "SIDE-1\tSIDE-2\tHYPOTENUSE\n");
  for (int side1 = 1; side1 <= 50; side1++) {
    for (int side2 = 1; side2 <= 50; side2++) {
      hypotenuseSquared = side1 * side1 + side2 * side2;
      for (int hypotenuse = 1; hypotenuse <= 50; hypotenuse++) {
        if (hypotenuse * hypotenuse == hypotenuseSquared) {
          printf("%d\t%d\t%d\n", side1, side2, hypotenuse);
        }
      }
    }
  }
}
