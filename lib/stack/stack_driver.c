#include <stdio.h>
#include "stack.c"

int main(){
  Stack s;
  Pesanan p;
  Item i;
  CreateStack(&s);
  p.t = 1;
  p.pickUp = 'a';
  p.dropOff = 'b';
  createItem(&i, 'N', -1);
  p.tipeItem = i; 
  push(&s, p);
  p.t = 2;
  p.pickUp = 'a';
  p.dropOff = 'b';
  createItem(&i, 'V', -1);
  p.tipeItem = i;
  push(&s, p);
  for(int i = 0; i <= IDX_TOP(s); i++){
    displayPesanan(s.buffer[i]);
  }
}