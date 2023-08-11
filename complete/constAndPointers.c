/* This program shows the difference between:
  const int *ptr
  int *const ptr
  const int *const ptr */

#include <stdio.h>

int main(void) {

  int x = 1;
  const int *xPtr = &x; // This won't let you modify x using xPtr
                        // Even though x is not a const
  *xPtr = *xPtr + 1;

  int y = 2;
  int z = 3;
  int *const yPtr = &y;
  *yPtr = z; // This is allowed, because it does not modify the address
  yPtr = &z; // This will throw an error, since yPtr is a const pointer

  const int q = 4;
  int *qPtr = &q; // This will make q modfiable using aPtr
                  // Even though q is a const
  *qPtr = *qPtr + 1;

  int r = 4;
  const int *const rPtr = &r; // This will make rPtr const AND won't let you
                              // modify the variable it points to.
  *rPtr = *rPtr + 1;
  rptr = &q;
}
