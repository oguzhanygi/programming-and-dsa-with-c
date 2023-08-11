// This program demonstrates the features of pointers in C.

#include <stdio.h>

int main(void) {
  int x = 1;
  int *xPtr = &x;

  puts("xPtr is a pointer to x: ");
  printf("x = %d\n", x);
  printf("&x = %p\n", &x);
  printf("xPtr = %p\n", xPtr);
  printf("*xPtr = %d\n", *xPtr);
  puts("");

  int y = 2;
  int *yPtr = &y;

  puts("yPtr is a pointer to y: ");
  printf("y = %d\n", y);
  printf("&y = %p\n", &y);
  printf("yPtr = %p\n", yPtr);
  printf("*yPtr = %d\n", *yPtr);
  puts("");

  x = y;
  puts("After making x = y (Changing value of x): ");
  printf("x = %d,\ty = %d\n", x, y);
  printf("&x = %p,\t&y = %p\n", &x, &y);
  printf("xPtr = %p,\tyPtr = %p\n", xPtr, yPtr);
  printf("*xPtr = %d,\t\t*yPtr = %d\n", *xPtr, *yPtr);
  puts("");

  x = 1;
  puts("Changing back to x = 1 to not to confuse.");
  puts("");

  xPtr = yPtr;
  puts("After making xPtr = yPtr (Changing value at the address that xPtr "
       "points to): ");
  printf("x = %d,\ty = %d\n", x, y);
  printf("&x = %p,\t&y = %p\n", &x, &y);
  printf("xPtr = %p,\tyPtr = %p\n", xPtr, yPtr);
  printf("*xPtr = %d,\t\t*yPtr = %d\n", *xPtr, *yPtr);
}
