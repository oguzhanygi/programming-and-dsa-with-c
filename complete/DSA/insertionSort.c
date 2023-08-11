#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void insertionSort(int arr[], int size);
void swap(int arr[], int i, int j);

int main(void) {

  srand(time(NULL));

  int arr[SIZE] = {};

  for (size_t i = 0; i < SIZE; i++) {
    arr[i] = rand() % (2 * SIZE);
  }

  for (size_t i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  puts("");

  insertionSort(arr, SIZE);

  for (size_t i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  puts("");
}

void swap(int arr[], int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void insertionSort(int arr[], int size) {

  int scanBack;

  for (size_t i = 0; i < size - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      swap(arr, i, i + 1);
    }
    scanBack = i;
    while (scanBack > 0) {
      if (arr[scanBack] < arr[scanBack - 1]) {
        swap(arr, scanBack, scanBack - 1);
      }
      scanBack--;
    }
  }
}
