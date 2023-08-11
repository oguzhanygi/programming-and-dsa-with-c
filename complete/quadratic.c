// This program finds roots of quadratic equations.

#include <math.h>
#include <stdio.h>

float delta(float a, float b, float c) { return b * b - 4 * a * c; }

void findRoots(float a, float b, float c) {
  if (delta(a, b, c) < 0) {
    puts("Equation does not have real roots.");
    return;
  } else {
    float x1 = (-b + sqrt(delta(a, b, c))) / (2 * a);
    float x2 = (-b - sqrt(delta(a, b, c))) / (2 * a);
    printf("First root is equal to: %.3f\n", x1);
    printf("Second root is equal to: %.3f\n", x2);
  }
}

int main(void) {
  float a, b, c;
  puts("Enter the coefficient (a, b, c) by this order: ax^2 + bx + c = 0");
  printf("%s", "Enter a: ");
  scanf("%f", &a);
  printf("%s", "Enter b: ");
  scanf("%f", &b);
  printf("%s", "Enter c: ");
  scanf("%f", &c);
  findRoots(a, b, c);
}
