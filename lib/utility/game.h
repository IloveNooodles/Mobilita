#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include "../point/point.h"
#include "../time/time.h"
#include "../adt.h"

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

typedef struct {
  Lokasi peta[20][30];
  POINT hq;
  int jumlah_lokasi;
  Lokasi bangunan[26];
  Matrix adj[26][26];
  Pesanan psn[30];
} Game;



#endif 