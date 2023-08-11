/* This program generates 15 random numbers and
* stores them inside an array. After that it will
* reverse-order the array elements using pointers.
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main() {

  srand(time(NULL));

  int arr[SIZE] = {};

  for (size_t i = 0; i < SIZE; i++) {
    arr[i] = rand() % 100;
  }

  puts("Before reverse: ");

  // print array before reversing
  for (size_t i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  puts("");

  int *ptrA = arr;
  int temp = 0;

  // swap array elements using pointers
  for (size_t i = 0; i < SIZE / 2; i++) {
    temp = *(ptrA + i);
    *(ptrA + i) = *(ptrA + SIZE - 1 - i);
    *(ptrA + SIZE - 1 - i) = temp;
  }

  puts("After reverse: ");

  // print array after reversing
  for (size_t i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  puts("");
}
