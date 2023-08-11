/* This program turns a string to fully uppercase. 
*/

#include <stdio.h>

void toUpper(char* arr);

int main() {

  char arr[] = "cHaRaCters and $32.98";
  toUpper(arr);
  printf("%s\n", arr);

}

void toUpper(char* arr) {

  for(size_t i = 0; arr[i] != '\0'; i++) {

    if(96 < arr[i] && 123 > arr[i]) {

      arr[i] = arr[i] - 32;
    }
  }
}
