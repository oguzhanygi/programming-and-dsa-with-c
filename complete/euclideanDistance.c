/* This program demonstrates the use of structs with coordinates of
a point in 2D euclidean space. It also calculates the distance
between two points. */

#include <math.h>
#include <stdio.h>

typedef struct point {
  double x;
  double y;
} Point;

double distance(Point p1, Point p2);

int main(void) {
  Point point1 = {}, point2 = {};

  printf("%s", "Enter x for the first point: ");
  scanf("%lf", &point1.x);
  printf("%s", "Enter y for the first point: ");
  scanf("%lf", &point1.y);
  printf("%s", "Enter x for the second point: ");
  scanf("%lf", &point2.x);
  printf("%s", "Enter x for the second point: ");
  scanf("%lf", &point2.y);

  printf("Distance between these two points is %.3f\n",
         distance(point1, point2));
}

double distance(Point p1, Point p2) {
  return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}
