/* This program calculates annual interest
 * for several loans. */

#include <stdio.h>

int main(void) {

  float principal, rate;
  unsigned int days;

  while (principal != -1) {

    printf("Enter loan principal (-1 to end): ");
    scanf("%f", &principal);

    if (principal != -1) {

      printf("Enter interest rate: ");
      scanf("%f", &rate);

      printf("Enter term of the loan in days: ");
      scanf("%u", &days);

      float interest = principal * rate * days / 365;
      printf("The interest charge is: $%.2f\n", interest);
    }
  }
}
