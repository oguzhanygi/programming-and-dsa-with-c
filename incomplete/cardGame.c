#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int die() { return rand() % 6 + 1; }

void decisionTable(char alicesAnswer) {
  puts("Number on die\tOdd or even\tWinner");
  for (int i = 1; i <= 6; i++) {
    if (i % 2 == 1) {
      if (alicesAnswer == 'Y' || alicesAnswer == 'y')
        printf("%d\t\todd\t\tBob (Alice subtracted 1)\n", i);
      else
        printf("%d\t\teven\t\tAlice\n", i);
    } else {
      if (alicesAnswer == 'Y' || alicesAnswer == 'y')
        printf("%d\t\todd\t\tAlice (Alice subtracted 1)\n", i);
      else
        printf("%d\t\teven\t\tBob\n", i);
    }
  }
}

int main(void) {

  srand(time(NULL));

  int result = die();

  char alicesAnswer, bobsAnswer;

  puts("The die has been thrown.");
  printf("Does Alice want to subtract 1 from the result? [Y/N]: ");
  scanf("%c", &alicesAnswer);
  if (alicesAnswer == 'Y' || alicesAnswer == 'y')
    result -= 1;

  printf("Does Bob want to multiply the result by 2? [Y/N]: ");
  scanf("%c", &bobsAnswer);
  if (bobsAnswer == 'Y' || bobsAnswer == 'y')
    result *= 2;

  decisionTable(alicesAnswer);
}
