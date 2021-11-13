#include <stdio.h>
#include <stdlib.h>
#include "gadget.h"
#include "../point/point.h"
#include "../stack/stack.h"
#include "../item/item.h"

void CreateInventory(Inventory *L){
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

boolean isInventoryEmpty(Inventory L){
    return inventoryCapacity(L)==0;
}

boolean isInventoryFull(Inventory L){
    return inventoryCapacity(L)==5;
}

int inventoryCapacity (Inventory L){
    int sum = 0;
    for(int i=0; i<5;i++){
        sum += AMOUNT(L.buffer[i]);
    }
    return sum;
}

void buyGadget(Inventory L, Inventory *I, int money){
    if (isInventoryFull(*I)){
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
        if(user_input>=0 && user_input<=5){
            if (PRICE(L.buffer[user_input-1]) < money){
                printf("%s berhasil dibeli!\n", NAME(L.buffer[user_input-1]));
                printf("Uang Anda sekarang: %d Yen\n", money-PRICE(L.buffer[user_input-1]));
                AMOUNT((*I).buffer[user_input-1])++;
            } 
            else{
                printf("Uang tidak cukup untuk membeli gadget!\n");
            }
        }
        else{
            printf("input tidak valid\n");
        }
        
    }
}


void kainPembungkusWaktu(Stack *s)
{
    boolean found = false;
    for(int i = IDX_TOP(*s); i >= 0;i--){
        if (TYPE((*s).buffer[i].tipeItem) == 'P'){
            //FIXME bagian ini jadinya buat tas diganti jadi tipe pesanan coba di fix lagi
            // EXPIRY_NOW((*s).buffer[i]) = EXPIRY((*s).buffer[i]);
            found = true;
            break;
        }
    }
    if (found == false){
        printf("Tidak ditemukan perishable item pada tas!\n");
    }
    else{
        printf("Kain pembungkus waktu berhasil digunakan!\n");
    }
}

void senterPembesar (int stack_capacity){
    if (stack_capacity > 50)
        printf("Maaf Senter Pembesar tidak dapat digunakan. Kapasitas tas saat ini melebihi 50\n");
    else{
        stack_capacity *= 2;
        printf("Senter Pembesar berhasil digunakan!\n");
        printf("Kapasitas tas saat ini: %d \n", stack_capacity);
    }
}

void pintuKemanaSaja(){
// TODO: not fixed
    POINT loc;
    printf("Masukkan lokasi yang ingin dituju: ");
    BacaPOINT(&loc);
/**********************Location_now*******************/
    POINT location_now = loc;
    printf("Pintu Kemana Saja berhasil digunakan!\n");
}

void mesinWaktu(int time_now){
//TODO : not fixed
/*************************time_now*********************/
/*pastiin queue daftar pesanan di pop kalo pesanannya udah keluar*/
    if(time_now > 50)
        time_now -= 50;
    else
        time_now = 0;
    printf("Mesin Waktu berhasil digunakan!\n");
}

void senterPengecil(){

}

void displayInventory(Inventory *I)
/* untuk melihat list gadget dan/atau menggunkan gadget*/
{
    int user_input, jumlah;
    for(int i=0; i<5 ; i++){
        printf("%d. ",i+1);
        if (AMOUNT((*I).buffer[i]) ==0)
            printf("-\n");
        else{
            printf("%s ", NAME((*I).buffer[i]));
            printf("(%d)\n", AMOUNT((*I).buffer[i]));
        }
    }
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
    printf("\n");
/*****************************INPUT**********************/
/* pilih gadget yang ingin digunkanan */
    printf("ENTER COMMAND:");
    scanf("%d", &user_input);
    if(user_input != 0 && user_input<=5){
        if (AMOUNT((*I).buffer[user_input-1])>0){
            if (user_input == 1){
                Stack s; /* tas*/
                kainPembungkusWaktu(&s);
            }
            else if (user_input == 2){
                senterPembesar(stack_capacity);
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
            AMOUNT((*I).buffer[user_input-1])--;
        }
        else{
            printf("Tidak ada gadget yang dapat digunakan!\n");
        }
    }
    else if(user_input ==0 ){
        printf("Kembali ke menu\n");
        /* back to menu*/
    }
    else{
        printf("input tidak valid\n");
    }
    
}
