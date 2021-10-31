/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include "../utility/boolean.h"
#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
  LISTBUFFER(*l) = (Lokasi*) malloc(capacity*sizeof(Lokasi));
  NEFF(*l) = 0;
  CAP(*l) = capacity;
}

void dealocate(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
  free(LISTBUFFER(*l));
  NEFF(*l) = 0;
  CAP(*l) = 0;
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listDinLength(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
  return NEFF(l);
}


/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
  return NEFF(l) - 1;
}
/* ********** Test Indeks yang valid ********** */
boolean isIdxListDinValid(ListDin l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return (i >= 0 && i < CAP(l));
}
boolean isIdxListDinEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
  return (i >= 0 && i < NEFF(l));
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isListDinEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
  return (NEFF(l) == 0);
}
/* *** Test list penuh *** */
boolean isListDinFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
  return (NEFF(l) == CAP(l));
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readListDin(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
  int n, i;
  char a;
  scanf("%i", &n);
  while (n < 0 || n > CAP(*l)){
      scanf("%i", &n);
  }
  NEFF(*l) = n;
  if (n != 0){
    for (i=0; i<n; i++){
      scanf("%s", &LISTELMT(*l, i).tipeBangunan);
      BacaPOINT(&LISTELMT(*l, i).koor);
    }
  }
}

void displayListDin(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

{
  int i, len;
  len = listDinLength(l);
  if (len != 0){
    for (i = 0; i <= getLastIdx(l); i++){
      printf("%c ", LISTELMT(l, i).tipeBangunan);
      TulisPOINT(LISTELMT(l,i).koor);
      printf("\n");
    }
  }
}

// /* ********** OPERATOR ARITMATIKA ********** */
// /* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
// ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
// /* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
// /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
// /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
// {
//    ListDin l;
//    int i, len;
//    CreateListDin(&l, CAP(l1));
//    NEFF(l) = NEFF(l1);
//    len = listDinLength(l1);
//    if (plus){
//        for (i=0; i<len; i++){
//            LISTELMT(l, i) = LISTELMT(l1, i) + LISTELMT(l2, i);
//        }
//    }
//    else{
//        for (i=0; i<len; i++){
//            LISTELMT(l, i) = LISTELMT(l1, i) - LISTELMT(l2, i);
//        }
//    }
//    return l;
// }
// /* ********** OPERATOR RELASIONAL ********** */
// /* *** Operasi pembandingan list : < =, > *** */
// boolean isListDinEqual(ListDin l1, ListDin l2)
// /* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
// {
//    int i = 0;
//    if (listDinLength(l1) == listDinLength(l2)){
//       while (LISTELMT(l1, i) == LISTELMT(l2, i) && i != listDinLength(l1)){
//           i++;
//       }
//       return (i == listDinLength(l1));
//    }
//    else{
//       return false;
//    }
// }
// /* ********** SEARCHING ********** */
// /* ***  Perhatian : list boleh kosong!! *** */
// IdxType indexOfListDin(ListDin l, ElType val)
// /* Search apakah ada elemen List l yang bernilai val */
// /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
// /* Jika tidak ada, mengirimkan IDX_UNDEF */
// /* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
// /* Skema Searching yang digunakan bebas */
// {
//    if (isListDinEmpty(l)){
//       return IDX_UNDEF;
//    }
//    int i = 0;
//    while ((LISTELMT(l,i) != val) && i != listDinLength(l)){
//       i++;
//    }
//    if (i == listDinLength(l)){
//       return IDX_UNDEF;
//    }
//    else{
//       return i;
//    }
// }


// /* ********** NILAI EKSTREM ********** */
// void listDinExtremes(ListDin l, ElType *max, ElType *min)
// /* I.S. List l tidak kosong */
// /* F.S. max berisi nilai maksimum l;
//         min berisi nilai minimum l */
// {
//     *max = LISTELMT(l,0);
//     *min = LISTELMT(l,0);
//     int i, len;
//     len = listDinLength(l);
//     for (i=1; i<len; i++){
//         if (LISTELMT(l,i) > *max){
//             *max = LISTELMT(l,i);
//         }
//         if (LISTELMT(l,i) < *min){
//             *min = LISTELMT(l,i);
//         }
//     }
// }
// /* ********** OPERASI LAIN ********** */
// void copyListDin(ListDin lIn, ListDin *lOut)
// /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
// /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
// /* Proses : Menyalin isi lIn ke lOut */
// {
//    dealocate(lOut);
//    CreateListDin(lOut, CAP(lIn));
//    int i;
//    for (i = 0 ; i<NEFF(lIn); i++){
//       LISTELMT(*lOut, i) = LISTELMT(lIn, i);
//    }
//    NEFF(*lOut) = NEFF(lIn);
// }
// ElType sumList(ListDin l)
// /* Menghasilkan hasil penjumlahan semua elemen l */
// /* Jika l kosong menghasilkan 0 */
// {
//    int i;
//    int sum = 0;
//    for (i = 0; i < listDinLength(l); i++){
//       sum += LISTELMT(l,i);
//    }
//    return sum;
// }

// int countVal(ListDin l, ElType val)
// /* Menghasilkan berapa banyak kemunculan val di l */
// /* Jika l kosong menghasilkan 0 */
// {
//    int count = 0;
//    int i;
//    for (i = 0; i<listDinLength(l); i++){
//       if(LISTELMT(l,i) == val){
//          count++;
//       }
//    }
//    return count;
// }

// boolean isAllEvenListDin(ListDin l)
// /* Menghailkan true jika semua elemen l genap. l boleh kosong */
// {
//    int i = 0;
//    while (LISTELMT(l,i) % 2 == 0 && i != NEFF(l)){
//       i++;
//    }
   
//    return (listDinLength(l) == i);
// }
// /* ********** SORTING ********** */
// void swap(ListDin *l, int idx1, int idx2){
//     int temp;
//     temp = LISTELMT(*l, idx1);
//     LISTELMT(*l, idx1) = LISTELMT(*l, idx2);
//     LISTELMT(*l, idx2) = temp;
// }
// void sortListDin(ListDin *l, boolean asc)
// /* I.S. l boleh kosong */
// /* F.S. Jika asc = true, l terurut membesar */
// /*      Jika asc = false, l terurut mengecil */
// /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
//    algoritma bebas */
// {
//    int i, j;
//    int len = listDinLength(*l);
//    if (len > 1){
//       if (asc) {
//          for(i = 0; i < len; i++){
//             for(j = 0; j < len-i-1; j++){
//                if (LISTELMT(*l, j) > LISTELMT(*l, j+1)){
//                   swap(l, j, j+1);
//                }
//             }
//          }
//       }
//       else{
//          for(i = 0; i < len; i++){
//             for(j = 0; j < len-i-1; j++){
//                if (LISTELMT(*l, j) < LISTELMT(*l, j+1)){
//                   swap(l, j, j+1);
//                }
//             }
//          }
//       }
//    }
// }


// /* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
// /* *** Menambahkan elemen terakhir *** */
// void insertLastListDin(ListDin *l, ElType val)
// /* Proses: Menambahkan val sebagai elemen terakhir list */
// /* I.S. List l boleh kosong, tetapi tidak penuh */
// /* F.S. val adalah elemen terakhir l yang baru */
// {
//    LISTELMT(*l, NEFF(*l)) = val;
//    NEFF(*l)++;
// }

// /* ********** MENGHAPUS ELEMEN ********** */
// void deleteLastListDin(ListDin *l, ElType *val)
// /* Proses : Menghapus elemen terakhir list */
// /* I.S. List tidak kosong */
// /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
// /*      Banyaknya elemen list berkurang satu */
// /*      List l mungkin menjadi kosong */
// {
//    *val = LISTELMT(*l, NEFF(*l)-1);
//    NEFF(*l)--;
// }
// /* ********* MENGUBAH UKURAN ARRAY ********* */
// void growList(ListDin *l, int num)
// /* Proses : Menambahkan capacity l sebanyak num */
// /* I.S. List sudah terdefinisi */
// /* F.S. Ukuran list bertambah sebanyak num */
// {
//    // ListDin temp;
//    // copyList(*l, &temp);
//    // realloc(l, (CAPACITY(*l)+num)*sizeof(int));
//    // copyList(temp, l);
//    // CAPACITY(*l) += num;

//    // ListDin temp;
//    // CreateListDin(&temp, CAPACITY(*l));
//    // copyList(*l, &temp);
//    // dealocate(l);
//    // CreateListDin(l, CAPACITY(temp)+num);
//    // copyList(temp, l);
//    // CAPACITY(*l) += num;

//    ListDin temp;
//    CreateListDin(&temp, CAP(*l));
//    copyListDin(*l, &temp);
//    int tempNeff = NEFF(*l);
//    dealocate(l);
//    CreateListDin(l, CAP(temp) + num);
//    NEFF(*l) = tempNeff;
   
//    int i;
//    for (i = 0; i < listDinLength(temp); i++) {
//       LISTELMT(*l, i) = LISTELMT(temp, i);
//    }
// }


// void shrinkList(ListDin *l, int num)
// /* Proses : Mengurangi capacity sebanyak num */
// /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
// /* F.S. Ukuran list berkurang sebanyak num. */
// {
//    // ListDin temp;
//    // copyList(*l, &temp);
//    // realloc(l, (CAPACITY(*l)-num)*sizeof(int));
//    // copyList(temp, l);
//    // CAPACITY(*l) -= num;

//    // ListDin temp;
//    // CreateListDin(&temp, CAPACITY(*l));
//    // copyList(*l, &temp);
//    // dealocate(l);
//    // CreateListDin(l, CAPACITY(temp)-num);
//    // copyList(temp, l);
//    // CAPACITY(*l) -= num;

//    ListDin temp;
//    CreateListDin(&temp, CAP(*l));
//    copyListDin(*l, &temp);
//    int tempNeff = NEFF(*l);
//    // dealocate(l);
//    CreateListDin(l, CAP(temp) - num);
//    NEFF(*l) = tempNeff;
//    if(CAP(temp) - num < NEFF(*l)){
//       NEFF(*l) = CAP(temp) - num;
//    }
   
//    int i;
//    for (i = 0; i < listDinLength(temp); i++) {
//       LISTELMT(*l, i) = LISTELMT(temp, i);
//    }
// }

// void compactList(ListDin *l)
// /* Proses : Mengurangi capacity sehingga nEff = capacity */
// /* I.S. List lidak kosong */
// /* F.S. Ukuran nEff = capacity */
// {
//    shrinkList(l, CAP(*l)-NEFF(*l));
// }