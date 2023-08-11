/* This program demonstrates integer overflow. */

#include <limits.h>
#include <stdio.h>

int main(void) {
  printf("max signed int: INT_MAX = %d\n", INT_MAX);
  puts("If we add + 1 to this value, the value gets outside of the range.");
  puts("This makes the new value equal to smallest integer value "
       "(INT_MIN).");
  printf("INT_MAX + 1 = %d\n", INT_MAX + 1);
  printf("INT_MIN = %d\n", INT_MIN);
}
