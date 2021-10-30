#include <stdio.h>
#include "c/pcolor.c"
#include "h/time.h"

int main(){
  printf("Selamat datang di game mobilita\n");
  TIME t = MakeTIME(59);
  TulisTIME(t);
  return 0;
}