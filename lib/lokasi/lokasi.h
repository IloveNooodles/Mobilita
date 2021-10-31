#ifndef LOKASI_H
#define LOKASI_H

#include "../point/point.h"

typedef struct {
  char tipeBangunan;
  POINT koor;
} Lokasi;

void TulisLokasi(Lokasi c);

#define getTipeBangunan(l) (l).tipeBangunan
#define getKoordinat(l) (l).koor

#endif  