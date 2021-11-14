#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include "../adt.h"

int currentTime;
Lokasi currentLocation;
int currentMoney;
List TODO;
List inProgress;
PrioQueue psnTerurut;
Pesanan tempPesanan;

typedef struct {
  POINT size;
  Lokasi hq;
  int jumlah_lokasi;
  ListDin bangunan;
  Matrix adj;
  Ability b;
  Stack tas;
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

void displayPeta(Game g, int time);

void pickup(Game *g);

void dropOff(Game *g);

PrioQueue transformToPrioQueue(Game g);

#endif 