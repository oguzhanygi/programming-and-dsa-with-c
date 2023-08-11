/* This program creates a new type to represent complex numbers using
structs. It also have a function to multiply two complex numbers */

#include <stdio.h>

typedef struct complexNum {
  double real;
  double imaginary;
} ComplexNum;

ComplexNum complexProduct(ComplexNum a, ComplexNum b);

int main(void) {
  ComplexNum number1 = {}, number2 = {};

  printf("Enter first numbers real part: ");
  scanf("%lf", &number1.real);
  printf("Enter first numbers imaginary part: ");
  scanf("%lf", &number1.imaginary);
  printf("Enter second numbers real part: ");
  scanf("%lf", &number2.real);
  printf("Enter second numbers imaginary part: ");
  scanf("%lf", &number2.imaginary);

  ComplexNum result = complexProduct(number1, number2);
  printf("The result is equal to %.2f %+.2f * i\n", result.real,
         result.imaginary);
}

ComplexNum complexProduct(ComplexNum a, ComplexNum b) {
  ComplexNum product;
  product.real = a.real * b.real - a.imaginary * b.imaginary;
  product.imaginary = a.real * b.imaginary + a.imaginary * b.real;
  return product;
}
