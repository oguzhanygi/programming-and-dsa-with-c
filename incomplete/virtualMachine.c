#include <stdio.h>

#define MEMORY_SIZE 100

// input/output operations
#define READ 10
#define WRITE 11

// load/store operations
#define LOAD 20
#define STORE 21

// Arithmetic operations
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33

// transfer of control operations
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

void welcome(void);
void load(size_t size, int memory[]);
void execute(int instructionCounter, int instructionRegister, int memory[]);
void dump(size_t size, int arr[]);

int main(void) {
  int memory[MEMORY_SIZE] = {};

  welcome();
  load(MEMORY_SIZE, memory);
  execute(instructionCounter, instructionRegister, memory);
  dump(MEMORY_SIZE, memory);
}

void welcome(void) {
  char welcome[] = "***            Welcome to Simpletron          ***\n"
                   "***                                           ***\n"
                   "*** Please enter your program one instruction ***\n"
                   "*** (or data word) at a time. I will type the ***\n"
                   "*** location number and a question mark (?).  ***\n"
                   "*** You then type the word for that location. ***\n"
                   "*** Type the sentinel -99999 to stop entering ***\n"
                   "*** your program.                             ***\n";
  printf("%s", welcome);
}

void load(size_t size, int memory[]) {
  int instruction = 0;
  int instructionCounter = 0;
  int instructionRegister = 0;
  while (instruction != -99999) {
    printf("%02d ? ", instructionCounter);
    scanf("%d", &instruction);
    instructionRegister = memory[instructionCounter];
    instructionCounter++;
  }
  puts("*** Program loading completed ***");
}

void execute(int instructionCounter, int instructionRegister, int memory[]) {
  int operationCode = instructionRegister / 100;
  int operand = instructionRegister % 100;
  int accumulator = 0;
  puts("*** Program execution begins  ***");
  while (operationCode != HALT) {
    switch (operationCode) {
    case READ:
      scanf("%d", &memory[operand]);
      break;
    case WRITE:
      printf("%d\n", memory[operand]);
      break;
    case LOAD:
      accumulator = memory[operand];
      break;
    case STORE:
      memory[operand] = accumulator;
      break;
    case ADD:
      accumulator += memory[operand];
      break;
    case SUBTRACT:
      accumulator -= memory[operand];
      break;
    case DIVIDE:
      accumulator /= memory[operand];
      break;
    case MULTIPLY:
      accumulator *= memory[operand];
      break;
    case BRANCH:
      instructionCounter = operand;
      break;
    case BRANCHZERO:
      if (accumulator == 0) {
        instructionCounter = operand;
      }
      break;
    case BRANCHNEG:
      if (accumulator < 0) {
        instructionCounter = operand;
      }
      break;
    }
  }
  puts("*** Simpletron execution terminated ***");
}

void dump(size_t size, int arr[]) {
  printf("%s", "MEMORY:\n\t");
  for (int i = 0; i < 10; i++) {
    printf("%5d\t", i);
  }
  puts("");
  for (size_t i = 0; i < size; i++) {
    if (i % 10 == 0) {
      printf("%2zu\t", i);
    }
    printf("%+05d\t", arr[i]);
    if (i % 10 == 9) {
      puts("");
    }
  }
}
