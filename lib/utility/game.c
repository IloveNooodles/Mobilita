#include <stdio.h>
#include "game.h"

Lokasi peta[10][15]; //N x M isi dengan nol kemungkinan bisa diisi sama spasi / whitespace;
peta[1][1] = 1;
// peta[1][1] = 1;
// buat tipe data lokasi sebanyak 17 berarti ini ada 2 tipe data kayaknya  buat lokasi
// 1 character 1 point
//adjacency headquarters dgn lokasi lain
//Masukin pesanan

// Konfigurasi file yang akan diinput pada awal game akan berisi sebagai berikut:
// ● Ukuran peta (10 <= N <= 20; 10 <= M <= 30)
// ● Koordinat Headquarters
// ● Jumlah lokasi (4 <= L <= 26)
// ● Karakter lokasi dan koordinat lokasi
// ● Matriks hubungan lokasi (adjacency matrix), di mana elemen pertama menunjukkan
// adjacency Headquarters dengan lokasi lain
// ● Jumlah pesanan (5 <= P <= 30)
// ● Waktu pesanan masuk, bangunan lokasi pick up, bangunan lokasi drop off, dan jenis
// item sebagai berikut:
// ○ N → Normal Item
// ○ H → Heavy Item
// ○ P → Perishable Item
// ■ Untuk setiap perishable item akan ada tambahan input waktu item,
// menyatakan kapan perishable item tersebut akan hangus
// ○ V → VIP Item
// Berikut adalah contoh konfigurasi file:

// 10 15
// 1 1
// 17
// A 10 1
// B 1 15
// C 1 9
// D 1 13
// E 2 3
// F 3 1
// G 3 8
// H 3 14
// I 4 5
// J 5 12
// K 6 3
// L 7 10
// M 8 2
// N 8 6
// O 8 15
// P 9 13
// Q 10 3
// 0 0 0 1 0 1 1 0 0 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1
// 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0
// 1 0 0 0 1 0 0 1 1 0 0 0 0 0 0 0 0 0
// 0 0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 1 1 0 1 0 0 0 0 0 0 0 0
// 1 0 0 0 0 1 0 0 0 1 0 1 0 0 0 0 0 0
// 0 0 0 1 0 1 0 0 1 1 1 0 0 0 0 0 0 0
// 0 0 1 1 1 0 0 1 0 0 1 0 0 0 0 1 0 0
// 0 0 0 0 0 1 1 1 0 0 1 1 1 0 0 0 0 0
// 0 0 0 0 0 0 0 1 1 1 0 0 1 0 0 1 0 0
// 0 0 0 0 0 0 1 0 0 1 0 0 1 1 1 0 0 0
// 0 0 0 0 0 0 0 0 0 1 1 1 0 0 1 0 1 0
// 0 1 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 1
// 0 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 1
// 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 1 0
// 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0
// 0 1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0
// 10
// 1 G N N
// 3 G N H
// 2 B M N
// 1 M B H
// 5 C D N
// 3 F E N
// 10 P Q P 20
// 5 G N P 10
// 8 O P V
// 8 Q L V