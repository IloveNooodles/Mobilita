#include <stdio.h>
#include "c/pcolor.c"
#include "c/point.c"
#include "c/time.c"

int main(){
  printf("Selamat datang di game mobilita\n");
  TIME t = MakeTIME(23, 59, 59);
  TulisTIME(t);
  return 0;
}