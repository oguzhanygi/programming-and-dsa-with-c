/* This program calculates final velocity
 * and distance traversed. */

#include <stdio.h>

int main(void) {

  /* assume initial velocity, acceleration, and
   * elapsed time equal to 0 */
  int u = 0, a = 0, t = 0;

  printf("%s", "Enter the initial velocity: ");
  scanf("%d", &u);

  printf("%s", "Enter the acceleration: ");
  scanf("%d", &a);

  printf("%s", "Enter the time that has elapsed: ");
  scanf("%d", &t);

  // final velocity
  int finalV = u + a * t;

  // distance traversed
  int distanceT = u * t + ((a * t * t) / 2);

  printf("Final velocity = %d\n", finalV);
  printf("Distance traversed = %d\n", distanceT);
}
