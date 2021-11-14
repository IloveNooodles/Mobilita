#include <stdio.h>
#include "prioqueue.h"

void CreatePrioQueue(PrioQueue *pq){
  IDX_HEAD(*pq) = IDX_UNDEF;
  IDX_TAIL(*pq) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */

boolean isEmpty(PrioQueue pq){
  return IDX_HEAD(pq) == IDX_UNDEF && IDX_TAIL(pq) == IDX_UNDEF;
}
/* Mengirim true jika pq kosong: lihat definisi di atas */

boolean isFull(PrioQueue pq){
  return IDX_HEAD(pq) == 0 && IDX_TAIL(pq) == CAPACITY-1;
}
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */

int lengthPrioQueue(PrioQueue pq){
  if(isEmpty(pq)) return 0;
  return IDX_TAIL(pq) - IDX_HEAD(pq) + 1;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika pq kosong. */

/*** Primitif Add/Delete ***/

void geserKiri(PrioQueue *pq){
  for(int i = IDX_HEAD(*pq); i <= IDX_TAIL(*pq); i++){
    (*pq).buffer[i-IDX_HEAD(*pq)] = (*pq).buffer[i];
  }
  IDX_TAIL(*pq) -= IDX_HEAD(*pq);
  IDX_HEAD(*pq) = 0;
}

void enqueue(PrioQueue *pq, Pesanan val){
  if(isEmpty(*pq)){
    IDX_HEAD(*pq) = 0;
    IDX_TAIL(*pq) = 0;
    TAIL(*pq) = val;
  }else{
    if(IDX_HEAD(*pq) != 0 && IDX_TAIL(*pq) == CAPACITY - 1){
      geserKiri(pq);
    }
    boolean found = false;
    for(int i = IDX_HEAD(*pq); i <= IDX_TAIL(*pq); i++){
      if(val.t < (*pq).buffer[i].t){
        found = true;
        for(int j = IDX_TAIL(*pq); j >= i; j--){
          (*pq).buffer[j+1] = (*pq).buffer[j];
        }
        (*pq).buffer[i] = val;
        break;
      }
    }
    IDX_TAIL(*pq)++;
    if(!found){
      TAIL(*pq) = val;
    }
  }
}
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen pq
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeue(PrioQueue * pq, Pesanan *val){
  *val = HEAD(*pq);
  if(lengthPrioQueue(*pq) == 1){
    IDX_TAIL(*pq) = IDX_UNDEF;
    IDX_HEAD(*pq) = IDX_UNDEF;
  }else{
    IDX_HEAD(*pq) += 1;
  }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd
I.S., HEAD dan IDX_HEAD "mundur"; 
        pq mungkin kosong */

boolean isPesananEqual(Pesanan p1, Pesanan p2){
  return (WAKTUPESANAN(p1) == WAKTUPESANAN(p2) && PICKUP(p1) == PICKUP(p2) && DROPOFF(p1) == DROPOFF(p2) && tipeItem(p1).type == tipeItem(p2).type);
}

void displayPesanan(Pesanan p){
  printf("%c -> %c", p.pickUp, p.dropOff);
  if(p.tipeItem.type == 'N'){
    printf(" (Normal Item) ");
  }else if(p.tipeItem.type == 'H'){
    printf(" (Heavy Item) ");
  }else if(p.tipeItem.type == 'P'){
    printf(" (Perishable Item, sisa waktu %d)", p.tipeItem.expiry_now);
  }else if(p.tipeItem.type == 'V'){
    printf(" (VIP Item) ");
  }
  printf("\n");
}

void displayInProgress(Pesanan p){
  if(p.tipeItem.type == 'N'){
    printf("Normal Item (Tujuan: %c)", p.dropOff);
  }else if(p.tipeItem.type == 'H'){
    printf("Heavy Item (Tujuan: %c)", p.dropOff);
  }else if(p.tipeItem.type == 'P'){
    printf("Perishable Item, sisa waktu %d (Tujuan: %c)", p.tipeItem.expiry_now, p.dropOff);
  }else if(p.tipeItem.type == 'V'){
    printf("VIP Item (Tujuan: %c)", p.dropOff);
  }
  printf("\n");
}
