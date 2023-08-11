/* This program compares six differrent sorting algorithms.
 *  Those six algorithms are:
 *  Bubble Sort
 *  Selection Sort
 *  Quick Sort
 *  Merge Sort
 *  Heap Sort
 *  Insertion Sort
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// function prototypes
int getSize();
void fillWithRandomNum(int arr[], int size);
void printArray(int arr[], int size);
void swap(int *ptr, int *ptr2);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);

// driver function 'main'
int main(void) {

  // random seed based on current time
  srand(time(NULL));

  // array size
  int size = getSize();
  // empty array
  int arr[size];
  // user's selected algorithm
  int selection = 0;
  // answer of the user if he/she wants to print the array
  char yesNo;
  // elapsed time while running the selected algorithm
  double timeSpent = 0.0;

  // filling the array with random numbers
  fillWithRandomNum(arr, size);

  // asks user to select an algorithm
  puts("1- Bubble Sort\t\t2- Selection Sort");
  puts("3- Insertion Sort\t4- Merge Sort");
  puts("Please Select an algorithm from above: ");
  scanf("%d", &selection);

  // asks user to print the array if he/she wants
  puts("The array is generated.");
  puts("Would you like to print the elements?");
  puts("Enter 'y' for yes, or 'n' for no: ");
  scanf(" %c", &yesNo);
  if (yesNo == 'y' || yesNo == 'Y') {
    printArray(arr, size);
  }

  // starts clock
  clock_t begin = clock();

  // calls the function for the selected algorithm
  switch (selection) {

  case 1:
    bubbleSort(arr, size);
    break;
  case 2:
    selectionSort(arr, size);
    break;
  case 3:
    insertionSort(arr, size);

  default:
    break;
  }

  // stops clock
  clock_t end = clock();

  // elapsed time while running the selected algorithm
  timeSpent += (double)(end - begin) / CLOCKS_PER_SEC;

  // prints the elapsed time
  printf("Spent time for the selected algorithm is equal to: %f\n", timeSpent);

  puts("The array is sorted.");
  puts("Would you like to print the elements?");
  puts("Enter 'y' for yes, or 'n' for no: ");
  scanf(" %c", &yesNo);
  if (yesNo == 'y' || yesNo == 'Y') {
    printArray(arr, size);
  }
}

// gets the size of array from the user
int getSize() {

  int size;

  puts("Enter the desired number for the element amount: ");
  scanf("%d", &size);

  return size;
}

// fills the array with random numbers
void fillWithRandomNum(int arr[], int size) {

  for (size_t i = 0; i < size; i++) {
    arr[i] = rand() % 15;
  }
}

// prints all the elements
void printArray(int arr[], int size) {

  for (size_t i = 0; i < size; i++) {

    printf("%d ", arr[i]);
  }

  puts("");
}

// swaps two elements
void swap(int *ptr1, int *ptr2) {

  int temp;

  temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}

// bubble sort
void bubbleSort(int arr[], int size) {

  for (size_t j = 0; j < size - 1; j++) {

    for (size_t i = 0; i < size - j - 1; i++) {

      if (arr[i] > arr[i + 1]) {

        swap(arr + i, arr + i + 1);
      }
    }
  }
}

// selection sort
void selectionSort(int arr[], int size) {

  int lowest = __INT_MAX__;
  int indexOfLowest = 0;

  for (size_t j = 0; j < size; j++) {

    for (size_t i = j; i < size; i++) {

      if (arr[i] < lowest) {
        lowest = arr[i];
        indexOfLowest = i;
      }
    }

    swap(arr + j, arr + indexOfLowest);
    lowest = __INT_MAX__;
  }
}

void insertionSort(int arr[], int size) {

  int scanBack = 0;

  for (size_t i = 0; i < size - 1; i++) {

    if (arr[i] > arr[i + 1]) {

      swap(arr + i, arr + i + 1);
    } else {
      continue;
    }
    scanBack = i;
    while (scanBack > 0) {

      if (arr[scanBack - 1] > arr[scanBack]) {

        swap(arr + scanBack, arr + scanBack - 1);
      } else {
        break;
      }
      scanBack--;
    }
  }
}

void mergeSort(int arr[], int left, int right) {
  // will be written
}
