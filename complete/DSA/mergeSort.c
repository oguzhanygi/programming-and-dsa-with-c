#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void mergeSort(int arr[], int start, int end);
void merge(int arr[], int start, int mid, int end);

int main(void) {
  srand(time(NULL));
  int arr[SIZE] = {};

  for (size_t i = 0; i < SIZE; i++) {
    arr[i] = rand() % (2 * SIZE);
  }

  printf("%s", "Before merge sort: ");
  for (size_t i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  puts("");

  mergeSort(arr, 0, SIZE - 1);

  printf("%s", "After merge sort: ");
  for (size_t i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  puts("");
}

void mergeSort(int arr[], int start, int end) {
  int mid = start + (end - start) / 2;
  if (start >= end)
    return;
  mergeSort(arr, start, mid);
  mergeSort(arr, mid + 1, end);
  merge(arr, start, mid, end);
}

void merge(int arr[], int start, int mid, int end) {

  if (start >= end)
    return;

  int l = mid - start + 1;
  int r = end - mid;

  int lArr[l] = {};
  int rArr[r] = {};

  for (size_t i = 0; i < l; i++) {
    lArr[i] = arr[start + i];
  }

  for (size_t i = 0; i < r; i++) {
    rArr[i] = arr[mid + 1 + i];
  }

  size_t i = 0, j = 0, k = start;
  while (i < l && j < r) {
    if (lArr[i] <= rArr[j]) {
      arr[k] = lArr[i];
      i++;
    } else {
      arr[k] = rArr[j];
      j++;
    }
    k++;
  }

  while (i < l) {
    arr[k] = lArr[i];
    i++;
    k++;
  }

  while (j < r) {
    arr[k] = rArr[j];
    j++;
    k++;
  }
}
