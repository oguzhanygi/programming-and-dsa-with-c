/* This program demonstrates the use of binary
search algorithm */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int binarySearch(int arr[], int start, int end, int findThis);

int main(void) {
  srand(time(NULL));

  int arr[SIZE] = {};
  int value = 0;
  int findThis;
  int result = -1;

  // Fill the array with ordered random numbers
  for (size_t i = 0; i < SIZE; i++) {
    arr[i] = value + 1 + rand() % 9;
    value = arr[i];
  }

  // Print the elements
  for (size_t i = 0; i < SIZE; i++) {
    printf("%zu-\t%d\n", i, arr[i]);
  }
  puts("");

  // Which number to look at it's index
  printf("%s", "Which number are you looking for: ");
  scanf("%d", &findThis);

  result = binarySearch(arr, 0, SIZE - 1, findThis);

  if (result == -1)
    puts("Not found.");
  else
    printf("Searched elements is at index %d.\n", result);
}



int binarySearch(int arr[], int start, int end, int findThis) {

  if (start > end || findThis > arr[end] || findThis < arr[start])
    return -1;

  int midIndex = (end + start) / 2;

  if (findThis == arr[midIndex]) {
    return midIndex;
  } else if (findThis > arr[midIndex]) {
    return binarySearch(arr, midIndex + 1, end, findThis);
  } else {
    return binarySearch(arr, start, midIndex - 1, findThis);
  }
}