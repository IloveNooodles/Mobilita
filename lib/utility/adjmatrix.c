#include <stdio.h>
#include "adjmatrix.h"

int charToIndex(char a){
  return a - 65;
}

char indexToChar(int a){
  return (char)(a+65);
}