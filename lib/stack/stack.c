/* File : stack.h */
/* Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#include "stack.h"

int stack_capacity = 3;

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *s){
  IDX_TOP(*s) = IDX_UNDEF;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean isStackEmpty(Stack s){
  return IDX_TOP(s) == IDX_UNDEF;
}
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean isStackFull(Stack s){
  return IDX_TOP(s) == stack_capacity - 1;
}
/* Mengirim true jika tabel penampung nilai s stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void push(Stack *s, StackElType val){
  IDX_TOP(*s) += 1;
  TOP(*s) = val;
}
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void pop(Stack *s, StackElType *val){
  *val = TOP(*s);
  IDX_TOP(*s) -= 1;
}
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

/* ************ Menambah kapasitas Stack ************ */
boolean increaseCapacity(int amount) {
    if (stack_capacity == CAPACITY) {
        return false;
    }
    else {
        if (stack_capacity + amount >= CAPACITY) {
            stack_capacity = CAPACITY;
        }
        else {
            stack_capacity += amount;
        }

        return true;
    }
}

/* Menambah kapasitas maksimal Stack sebanyak amount */
/* stack_capacity bernilai maksimal 100 */
