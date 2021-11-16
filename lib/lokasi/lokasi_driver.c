#include "lokasi.c"

int main(){
  Lokasi l;
  Lokasi p;
  l.koor.X = 2;
  l.koor.Y = 3;
  l.tipeBangunan = 'B';

  p.koor.X = 2;
  p.koor.Y = 3;
  p.tipeBangunan = 'B';
  TulisLokasi(l);
  TulisLokasi(p);
  if(isLocationEqual(l, p)){
    printf("SAMA");
  }else{
    printf("bedad");
  }
}