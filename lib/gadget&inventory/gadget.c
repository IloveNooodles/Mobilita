#include <stdio.h>
#include <stdlib.h>
#include "gadget.h"
#include "point.h"

void CreateInventory(List *L){
    NAME((*L).buffer[0]) = "Kain Pembungkus Waktu";
    DESC((*L).buffer[0]) = "Setiap kain pembungkus waktu dapat dipakai sekali untuk perishable item teratas pada tas agar kembali ke durasi semula.";
    PRICE((*L).buffer[0]) = 800;
    AMOUNT((*L).buffer[0]) = 0;

    NAME((*L).buffer[1])  = "Senter Pembesar";
    DESC((*L).buffer[1]) = "Senter pembesar dapat digunakan untuk meningkatkan kapasitas tas sebesar dua kali lipat, namun tidak melebihi batas maksimum kapasitas tas.";
    PRICE((*L).buffer[1]) = 1200;
    AMOUNT((*L).buffer[1]) = 0;

    NAME((*L).buffer[2])  = "Pintu Kemana Saja";
    DESC((*L).buffer[2]) = "Pintu Kemana Saja dapat digunakan sekali untuk berpindah ke lokasi yang diinginkan tanpa menambahkan unit waktu.";
    PRICE((*L).buffer[2]) = 1500;
    AMOUNT((*L).buffer[2]) = 0;

    NAME((*L).buffer[3])  = "Mesin Waktu";
    DESC((*L).buffer[3]) = "Mesin waktu dapat digunakan untuk mengurangi waktu sebanyak 50 unit. (jika waktu kurang dari 50 unit, maka waktu menjadi 0 unit).";
    PRICE((*L).buffer[3]) = 3000;
    AMOUNT((*L).buffer[3]) = 0;

    NAME((*L).buffer[4])  = "Senter Pengecil";
    DESC((*L).buffer[4]) = "Senter pengecil dapat digunakan untuk menghilangkan efek dari satu heavy item jika terdapat pada tumpukan teratas tas. Efek dari senter pengecil ini akan berlangsung sampai melakukan drop off / return pertama kali setelah penggunaan gadget ini.";
    PRICE((*L).buffer[4]) = 800;
    AMOUNT((*L).buffer[4]) = 0;
}

boolean isEmpty(List L){
    return inventoryCapacity(L)==0;
}

boolean isFull(List L){
    return inventoryCapacity(L)==5;
}

int inventoryCapacity (List L){
    int sum = 0;
    for(int i=0; i<5;i++){
        sum += AMOUNT(L.buffer[i]);
    }
    return sum;
}

void buyGadget(List L, List *I, int money){
    if (isFull(*I)){
        printf("Tidak dapat membeli gadget. Inventory penuh!");
    }
    else{
        int user_input;
        printf("Uang anda sekarang: %d Yen \n", money);
        printf("Gadget yang tersedia: \n");
        for(int i = 0; i<5 ; i++){
            printf("%d. %s (%d Yen)\n",i+1,NAME(L.buffer[i]), PRICE(L.buffer[i]));
        }
        printf("Gadget mana yang ingin Anda beli? (Ketik 0 jika ingin kembali)\n");
        printf("\n");
/*****************************INPUT**********************/
        printf("ENTER COMMAND: ");
        scanf("%d", &user_input);
        if (PRICE(L.buffer[user_input-1]) < money){
            printf("%s berhasil dibeli!\n", NAME(L.buffer[user_input-1]));
            printf("Uang Anda sekarang: %d Yen\n", money-PRICE(L.buffer[user_input-1]));
            AMOUNT((*I).buffer[user_input-1])++;
        } 
        else{
            printf("Uang tidak cukup untuk membeli gadget!\n");
        }
    }
}

void Inventory(List *I)
/* untuk melihat list gadget dan/atau menggunkan gadget*/
{
    int user_input, jumlah;
    for(int i=0; i<5 ; i++){
        printf("%d. ",i+1);
        if (AMOUNT((*I).buffer[i]) ==0)
            printf("-\n");
        else
            printf("%s\n", NAME((*I).buffer[i]));
    }
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
    printf("\n");
/*****************************INPUT**********************/
/* pilih gadget yang ingin digunkanan */
    printf("ENTER COMMAND:");
    scanf("%d", &user_input);
    if (AMOUNT((*I).buffer[user_input-1])>0){
        if (user_input == 1){
            kainPembungkusWaktu();
        }
        else if (user_input == 2){
/*********************TAS_CAP***********************/
            int tas_cap = 5;
            senterPembesar(tas_cap);
        }
        else if(user_input==3){
            pintuKemanaSaja();
        }
        else if(user_input == 4){
/*******************Time_now***********************/
            int time_now;
            mesinWaktu(time_now);
        }
        else if(user_input == 5){
            senterPengecil();
        }
        else if(user_input == 0){
            /*BACK TO MENU*/
        }
        else{
            printf("input tidak valid\n");
        }
        AMOUNT((*I).buffer[user_input-1])--;
    }
    else{
        printf("Tidak ada gadget yang dapat digunakan!\n");
    }
}

void kainPembungkusWaktu()
/* asumsi ada tambahan EXPIRY_NOW(i) pada adt  item*/
/*typedef char item_type[11];
typedef struct {
    item_type type;
    int value;
    int expiry;
    int expiry_now
} Item;
# define EXPIRY_NOW(i) (i).expiry_now
*/ 
{
    /*nunggu tas*/
}

void senterPembesar (int tas_cap){
/************************TAS_CAP**************************/
    if (tas_cap > 50)
        printf("Maaf Senter Pembesar tidak dapat digunakan. Kapasitas tas saat ini melebihi 50\n");
    else{
        tas_cap *= 2;
        printf("Senter Pembesar berhasil digunakan!\n");
        printf("Kapasitas tas saat ini: %d \n", tas_cap);
    }
}

void pintuKemanaSaja(){
    POINT loc;
    printf("Masukkan lokasi yang ingin dituju: ");
    BacaPOINT(&loc);
/**********************Location_now*******************/
    POINT location_now = loc;
}

void mesinWaktu(int time_now){
/*************************time_now*********************/
/*pastiin queue daftar pesanan di pop kalo pesanannya udah keluar*/
    if(time_now > 50)
        time_now -= 50;
    else
        time_now = 0;
}

void senterPengecil(){
    /*nunggu tas*/

}
