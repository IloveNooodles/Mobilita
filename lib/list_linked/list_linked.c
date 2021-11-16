#include <stdio.h>
#include <stdlib.h>
#include "list_linked.h"

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateLinkedList(List *l){
  FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isLinkedListEmpty(List l){
  return FIRST(l) == NULL;
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
PesananElType getElmt(List l, int idx){
  Address p = l;
  int i = 0;
  while(i < idx){
    i += 1;
    p = NEXT(p);
  }
  return INFO(p);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, PesananElType val){
  Address p = *l;
  int i = 0;
  while(i < idx){
    i += 1;
    p = NEXT(p);
  }
  INFO(p) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

//NOTE gw gatau ini yang indexof bakal kepake atau engga feeling2 gabakal kepake jadi gw komen dulu buat sementara
// int indexOfLinkedList(List l, ElType val){
//   int idx = 0;
//   Address p = l;
//   boolean found = false;
//   while(p != NULL && !found){
//     if(INFO(p) == val){
//       found = true;
//     }else{
//       idx += 1;
//       p = NEXT(p);
//     }
//   }
//   if(found){
//     return idx;
//   }else{
//     return IDX_UNDEF;
//   }
// }
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, PesananElType val){
  Address p = newNode(val);
  if (p != NULL){
    NEXT(p) = *l;
    *l = p;
  }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, PesananElType val){
  if(isLinkedListEmpty(*l)){
    insertFirst(l, val);
  }else{
    Address p = newNode(val);
    if(p != NULL){
      Address last = *l;
      while(NEXT(last) != NULL){
        last = NEXT(last);
      }
      NEXT(last) = p;
    }
  }
}

/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, PesananElType val, int idx){
  if(idx == 0){
    insertFirst(l, val);
  }else{
    Address p = newNode(val);
    if(p != NULL){
      int i = 0;
      Address last = *l;
      while(i < idx - 1){
        i++;
        last = NEXT(last);
      }
      NEXT(p) = NEXT(last);
      NEXT(last) = p;
    }
  }

}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, PesananElType *val){
  Address p = *l;
  *val = INFO(p);
  *l = NEXT(p);
  free(p);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, PesananElType *val){
  Address loc = NULL;
  Address p = *l;
  while(NEXT(p) != NULL){
    loc = p;
    p = NEXT(p);
  }
  if(loc == NULL){
    *l = NULL;
  }else{
    NEXT(loc) = NULL;
  }
  *val = INFO(p);
  free(p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, PesananElType *val){
  if(idx == 0){
    deleteFirst(l, val);
  }else{
    Address loc = *l;
    Address p;
    int i = 0;
    while(i < idx - 1){
      i++;
      loc = NEXT(loc);
    }
    p = NEXT(loc);
    *val = INFO(p);
    NEXT(loc) = NEXT(p);
  }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int listLinkedLength(List l){
  int len = 0;
  Address p = l;
  while(p != NULL){
    len += 1;
    p = NEXT(p);
  }
  return len;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2){
  List l3;
  CreateLinkedList(&l3);
  Address p = l1;
  while(p != NULL){
    insertLast(&l3, INFO(p));
    p = NEXT(p);
  }
  p = l2;
  while(p != NULL){
    insertLast(&l3, INFO(p));
    p = NEXT(p);
  }
  return l3;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

//NOTE ngecheck apa ada item ini buat ngeprint merah
boolean hasItem(List l, Lokasi loc){
  Address now = l;
  boolean found = false;
  while(now != NULL && !found){
    if(INFO(now).pickUp == loc.tipeBangunan){
      found = true;
    }
    now = NEXT(now);
  }
  return found;
}

void onePerishableList(List *l){
  boolean found = false;
  Address now = *l;
  while(now != NULL && !found){
    if(INFO(now).tipeItem.type == 'P'){
      INFO(now).tipeItem.expiry_now = INFO(now).tipeItem.expiry;
      found = true;
    }else{
      now = NEXT(now);
    }
  }
}

void allPerishableList(List *l, int selisih){
  Address now = *l;
  while(now != NULL){
    if(INFO(now).tipeItem.type == 'P'){
      if(INFO(now).tipeItem.expiry_now + selisih >= INFO(now).tipeItem.expiry){
        INFO(now).tipeItem.expiry_now = INFO(now).tipeItem.expiry;
      }else{
        INFO(now).tipeItem.expiry_now += selisih;
      }
    }
    now = NEXT(now);
  }
}

//NOTE buat ngecheck ada persihable apa engga
int checkInProgress(List l, Pesanan PesananIn){
  Address now = l;
  int counter = 0;
  boolean found = false;
  while(now != NULL && !found){
    if(isPesananEqual(INFO(now), PesananIn)){
      found = true;
    }
    counter++;
    now = NEXT(now);
  }
  if(found)return counter - 1;
  else return IDX_UNDEF;
}

//NOTE Buat ngecheck di todo
int checkPesanan(List l, Lokasi loc){
  Address now = l;
  int counter = 0;
  boolean found = false;
  while(now != NULL && !found){
    if(INFO(now).pickUp == getTipeBangunan(loc)){
      found = true;
    }
    counter++;
    now = NEXT(now);
  }
  if(found){
    return counter-1;
  }else{
    return IDX_UNDEF;
  }
}

//NOTE buat ngedelete item dari TODO
void deletePesanan(List *l, Pesanan *PesananOut, int idx){
    Pesanan tmpPesanan;
    deleteAt(l, idx, &tmpPesanan);
    *PesananOut = tmpPesanan;
}
void displayPesananTerurut(List l){
  if(isLinkedListEmpty(l)){
    printf("Tidak ada to do list pada saat ini.\n");
  }else{
    printf("Pesanan pada To Do List: \n");
    Address now = l;
    int i = 1;
    while(now != NULL){
      printf("%d. ", i);
      i++;
      displayPesanan(INFO(now));
      now = NEXT(now);
    }
    printf("\n");
  }
}

void displayInProgressList(List l){
  if(isLinkedListEmpty(l)){
    printf("Tidak ada pesanan yang sedang diantarkan.\n");
  }else{
    Address now = l;
    printf("Pesanan yang sedang diantarkan: \n");
    int i = 1;
    while(now != NULL){
      printf("%d. ", i);
      i++;
      displayInProgress(INFO(now));
      now = NEXT(now);
    }
    printf("\n");
  }
}

void minusExpiryList(List *l){
  Address now = *l;
  while(now != NULL){
    minusExpiry(&INFO(now).tipeItem);
    now = NEXT(now);
  }
}