/* This program sorts an array of integers
 * using selection sort algorithm. */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void selectionSort(int arr[], int size);
void swap(int arr[], int indexA, int indexB);

int main(void) {
  srand(time(NULL));
  int arr[SIZE] = {};

  for (size_t i = 0; i < SIZE; i++) {
    arr[i] = rand() % (2 * SIZE);
  }

  puts("Elements before selection sort: ");
  for (size_t i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  puts("");

  selectionSort(arr, SIZE);

  puts("Elements after selection sort: ");
  for (size_t i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  puts("");
}

void swap(int arr[], int indexA, int indexB) {
  int temp;
  temp = arr[indexA];
  arr[indexA] = arr[indexB];
  arr[indexB] = temp;
}

void selectionSort(int arr[], int size) {
  int smallest;
  int indexOfSmallest;

  for (size_t i = 0; i < size; i++) {
    smallest = arr[i];
    indexOfSmallest = i;
    for (size_t j = i + 1; j < size; j++) {
      if (smallest > arr[j]) {
        smallest = arr[j];
        indexOfSmallest = j;
      }
    }
    swap(arr, i, indexOfSmallest);
  }
}
