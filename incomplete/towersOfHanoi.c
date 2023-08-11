/* This program solves towers of hanoi problem. */

#include <stddef.h>
#include <stdio.h>

#define SIZE 5

void swap(int *ptr1, int *ptr2);

int main(void) {
  int tower1[SIZE] = {5, 4, 3, 2, 1};
  int tower2[SIZE] = {};
  int tower3[SIZE] = {};

  for (size_t i = 0; i < SIZE; i++) {
    printf("%d ", tower1[i]);
  }
  puts("");

  for (size_t i = 0; i < SIZE; i++) {
    printf("%d ", tower2[i]);
  }
  puts("");

  for (size_t i = 0; i < SIZE; i++) {
    printf("%d ", tower3[i]);
  }
  puts("");
}

void swap(int *ptr1, int *ptr2) {
  int temp;
  temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}

void hanoi(int tower1[], int tower2[], int tower3[], int size) {
  int i = size - 1;
  int j = 0;
  int k = 0;
  while (j < size && k < size) {
    if (tower2[j] == 0 && tower2[j - 1] < tower1[i]) {
      swap(tower2 + j, tower1 + i);
      i--;
    }
    j++;
    if (tower3[k] == 0 && tower3[k - 1] < tower1[i]) {
      swap(tower3 + k, tower1 + i);
      i--;
    }
    k++;
  }
}
