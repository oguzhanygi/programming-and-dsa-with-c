/* This program prints first 10 lines
 * of Floyd's Triangle. */

#include <stdio.h>

int main(void) {

  // start number from 1
  int number = 1;

  // element amount in the first row
  int elementAmount = 1;

  // tracks which line the program currently on
  int lineAmount = 1;

  // keep printing until 11th line
  while (lineAmount < 11) {
    printf("%d ", number++);
    /* switch to new line only if element amount is equal to which line the
     * program is currently on */
    if (elementAmount == lineAmount) {
      puts("");
      lineAmount++;
      elementAmount = 0;
    }
    elementAmount++;
  }
}
