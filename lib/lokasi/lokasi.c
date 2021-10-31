#include <stdio.h>
#include "lokasi.h"

void TulisLokasi(Lokasi c){
  printf("%c ", getTipeBangunan(c));
  TulisPOINT(getKoordinat(c));
  printf("\n");
}