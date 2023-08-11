// This program prints nth term of fibonacci series

#include <stdio.h>

unsigned int getNumber(void);
unsigned int fibonacci(unsigned int n);

int main(void) {
  unsigned int number = getNumber();
  printf("Term %u is equal to: %u\n", number, fibonacci(number));
}

unsigned int getNumber(void) {
  unsigned int n = 0;
  printf("%s", "Which term do you want to find?: ");
  scanf("%u", &n);
  return n;
}

unsigned int fibonacci(unsigned int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return fibonacci(n - 1) + fibonacci(n - 2);
}
