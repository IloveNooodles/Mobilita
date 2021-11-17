#include "point.h"

int main(){
  POINT p1 = MakePOINT(3, 5);
  POINT p2;
  BacaPOINT(&p2);
  TulisPOINT(p1);
  TulisPOINT(p2);
  printf("Selisih nya adalah: %d", selisih(p1, p2));
}