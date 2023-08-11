// This program shuffles a deck of cards and prints them with their randomized
// order.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13

void shuffle(int shuffleDeck[][FACES]);
void printDeck(int shuffleDeck[][FACES], const char *const suit[SUITS],
               const char *const face[FACES]);
int main(int argc, char **argv) {

  srand(time(NULL));

  const char *const suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
  const char *const face[FACES] = {"Ace",  "Deuce", "Three", "Four", "Five",
                                   "Six",  "Seven", "Eight", "Nine", "Ten",
                                   "Jack", "Queen", "King"};

  // a 2D array to keep shuffled values from 1 to 52 that represents cards
  int shuffleDeck[SUITS][FACES] = {};

  // fills the array randomly with uniqe numbers from 1 to 52
  shuffle(shuffleDeck);

  // print the whole deck
  printDeck(shuffleDeck, suit, face);
}

void shuffle(int shuffleDeck[][FACES]) {
  size_t randSuit = rand() % 4;
  size_t randFace = rand() % 13;
  int ctr = 0;

  for (size_t i = 0; i < SUITS; i++) {
    for (size_t j = 0; j < FACES; j++) {
      // changes randSuit and randFace until it finds an empty space
      while (shuffleDeck[randSuit][randFace] != 0) {
        ctr++;
        randSuit = rand() % 4;
        randFace = rand() % 13;
      }
      // places numbers from 1 to 52 to shuffleDeck array
      shuffleDeck[randSuit][randFace] = 13 * i + (j + 1);
    }
  }
  printf("%d\n", ctr);
}

void printDeck(int shuffleDeck[][FACES], const char *const suit[SUITS],
               const char *const face[FACES]) {
  for (size_t i = 0; i < SUITS; i++) {
    for (size_t j = 0; j < FACES; j++) {
      // finds the right face and suit using the number from shuffleDeck
      printf("%5s of %-8s\n", face[(shuffleDeck[i][j] - 1) % FACES],
             suit[(shuffleDeck[i][j] - 1) / FACES]);
    }
    puts("");
  }
}
