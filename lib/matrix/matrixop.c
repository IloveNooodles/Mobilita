/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#include <stdio.h>
#include "matrix.h"

/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m){
  ROWS(*m) = nRow;
  COLS(*m) = nCol;
}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j){
  return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m){
  return ROWS(m) - 1;
}
/* Mengirimkan Index baris terbesar m */
Index getLastIdxCol(Matrix m){
  return COLS(m) - 1;
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, Index i, Index j){
  return(i >= 0 && i < ROWS(m) && j >= 0 && j < COLS(m));
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, Index i){
  return MATRIXELMT(m, i, i);
}
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes){
  CreateMatrix(ROWS(mIn), COLS(mIn), mRes);
  for(int i = 0; i < ROWS(mIn); i++){
    for(int j = 0; j < COLS(mIn); j++){
      MATRIXELMT(*mRes, i, j) = MATRIXELMT(mIn, i, j);
    }
  }
}
/* Melakukan assignment MRes = MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
  CreateMatrix(nRow, nCol, m);
  for(int i = 0; i < nRow; i++){
    for(int j = 0; j < nCol; j++){
      int x;
      scanf("%d", &x);
      MATRIXELMT(*m, i, j) = x;
    }
  }
}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m){
  for(int i = 0; i < ROWS(m); i++){
    for(int j = 0; j < COLS(m); j++){
      printf("%d", MATRIXELMT(m, i, j));
      if(j != COLS(m) - 1){
        printf(" ");
      }
    }
    if(i != ROWS(m) - 1){
      printf("\n");
    }
  }
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
  Matrix m3;
  CreateMatrix(ROWS(m1), COLS(m1), &m3);
  for(int i = 0; i < ROWS(m1); i++){
    for(int j = 0; j < COLS(m1); j++){
      MATRIXELMT(m3, i, j) = MATRIXELMT(m1, i, j) + MATRIXELMT(m2, i, j);
    }
  }
  return m3;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2){
  Matrix m3;
  CreateMatrix(ROWS(m1), COLS(m2), &m3);
  for(int i = 0; i < ROWS(m1); i++){
    for(int j = 0; j < COLS(m1); j++){
      MATRIXELMT(m3, i, j) = MATRIXELMT(m1, i, j) - MATRIXELMT(m2, i, j);
    }
  }
  return m3;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMatrix(Matrix m1, Matrix m2){
  Matrix m3;
  CreateMatrix(ROWS(m1), COLS(m2), &m3);
  for(int i = 0; i < ROWS(m3); i++){
    for(int j = 0; j < COLS(m3); j++){
      int ans = 0;
      for(int k = 0; k < COLS(m1); k++){
        ans += MATRIXELMT(m1, i, k) * MATRIXELMT(m2, k, j);
      }
      MATRIXELMT(m3, i, j) = ans;
    }
  }
  return m3;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyConst(Matrix m, ElType x){
  Matrix m2;
  CreateMatrix(ROWS(m), COLS(m), &m2);
  for(int i = 0; i < ROWS(m); i++){
    for(int j = 0 ; j < COLS(m); j++){
      MATRIXELMT(m2, i, j) = MATRIXELMT(m, i, j) * x;
    }
  }
  return m2;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyConst(Matrix *m, ElType k){
  for(int i = 0; i < ROWS(*m); i++){
    for(int j = 0 ; j < COLS(*m); j++){
      MATRIXELMT(*m, i, j) *= k;
    }
  }
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2){
  boolean eq = (count(m1) == count(m2) && getLastIdxCol(m1) == getLastIdxCol(m2));
  if(eq){
    for(int i = 0; i < ROWS(m1); i++){
      for(int j = 0; j < COLS(m1); j++){
        if(MATRIXELMT(m1, i, j) != MATRIXELMT(m2, i, j)){
          eq = false;
          break;
        }
      }
    }
  }
  return eq;
}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isNotEqual(Matrix m1, Matrix m2){
  return (!isEqual(m1, m2));
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isSizeEqual(Matrix m1, Matrix m2){
  return COLS(m1) == COLS(m2) && ROWS(m1) == ROWS(m2);
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */

/* ********** Operasi lain ********** */
int count(Matrix m){
  return ROWS(m) * COLS(m);
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
  return ROWS(m) == COLS(m);
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric(Matrix m){
  boolean eq = isSquare(m);
  if(eq){
    for(int i = 0; i < ROWS(m); i++){
      for(int j = 0; j < COLS(m); j++){
        if(MATRIXELMT(m,i,j) != MATRIXELMT(m,j,i)){
          eq = false;
          break;
        }
      }
    }
  }
  return eq;
}
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity(Matrix m){
  boolean eq = isSquare(m);
  if(eq){
    for(int i = 0; i < ROWS(m); i++){
      for(int j = 0; j < COLS(m); j++){
        if(i == j && MATRIXELMT(m, i, j) != 1){
          eq = false;
          break;
        }else if(i != j && MATRIXELMT(m, i, j) != 0){
          eq = false;
          break;
        }
      }
    }
  }
  return eq;
}
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse(Matrix m){
  double Cur = 0;
  double total = ((double) count(m)) * 0.05;
  for(int i = 0; i < ROWS(m); i++){
    for(int j = 0; j < COLS(m); j++){
      if(MATRIXELMT(m, i, j) != 0)Cur++;
    }
  }
  return Cur <= total;
}
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix inverse1(Matrix m){
  return multiplyConst(m, -1);
}
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
void pInverse1(Matrix *m){
  pMultiplyConst(m, -1);
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */

void swapRow(Matrix *m, int row1, int row2){
  for(int i = 0; i < COLS(*m); i++){
    int temp = MATRIXELMT(*m, row1, i);
    MATRIXELMT(*m, row1, i) = MATRIXELMT(*m, row2, i);
    MATRIXELMT(*m,row2, i) = temp;
  }
}

//square matrix
float determinant(Matrix m){
  int a, b, index;
  float total = 1, det = 1;
  int size = ROWS(m);
  int temp[size+1];
  Matrix c;
  copyMatrix(m, &c);
  for(int i = 0; i < size; i++){
    index = i;
    while(MATRIXELMT(c, index, i) == 0 && index < size){
      index++;
    }
    if(index == size)continue;
    if(index != i){
      swapRow(&c, index, i);
      det = -det;
    }
    for(int j = 0; j < size; j++){
      temp[j] = MATRIXELMT(c, i, j);
    }
    for(int j = i+1; j < size; j++){
      a = temp[i];
      b = MATRIXELMT(c, j, i);
      for(int k = 0; k < size; k++){
        MATRIXELMT(c, j, k) = a*MATRIXELMT(c,j,k) - b*temp[k];
      }
      total = total * a;
    }
  }
  for(int i = 0; i < size; i++){
    det *= getElmtDiagonal(c, i);
  }
  return det/total;
}

/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
void transpose(Matrix *m){
  Matrix c;
  CreateMatrix(COLS(*m), ROWS(*m), &c);
  for(int i = 0; i < ROWS(*m); i++){
    for(int j = 0; j < COLS(*m); j++){
      MATRIXELMT(c, j, i) = MATRIXELMT(*m, i, j);
    }
  }
  copyMatrix(c, m);
}

float rowMean(Matrix m, Index i){
  float sum = 0;
  for(int j = 0; j < COLS(m); j++){
    sum += MATRIXELMT(m, i, j);
  }
  return sum/COLS(m);
}

float colMean(Matrix m, Index i){
  float sum = 0;
  for(int j = 0; j < ROWS(m); j++){
    sum += MATRIXELMT(m, j, i);
  }
  return sum/ROWS(m);
}

void rowExtremes(Matrix m, Index i, ElType *max, ElType *min){
  for(int j = 0; j < COLS(m); j++){
    if(j == 0){
      *max = MATRIXELMT(m, i, j);
      *min = MATRIXELMT(m, i, j);
    }else{
      if(*max < MATRIXELMT(m, i, j)){
        *max = MATRIXELMT(m, i, j);
      }
      if(*min > MATRIXELMT(m, i, j)){
        *min = MATRIXELMT(m, i, j);
      }
    }
  }
}

void colExtremes(Matrix m, Index i, ElType *max, ElType *min){
  for(int j = 0; j < ROWS(m); j++){
    if(j == 0){
      *max = MATRIXELMT(m, j, i);
      *min = MATRIXELMT(m, j, i);
    }else{
      if(*max < MATRIXELMT(m, j, i)){
        *max = MATRIXELMT(m, j, i);
      }
      if(*min > MATRIXELMT(m, j, i)){
        *min = MATRIXELMT(m, j, i);
      }
    }
  }
}

int countValOnRow(Matrix m, Index i, ElType val){
  int count = 0;
  for(int j = 0; j < COLS(m); j++){
    if(val == MATRIXELMT(m, i,j)){
      count++;
    }
  }
  return count;
}

int countValOnCol(Matrix m, Index i, ElType val){
  int count = 0;
  for(int j = 0; j < ROWS(m); j++){
    if(val == MATRIXELMT(m, j, i)){
      count++;
    }
  }
  return count;
}


/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */