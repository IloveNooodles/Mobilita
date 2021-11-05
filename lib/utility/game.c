#include <stdio.h>
#include "game.h"

void startGame(Game g){
  //TODO void readInput() ini bagian process IO
  WAKTUGAME(g) = 0;
  CurLoc(g) = g.hq;
}