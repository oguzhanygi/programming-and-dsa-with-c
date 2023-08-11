// This program demonstrates the use of function pointers

#include <stdio.h>

void function1(void);
void function2(void (*functionPtr)(void));
void function3(void *aFunctionThatReturnsPtr(void));

int main(void) {
  function2(function1);
  puts("");
  function3(NULL);
}

void function1(void) { puts("The function has been called."); }

// With parantheses
void function2(void (*functionPtr)(void)) {
  puts("This function recieves a function pointer: ");
  printf("Value of the function pointer: %p\n", functionPtr);
  puts("Calling the function using the function pointer: ");
  functionPtr();
}

// Without parantheses
void function3(void *aFunctionThatReturnsPtr(void)) {
  puts("This function declares a function");
  puts("that returns a pointer in it's parameter list.");
}
