/* This program calculates a circle's circumference
 * and area. */

#include <stdio.h>

#define PI 3.14159

int main(void) {

  double radius = 0.0;

  printf("%s", "Enter the radius of the circle: ");
  scanf("%lf", &radius);

  double area = PI * radius * radius;
  double circumference = 2 * PI * radius;

  printf("Area of the circle: %.5lf\n", area);
  printf("Circumference of the circle: %.5lf\n", circumference);
}
