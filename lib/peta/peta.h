#ifndef PETA_H
#define PETA_H

#include "../utility/boolean.h"
#include "../lokasi/lokasi.h"
#include "../listdin/listdin.h"
#include "../utility/adjmatrix.h"

#define MAX_ListDin 30
#define MAX_COL 40
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

typedef struct {
  ListDin l;
  AdjMatrix adj;
} Peta;

void CreatePeta(Peta *p);
void initializePeta(Peta *p, int size);
int sizePeta(Peta p);
void displayLokasiPeta(Peta p); 
void displayAdjPeta(Peta p, int idx);
void displayPeta(Peta p, int row, int col);

//Selektor
#define getAdjMatrix(p) (p).adj
#define getListDin(p) (p).l
#define TIPEBANGUNAN(p, i) LISTELMT(getListDin(p), i).tipeBangunan
#define ELMTADJMTRX(p, i) LISTELMT(getListDin(p), i).koor

#endif