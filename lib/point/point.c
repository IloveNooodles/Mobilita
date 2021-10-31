#include <stdio.h>
#include <math.h>
#include "point.h"

POINT MakePOINT(int x, int y){
  POINT p;
  Absis(p) = x;
  Ordinat(p) = y;
  return p;
}

void BacaPOINT(POINT* P){
  int x, y;
  scanf("%d %d", &x, &y);
  *P = MakePOINT(x, y);
}

void TulisPOINT(POINT P){
  printf("(%d,%d)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2){
  return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2){
  return (!EQ(P1, P2));
}

boolean IsOrigin(POINT P){
  return (Absis(P) == 0 && Ordinat(P) == 0);
}

boolean IsOnSbX(POINT P){
  return (Ordinat(P) == 0);
}

boolean IsOnSbY(POINT P){
  return (Absis(P) == 0);
}

int Kuadran(POINT P){
  int x, y;
  x = Absis(P);
  y = Ordinat(P);
  if(x > 0 && y > 0){
    return 1;
  }else if(x < 0 && y > 0){
    return 2;
  }else if(x < 0 && y < 0){
    return 2;
  }else if(x > 0 && y < 0){
    return 4;
  }
}

POINT NextX(POINT P){
  POINT P2;
  Absis(P2) = Absis(P) + 1;
  Ordinat(P2) = Ordinat(P);
  return P2;
}

POINT NextY(POINT P){
  POINT P2;
  Absis(P2) = Absis(P);
  Ordinat(P2) = Ordinat(P) + 1;
  return P2;
}

POINT PlusDelta(POINT P, int deltaX, int deltaY){
  POINT P2;
  Absis(P2) = Absis(P) + deltaX;
  Ordinat(P2) = Ordinat(P) + deltaY;
  return P2;
}

POINT MirrorOf(POINT P, boolean Sbx){
  POINT P2;
  int x, y;
  x = Absis(P);
  y = Ordinat(P);
  if(Sbx){
    y = -y;
  }else x = -x;
  Absis(P2) = x;
  Ordinat(P2) = y;
  return P2;
}

float Jarak0(POINT P){
  return sqrt(pow((Absis(P)), 2) + pow((Ordinat(P)), 2));
}

float Panjang(POINT P1, POINT P2){
  return sqrt(pow((Absis(P1) - Absis(P2)), 2) + pow((Ordinat(P1) - Ordinat(P2)), 2));
}

void Geser(POINT *P, int deltaX, int deltaY){
  Absis(*P) += deltaX;
  Ordinat(*P) += deltaY;
}

void GeserKeSbX(POINT *P){
  Ordinat(*P) = 0;
}

void GeserKeSbY(POINT *P){
  Absis(*P) = 0;
}

void Mirror(POINT* P, boolean SbX){
  if(SbX){
    Ordinat(*P) = -Ordinat(*P);
  }else{
    Absis(*P) = -Absis(*P);
  }
}

//NOTE ngereturn selisih koordinat p1 sama p2 atau langkah yang harus dilalui;
int selisih(POINT P1, POINT P2){
  return abs(Absis(P1) - Absis(P2)) + abs(Ordinat(P1) - Ordinat(P2));
}