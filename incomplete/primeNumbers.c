#include <stdio.h>
#include <time.h>
#include <unistd.h>

unsigned int isPrime(unsigned long n);
void primeFactorization(unsigned long n);

int main(void) {

  int k;
  puts("1-Prime check\t2-Listing Primes");
  puts("");
  printf("What do you want to do? Please choose from above: ");
  scanf("%d", &k);

  if (k == 1) {
    unsigned long n;
    printf("\nEnter the number: ");
    scanf("%lu", &n);
    double time_spent = 0.0;
    clock_t begin = clock();
    if (isPrime(n) == 1)
      printf("\nThe number you entered is a prime number.\n");
    else if (isPrime(n) == 0 && n > 1) {
      printf("\nThe number you entered is not a prime number.\n");
      printf("\nPrime factors of the given number are: \n");
      primeFactorization(n);
    } else if (n < 1)
      printf("\nThe number you entered is not a prime number.\n");
    puts("");
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds\n", time_spent);
  } else if (k == 2) {
    unsigned long n, t, m = 1;
    printf("Enter the minimum: ");
    scanf("%lu", &t);
    printf("Enter the maximum: ");
    scanf("%lu", &n);
    for (unsigned long i = t; i <= n; i++) {
      if (isPrime(i) == 1) {
        printf("%lu-) %lu\n", m, i);
        m = m + 1;
      }
    }
    puts("");
    printf("There are %lu pirme numbers between %lu and %lu.\n", m - 1, t, n);
    puts("");
  }
}
unsigned int isPrime(unsigned long number) {

  unsigned long divider = number / 2;

  unsigned int stop = 0;

  unsigned int result;

  while (stop == 0) {

    result = number / divider;

    if (number == result * divider) {
      stop = 1;
      return 0;
    } else if (divider % 2 == 0) {
      divider = divider - 1;
    } else {
      divider = divider - 2;
    }
    if (divider < 2) {
      stop = 1;
    }
  }

  if (divider < 2) {
    if (stop == 1) {
      return 1;
    }
  }
}
void primeFactorization(unsigned long n) {
  unsigned long keep = n, div = 1;
  unsigned int stop = 0;
  printf("%lu = ", n);
  if (n > 2) {
    do {
      for (unsigned long i = 3; i <= n; i += 2) {
        if (n % 2 == 0)
          i = 2;
        do {
          if (n % i == 0) {
            n = n / i;
            stop = 0;
            div = div * i;
            if (keep != i) {
              printf("%lu", i);
              if (keep / div != 1)
                printf("*");
            }
          } else {
            stop = 1;
          }
          if (keep / div == 1)
            keep = 1;
        } while (stop == 0);
      }
    } while (keep != 1);
  }
  puts("");
}
