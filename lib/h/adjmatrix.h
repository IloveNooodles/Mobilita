#ifndef ADJMATRIX_H
#define ADJMATRIX_H

#include "boolean.h"
#include "matrix.h"

#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int charToIndex(char a){
  return a - 65;
}

char indexToChar(int a){
  return (char)(a+65);
}




#endif