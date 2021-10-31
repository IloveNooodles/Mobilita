#ifndef PETA_H
#define PETA_H

#include "../utility/boolean.h"
#include "../lokasi/lokasi.h"
#include "../listdin/listdin.h"
#include "../utility/adjmatrix.h"

#define MAX_ListDin 30;
#define MAX_COL 40
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

typedef struct {
  ListDin l;
  AdjMatrix adj;
} Peta;

void CreatePeta(Peta *p);


//NOTE jangan lupa buat selektronya

#endif