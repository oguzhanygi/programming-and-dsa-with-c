/* This program reads two integer values,
 * and displays their sum, product, difference,
 * quotient and remainder.
 */

#include <stdio.h>

int main(void) {

  int a, b;

  printf("%s", "Enter the first integer: ");
  scanf("%d", &a);

  printf("%s", "Enter the second integer: ");
  scanf("%d", &b);

  printf("Their sum: %d\n", a + b);
  printf("Their product: %d\n", a * b);
  printf("Their difference: %d\n", a - b);
  printf("Their quotient: %d\n", a / b);
  printf("Their remainder: %d\n", a % b);
}
