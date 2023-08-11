// This program prints a diamond shape.

#include <stdio.h>

int main(void) {

  unsigned int rowAmount;

  puts("Amount of rows will be equal to the closest odd number to have a "
       "symetric diamond.");
  printf("%s", "How many rows should the diamond have?: ");
  scanf("%u", &rowAmount);

  int spaces = rowAmount / 2;

  // first half of the diamond
  for (int i = 0; i < rowAmount / 2; i++) {

    // amount of spaces
    for (int j = 0; j < spaces; j++) {
      printf("%s", " ");
    }

    // amount of stars
    for (int k = 0; k <= i; k++) {
      printf("%s", "* ");
    }
    puts("");

    // it should decrease when the amount of stars increase
    spaces--;
  }

  // second half of the diamond
  for (int i = rowAmount / 2; i >= 0; i--) {

    // amount of spaces
    for (int j = spaces; j > 0; j--) {
      printf("%s", " ");
    }

    // amount of stars
    for (int k = i; k >= 0; k--) {
      printf("%s", "* ");
    }
    puts("");

    // it should increase when the amount of stars decrease
    spaces++;
  }
}
