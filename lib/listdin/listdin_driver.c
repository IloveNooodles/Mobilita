#include <stdio.h>
#include "listdin.c"

int main(){
  ListDin l;
  CreateListDin(&l, 26);
  readListDin(&l);
  displayListDin(l);
  printf("%d", listDinLength(l));
  dealocate(&l);
  displayListDin(l);
  printf("%d", listDinLength(l));
}