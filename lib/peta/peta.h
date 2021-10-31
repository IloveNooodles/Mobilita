#ifndef PETA_H
#define PETA_H

#include "../point/point.h"
#include "../utility/boolean.h"

#define MAX_ROW 30
#define MAX_COL 40
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

typedef struct {
  char tipeBangunan;
  boolean state;
  POINT koor;
} Lokasi;

typedef struct {
  Lokasi buffer[MAX_ROW][MAX_COL];
  int idxRow;
  int idxCol;
} Peta;

#define KOOR(l, i, j) (l).buffer[i][j].koor
#define TIPEBANGUNAN(l, i, j) (l).buffer[i][j].tipeBangunan
#define DILOKASI(l, i, j) (l).buffer[i][j].state
#define getRowPeta(l) (l).idxRow
#define getColPeta(l) (l).idxCol

#endif