#include "list_linked.h"

//NOTE buat perishable item belom bisa kayaknya
int main(){
  PrioQueue pq;
  CreatePrioQueue(&pq);
  Pesanan p;
  p.t = 1;
  p.pickUp = 'G';
  p.dropOff = 'N';
  p.tipeItem = 'N';
  enqueue(&pq, p);
  p.t = 12;
  p.pickUp = 'G';
  p.dropOff = 'N';
  p.tipeItem = 'H';
  enqueue(&pq, p);
  p.t = 5;
  p.pickUp = 'A';
  p.dropOff = 'Q';
  p.tipeItem = 'H';
  enqueue(&pq, p);
  p.t = 10;
  p.pickUp = 'B';
  p.dropOff = 'P';
  p.tipeItem = 'V';
  enqueue(&pq, p);
  List l;
  CreateLinkedList(&l);
  for(int i = 0; i < lengthPrioQueue(pq); i++){
    insertLast(&l, pq.buffer[i]);
  }
  displayPesananTerurut(l);
  displayInProgressList(l);
}