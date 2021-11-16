#include "prioqueue.h"

int main(){
  PrioQueue pq;
  CreatePrioQueue(&pq);
  Pesanan p;
  Item i;
  p.t = 3;
  p.pickUp = 'A';
  p.dropOff = 'B';
  createItem(&i, 'V', -1);
  p.tipeItem = i;
  enqueue(&pq, p);
  displayPesanan(HEAD(pq));
  displayItem(HEAD(pq).tipeItem);
}