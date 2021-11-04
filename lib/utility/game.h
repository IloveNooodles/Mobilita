#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include "../point/point.h"
#include "../matrix/matrix.h"
#include "../adt.h"
#include "../lokasi/lokasi.h"
#include "../wordmachine/wordmachine.h"
#include "../wordmachine/charmachine.h"

int currentTime;
Lokasi currentLocation;

// typedef struct {
//   char tipeBangunan;
//   POINT koor;
// } Lokasi;

typedef struct {
  int t;
  char pickUp;
  char dropOff;
  char tipeItem;
} Pesanan;

typedef struct {
  POINT size;
  Lokasi hq;
  int jumlah_lokasi;
  Lokasi bangunan[27];
  Matrix adj;
  int jumlah_pesanan;
  Pesanan psn[30];
  boolean endGame;
} Game;


//SELEKTOR Lokasi
#define KOOR(l) (l).koor
#define TIPEBANGUNAN(l) (l).tipeBangunan

//SELEKTOR PESANAN
#define WAKTU(l) (l).t
#define PICKUP(l) (l).pickUp
#define DROPOFF(l) (l).dropOff
#define tipeItem(l) (l).tipeItem


void move(Game g);

void updatePosition(Lokasi l);



#endif 