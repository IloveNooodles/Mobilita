#ifndef ADJMATRIX_H
#define ADJMATRIX_H

#include "boolean.h"
#include "../matrix/matrix.h"

typedef Matrix AdjMatrix;

#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int charToIndex(char a);
char indexToChar(int a);


#endif