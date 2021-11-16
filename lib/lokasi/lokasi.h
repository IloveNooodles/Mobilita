#ifndef LOKASI_H
#define LOKASI_H

#include <stdio.h>
#include "../point/point.c"

typedef struct {
  char tipeBangunan;
  POINT koor;
} Lokasi;

void TulisLokasi(Lokasi c);
boolean isLocationEqual(Lokasi l1, Lokasi l2);

#define getTipeBangunan(l) (l).tipeBangunan
#define getKoordinat(l) (l).koor

#endif  