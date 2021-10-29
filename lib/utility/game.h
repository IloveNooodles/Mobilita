#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include "../point/point.h"
#include "../h/time.h"

//NOTE pake . buat nandai whitespace kayaknya enak
typedef struct {
  char tipeBangunan;
  POINT koor;
} Lokasi;

//NOTE mungkin ini tipe pickup dropoff tipe item nya bisa diganti nanti sesuai tipe masing masing
typedef struct {
  TIME t;
  char pickUp;
  char dropOff;
  char tipeItem;
} Pesanan;

//SELEKTOR Lokasi
#define KOOR(l) (l).koor
#define TIPEBANGUNAN(l) (l).tipeBangunan

//SELEKTOR PESANAN
#define WAKTU(l) (l).t
#define PICKUP(l) (l).pickUp
#define DROPOFF(l) (l).dropOff
#define tipeItem(l) (l).tipeItem



#endif 