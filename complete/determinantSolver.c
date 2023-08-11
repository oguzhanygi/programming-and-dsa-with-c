/* This program solves the determinant of a given matrix.
It uses Cramer's method. */

#include <math.h>
#include <stdio.h>

int getSize(void);
void getElements(int size, double arr[size][size]);
double determinant(size_t size, double arr[size][size]);

int main(void) {

  puts("This program calculates the determinant of a given matrix.");

  int size = getSize();

  double arr[size][size];

  getElements(size, arr);

  printf("Determinant of the given matrix is: %f\n", determinant(size, arr));
}

int getSize(void) {
  int size, loop = 1;

  while (loop) {
    printf("%s", "Please enter the size of the matrix: ");
    scanf("%d", &size);
    if (size < 2)
      puts("You did not enter a valid size. Please enter a valid size.\a");
    else
      loop = 0;
  }
  return size;
}

void getElements(int size, double arr[][size]) {
  puts("Please enter the elements of the matrix.");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("Enter the element for row %d, column %d: ", i + 1, j + 1);
      scanf("%lf", &arr[i][j]);
    }
    puts("");
  }
}

double determinant(size_t size, double arr[size][size]) {
  if (size == 2) {
    return arr[0][0] * arr[1][1] - arr[1][0] * arr[0][1];
  } else {
    double sum = 0;
    for (size_t i = 0; i < size; i++) {
      double tempArr[size - 1][size - 1];
      for (size_t j = 0; j < size - 1; j++) {
        for (size_t k = 0, l = 0; k < size - 1; k++, l++) {
          if (l == i)
            k--;
          else
            tempArr[j][k] = arr[j + 1][l];
        }
      }
      sum = sum + pow(-1, i) * arr[0][i] * determinant(size - 1, tempArr);
    }
    return sum;
  }
}
