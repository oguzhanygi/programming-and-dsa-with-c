/* This program prints ascii characters and their
 * integer values between 32-128. */

#include <stdio.h>

int main(void) {

  puts("Skipping unprintable characters...");
  for (int i = 33; i < 127; i++) {
    printf("%d %c\t", i, i);
    if (i % 10 == 2) {
      puts("");
    }
  }
  puts("");
}
