#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

#define SIZE 20

void printMaze(size_t size, char maze[][size]);
void mazeGenerator(size_t size, char maze[][size]);
void solveMaze(size_t size, char maze[][size], size_t *row, size_t *column,
               size_t exitRow, size_t exitColumn);

static int in, out;

int main(void) {

  srand(time(NULL));

  char maze[SIZE][SIZE];

  for (size_t i = 0; i < SIZE; i++) {
    for (size_t j = 0; j < SIZE; j++) {
      maze[i][j] = '#';
    }
  }

  mazeGenerator(SIZE, maze);

  puts("Initial maze: ");
  printMaze(SIZE, maze);

  size_t startRow = in, startColumn = 0;
  size_t exitRow = out, exitColumn = SIZE - 1;

  // solveMaze(SIZE, maze, &startRow, &startColumn, exitRow, exitColumn);

  for (size_t i = 0; i < SIZE; i++) {
    for (size_t j = 0; j < SIZE; j++) {
      if (maze[i][j] == 'x')
        maze[i][j] = '.';
    }
  }

  // printMaze(SIZE, maze);
}

void mazeGenerator(size_t size, char maze[][size]) {
  in = rand() % (size - 2) + 1;
  maze[in][0] = '+';
  maze[in][1] = '.';
  out = rand() % (size - 2) + 1;
  maze[out][size - 1] = '.';
  maze[out][size - 2] = '.';

  int i = in, j = 1;
  int way;
  int steps;

  while (i != out || j != size - 2) {
    way = rand() % 4;
    steps = rand() % (size / 3);
    switch (way) {
    case 0:
      for (size_t k = 0; k < steps; k++) {
        if (j + 1 < size - 1 && j + 1 > 0) {
          maze[i][j + 1] = '.';
          j = j + 1;
          printMaze(size, maze);
        }
      }
      break;
    case 1:
      for (size_t k = 0; k < steps; k++) {
        if (j - 1 < size - 1 && j - 1 > 0) {
          maze[i][j - 1] = '.';
          j = j - 1;
          printMaze(size, maze);
        }
      }
      break;
    case 2:
      for (size_t k = 0; k < steps; k++) {
        if (i + 1 < size - 1 && i + 1 > 0) {
          maze[i + 1][j] = '.';
          i = i + 1;
          printMaze(size, maze);
        }
      }
      break;
    case 3:
      for (size_t k = 0; k < steps; k++) {
        if (i - 1 < size - 1 && i - 1 > 0) {
          maze[i - 1][j] = '.';
          i = i - 1;
          printMaze(size, maze);
        }
      }
      break;
    }
  }
}

void printMaze(size_t size, char maze[][size]) {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      switch (maze[i][j]) {
      case '#':
        printf(YELLOW "%c " RESET, maze[i][j]);
        break;
      case 'o':
        printf(GREEN "%c " RESET, maze[i][j]);
        break;
      case 'x':
        printf(RED "%c " RESET, maze[i][j]);
        break;
      default:
        printf("%c ", maze[i][j]);
        break;
      }
    }
    puts("");
  }
  puts("");
}

void solveMaze(size_t size, char maze[][size], size_t *row, size_t *column,
               size_t exitRow, size_t exitColumn) {}
