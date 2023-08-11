// This program implements a linear search algorithm.

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int linearSearch(int arr[], int size, int findThis);

int main(void) {
  srand(time(NULL));

  int arr[SIZE] = {};
  int findThis;

  for (size_t i = 0; i < SIZE; i++) {
    arr[i] = rand() % 100;
  }

  for (size_t i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  puts("");

  printf("Search for an element: ");
  scanf("%d", &findThis);

  int result = linearSearch(arr, SIZE, findThis);
  if (result == -1)
    printf("%s", "Not found.\n");
  else
    printf("It is at index %d.\n", result);
}

int linearSearch(int arr[], int size, int findThis) {
  for (size_t i = 0; i < size; i++) {
    if (arr[i] == findThis)
      return i;
  }
  return -1;
}
