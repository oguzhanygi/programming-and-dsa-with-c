/* This program demonstrates the usage of
 * ternary operator aka elvis operator */

#include <stdio.h>

int main(void) {

  int a = 1;
  int b = 2;
  int c;

  if (a + b == 3) {
    c = a;
  } else {
    c = b;
  }

  // This is the same thing as above.
  c = a + b == 3 ? a : b;

  // variable = [condition] ? [assign this if true] : [assign this if false];
}
