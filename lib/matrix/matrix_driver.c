#include "matrix.h"

int main(){
  Matrix m;
  readMatrix(&m, 3, 3);
  displayMatrix(m);
  printf("\n");
  Matrix m1;
  readMatrix(&m1, 2, 2);
  if(isSizeEqual(m, m1)){
    printf("sama");
  }else{
    printf("GAK SAMA BOS");
  }
  displayMatrix(m1);
}