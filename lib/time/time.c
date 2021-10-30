#include <stdio.h>
#include "time.h"
#include "../point/point.c"

boolean IsTIMEValid(int S){
  return S >= 0;
}

TIME MakeTIME(int SS){
  TIME a;
  Second(a) = SS;
  return a;
}

void BacaTIME(TIME *T){
  int SS;
  scanf("%d", &SS);
  if(IsTIMEValid(SS)){
    *T = MakeTIME(SS);
  }
  else {
    while(!IsTIMEValid(SS)){
      printf("Jam tidak valid\n");
      scanf("%d", &SS);
    }
    *T = MakeTIME(SS);
  }
}

void TulisTIME(TIME T){
  int SS;
  SS = Second(T);
  printf("%d", SS);
}

boolean TEQ(TIME T1, TIME T2){
  return (Second(T1) == Second(T2));
}

boolean TNEQ(TIME T1, TIME T2){
  return (Second(T1) != Second(T2));
}

boolean TLT(TIME T1, TIME T2){
  return (Second(T1) < Second(T2));
}

boolean TGT(TIME T1, TIME T2){
  return (Second(T1) > Second(T2));
}

void NextNDetik(TIME T, int N){
  Second(T) += N;
}

TIME NextNDetikTime(TIME T, int N){
  TIME t1;
  Second(t1) = Second(T);
  Second(t1) += N;
  return t1;
}

void PrevNDetik(TIME T, int N){
  Second(T) -= N;
}

TIME PrevNDetikTime(TIME T, int N){
  TIME t1;
  Second(t1) = Second(T);
  Second(t1) -= N;
  return t1;
}

//NOTE karena bentuk petanya persegi makannya nguranginnya gini implementasinya bisa diliat di point.c
void pindah(TIME T, POINT a, POINT b){
  NextNDetik(T, selisih(a, b));
}
