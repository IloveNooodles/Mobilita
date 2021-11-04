#include <stdio.h>
#include "lokasi.h"

void TulisLokasi(Lokasi c){
    printf("%c ", getTipeBangunan(c));
    TulisPOINT(getKoordinat(c));
    printf("\n");
}

boolean isLocationEqual(Lokasi l1, Lokasi l2){
    return EQ(l1.koor,l2.koor) && l1.tipeBangunan == l2.tipeBangunan;
}