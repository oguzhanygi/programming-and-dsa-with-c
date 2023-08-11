/* This program sorts an array of integers
 * using bubble sort algorithm. */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void bubbleSort(int arr[], int size);
void swap(int arr[], int indexA, int indexB);

int main(void) {

  // seed random number generator with current time
  srand(time(NULL));

  // initialize array with zeros
  int arr[SIZE] = {};

  // fill array with random integers
  for (size_t i = 0; i < SIZE; i++) {
    arr[i] = rand() % (2 * SIZE);
  }

  // print the elements before sorting
  puts("Elements before bubble sort: ");
  for (size_t i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  puts("");

  // sort the array
  bubbleSort(arr, SIZE);

  // print the elements after sorting
  puts("Elements after bubble sort: ");
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

void bubbleSort(int arr[], int size) {
  for (size_t i = 0; i < size - 1; i++) {
    for (size_t j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr, j, j + 1);
      }
    }
  }
}
