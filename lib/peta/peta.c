#include <stdio.h>
#include "peta.h"

void CreatePeta(Peta *p){
  CreateListDin(&getListDin(*p), MAX_ListDin);
  CreateMatrix(ROW_CAP, COL_CAP, &getAdjMatrix(*p));
}

void initializePeta(Peta *p, int size){
  readListDin(&getListDin(*p));
  readMatrix(&getAdjMatrix(*p), size+1, size+1);
}

int sizePeta(Peta p){
  return getLastIdx(p.l);
}

void displayLokasiPeta(Peta p){
  displayListDin(p.l);
}

void displayPeta(Peta p, int row, int col){
  Matrix m;
  CreateMatrix(row, col, &m);
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      MATRIXELMT(m, i, j) = -1;
    }
  }
  for(int i = 0; i <= sizePeta(p); i++){
    MATRIXELMT(m, ELMTADJMTRX(p, i).X-1, ELMTADJMTRX(p, i).Y-1) = i;
  }

  for(int i = 0; i < row-1; i++){
    if(i == row - 1){
      printf("*");
    }else printf("* ");
  }
  printf("\n");
  
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      if(j == 0){
        printf("*");
      }
      if(MATRIXELMT(m, i, j) != -1){
        printf("%c", TIPEBANGUNAN(p, MATRIXELMT(m, i, j)));
      }else printf(" ");
      if(j == col - 1){
        printf("*");
      }
    }
    printf("\n");
  }
  for(int i = 0; i < row-1; i++){
    if(i == row - 1){
      printf("*");
    }else printf("* ");
  }
  printf("\n");
}

void displayAdjPeta(Peta p, int idx){
  printf("\n");
  printf("Sekarang ada di: ");
  TulisLokasi(LISTELMT(p.l, idx));
  printf("Silahkan Pilih Lokasi untuk melanjutkan\n");
  int counter = 1;
  for(int i = 0; i <= sizePeta(p); i++){
    if(MATRIXELMT(getAdjMatrix(p), idx, i) == 1) {
      printf("%d. ", counter);
      printf("%c ", TIPEBANGUNAN(p, i));
      TulisPOINT(ELMTADJMTRX(p, i));
      counter++;
      printf("\n");
    }
  }
}