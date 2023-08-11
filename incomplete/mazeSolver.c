#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

#define SIZE 12

void printMaze(size_t size, char maze[][size]);
void mazeGenerator(size_t size, char maze[][size]);
void solveMaze(size_t size, char maze[][size], size_t *row, size_t *column,
               size_t exitColumn);

int in, out;

int main(void) {

  srand(time(NULL));

  char maze[SIZE][SIZE] = {"############", "#...#......#", "..#.#.####.#",
                           "###.#....#.#", "#....###.#..", "####.#.#.#.#",
                           "#..#.#.#.#.#", "##.#.#.#.#.#", "#........#.#",
                           "######.###.#", "#......#...#", "############"};

  // mazeGenerator(SIZE, maze);

  puts("initial maze: ");
  printMaze(SIZE, maze);

  size_t startRow = 2, startColumn = 0;
  size_t exitRow = 4, exitColumn = SIZE - 1;

  solveMaze(SIZE, maze, &startRow, &startColumn, exitColumn);

  for (size_t i = 0; i < SIZE; i++) {
    for (size_t j = 0; j < SIZE; j++) {
      if (maze[i][j] == 'x')
        maze[i][j] = '.';
    }
  }

  printMaze(SIZE, maze);
}

void mazeGenerator(size_t size, char maze[][size]) {
  for (size_t i = 0; i < SIZE; i++) {
    for (size_t j = 0; j < SIZE; j++) {
      maze[i][j] = '#';
    }
  }
  in = rand() % (size - 2) + 1;
  maze[in][0] = '+';
  maze[in][1] = '.';
  out = rand() % (size - 2) + 1;
  maze[out][size - 1] = '.';
  maze[out][size - 2] = '.';

  for (size_t i = 1; i < size - 1; i++) {
    for (size_t j = 1; j < size - 1; j++) {
      if (rand() % 2 == 0 || rand() % 3 == 0)
        maze[i][j] = '.';
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
               size_t exitColumn) {

  int counter = 0;

  while (1) {
    if (counter % 5 == 0)
      printMaze(size, maze);
    counter++;

    if (maze[*row][*column + 1] == '.' && *column + 1 > 0 &&
        *column + 1 < SIZE) {
      maze[*row][*column] = 'o';
      *column += 1;
      maze[*row][*column] = '+';
      if (*column == exitColumn)
        break;
    } else if (maze[*row][*column - 1] == '.' && *column - 1 > 0 &&
               *column - 1 < SIZE) {
      maze[*row][*column] = 'o';
      *column -= 1;
      maze[*row][*column] = '+';
      if (*column == exitColumn)
        break;
    } else if (maze[*row + 1][*column] == '.' && *row + 1 > 0 &&
               *row + 1 < SIZE) {
      maze[*row][*column] = 'o';
      *row += 1;
      maze[*row][*column] = '+';
      if (*column == exitColumn)
        break;
    } else if (maze[*row - 1][*column] == '.' && *row - 1 > 0 &&
               *row - 1 < SIZE) {
      maze[*row][*column] = 'o';
      *row -= 1;
      maze[*row][*column] = '+';
      if (*column == exitColumn)
        break;
    } else {
      if (maze[*row][*column + 1] == 'o' && *column + 1 > 0 &&
          *column + 1 < SIZE) {
        maze[*row][*column] = 'x';
        *column += 1;
        maze[*row][*column] = '+';
        if (*column == exitColumn)
          break;
      } else if (maze[*row][*column - 1] == 'o' && *column - 1 > 0 &&
                 *column - 1 < SIZE) {
        maze[*row][*column] = 'x';
        *column -= 1;
        maze[*row][*column] = '+';
        if (*column == exitColumn)
          break;
      } else if (maze[*row + 1][*column] == 'o' && *row + 1 > 0 &&
                 *row + 1 < SIZE) {
        maze[*row][*column] = 'x';
        *row += 1;
        maze[*row][*column] = '+';
        if (*column == exitColumn)
          break;
      } else if (maze[*row - 1][*column] == 'o' && *row - 1 > 0 &&
                 *row - 1 < SIZE) {
        maze[*row][*column] = 'x';
        *row -= 1;
        maze[*row][*column] = '+';
        if (*column == exitColumn)
          break;
      }
    }
  }
}
