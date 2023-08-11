/* This program is an excersise for tabular
 * output in C. */

#include <stdio.h>

int main(void) {

  int n = 1;

  printf("N\tN^2\tN^3\tN^4\n");

  while (n < 11) {

    printf("%d\t%d\t%d\t%d\n", n, n * n, n * n * n, n * n * n * n);
    n++;
  }
}
