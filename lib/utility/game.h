#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include "../point/point.h"
#include "../matrix/matrix.h"
#include "../adt.h"
#include "../peta/peta.h"

//NOTE mungkin ini tipe pickup dropoff tipe item nya bisa diganti nanti sesuai tipe masing masing dan kaykanya bisa buat adt baru juga
typedef struct {
  int t;
  char pickUp;
  char dropOff;
  char tipeItem;
} Pesanan;

typedef struct {
  POINT size;
  POINT hq;
  int jumlah_lokasi;
  Lokasi bangunan[30];
  AdjMatrix adj;
  int jumlah_pesanan;
  Pesanan psn[35];
} Game;

void startGame();
void saveGame();
void loadGame();

//SELEKTOR PESANAN
#define WAKTUPESANAN(l) (l).t
#define PICKUP(l) (l).pickUp
#define DROPOFF(l) (l).dropOff
#define tipeItem(l) (l).tipeItem

//SelektorGame
#define WAKTUGAME(l) (l).time
#define CurLoc(l) (l).CurrentLocation


#endif 