/* This program implements various character/string manipulation
functions that are found in ctype.h and string.h. */

#include <stdio.h>

int isBlank(int c) {
  if ((c >= 0 && c <= 32) || c == 127)
    return 1;
  else
    return 0;
}

int isDigit(int c) {
  if (c >= '0' && c <= '9')
    return 1;
  else
    return 0;
}

int isAlpha(int c) {
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    return 1;
  else
    return 0;
}

int isAlNum(int c) {
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    return 1;
  else if (c >= '0' && c <= '9')
    return 1;
  else
    return 0;
}

int isLower(int c) {
  if (c >= 'a' && c <= 'z')
    return 1;
  else
    return 0;
}

int isUpper(int c) {
  if (c >= 'A' && c <= 'Z')
    return 1;
  else
    return 0;
}

int toLower(int c) {
  if (c >= 'A' && c <= 'Z')
    return c + 32;
  else
    return c;
}

int toUpper(int c) {
  if (c >= 'a' && c <= 'z')
    return c - 32;
  else
    return c;
}

int main(void) {}
