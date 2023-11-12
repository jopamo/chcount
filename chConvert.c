#include "chConvert.h"

char toUpper(char ch) {
  if (ch >= 'a' && ch <= 'z') {
    return ch - 'a' + 'A';
  }
  return ch;
}

char toLower(char ch) {
  if (ch >= 'A' && ch <= 'Z') {
    return ch - 'A' + 'a';
  }
  return ch;
}
