/* This program is a simple number guessing game. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guess(unsigned int number) {

  unsigned int guess = 0;
  int counter = 1;

  puts("I have a number between 1 and 1000.");
  puts("Can you guess my number?");
  printf("%s", "Please type your first guess: ");
  scanf("%u", &guess);
  if (guess == number) {
    printf("%s", "WOW! You guessed on the first try!\n");
  } else {
    while (guess != number) {
      if (counter == 10) {
        puts("You know, it shouldn't take more than 10 times.");
      }
      if (guess > number) {
        printf("%s", "Too high. Try again: ");
        scanf("%u", &guess);
      } else if (guess < number) {
        printf("%s", "Too low. Try again: ");
        scanf("%u", &guess);
      }
      counter++;
    }
    printf("You did it! You guessed it after trying %d times.\n", counter);
  }
}

int main(void) {

  srand(time(NULL));

  unsigned int number = rand() % 1000 + 1;

  guess(number);
}
