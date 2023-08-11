#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {

  srand(time(NULL));

  char arr[SIZE] = {};

  for (size_t i = 0; i < SIZE; i++) {
    arr[i] = 97 + rand() % 26;
  }

  for (size_t i = 0; i < SIZE; i++) {
    printf("%c", arr[i]);
  }
  puts("");

  char *ptrA = arr;
  char temp;

  for (size_t i = 0; i < SIZE / 2; i++) {
    temp = *(ptrA + i);
    *(ptrA + i) = *(ptrA + SIZE - 1 - i);
    *(ptrA + SIZE - 1 - i) = temp;
  }

  for (size_t i = 0; i < SIZE; i++) {
    printf("%c", arr[i]);
  }
  puts("");
}
