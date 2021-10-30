#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include "../point/point.h"
#include "../h/time.h"

//NOTE mungkin ini tipe pickup dropoff tipe item nya bisa diganti nanti sesuai tipe masing masing
typedef struct {
  TIME t;
  char pickUp;
  char dropOff;
  char tipeItem;
} Pesanan;

//SELEKTOR PESANAN
#define WAKTU(l) (l).t
#define PICKUP(l) (l).pickUp
#define DROPOFF(l) (l).dropOff
#define tipeItem(l) (l).tipeItem



#endif 