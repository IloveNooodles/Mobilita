#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include "../point/point.h"
#include "../matrix/matrix.h"
#include "../adt.h"
#include "../lokasi/lokasi.h"
#include "../wordmachine/wordmachine.h"
#include "../wordmachine/charmachine.h"
#include "../listdin/listdin.h"

int currentTime;
Lokasi currentLocation;
int currentMoney;

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
  ListDin bangunan;
  // Lokasi bangunan[27];
  Matrix adj;
  int jumlah_pesanan;
  Pesanan psn[30];
  boolean endGame;
} Game;

void startGame();
void saveGame();
void loadGame();

//SELEKTOR PESANAN
#define WAKTUPESANAN(l) (l).t
#define PICKUP(l) (l).pickUp
#define DROPOFF(l) (l).dropOff
#define tipeItem(l) (l).tipeItem


void move(Game g);
// Move function

void updatePosition(Lokasi l);
// Update currentPosition with the input location

void displayCurrentMoney();

void displayCurrentLocation();

void displayPeta(Game g);

#endif 