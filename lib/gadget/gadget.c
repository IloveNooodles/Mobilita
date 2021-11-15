#include <stdio.h>
#include <stdlib.h>
#include "gadget.h"

void createInventory(GadgetList *I){
    for (int i=0 ; i<INVENTORY_CAP; i++){
        ID_GADGET((*I).buffer[i]) = ID_UNDEF;
    }
}

int inventoryCapacity (GadgetList I){
    int amount = 0;
    for(int i=0; i<INVENTORY_CAP; i++){
        if(ID_GADGET(I.buffer[i]) != ID_UNDEF){
            amount ++;
        }
    }
    return amount;
}

boolean isInventoryEmpty (GadgetList I){
    return inventoryCapacity(I)==0;
}

boolean isInventoryFull(GadgetList I){
    return inventoryCapacity(I) == 5;
}



void gadgetInfo(GadgetList *L){
    createInventory(L);
    ID_GADGET((*L).buffer[0]) = 0;
    NAME((*L).buffer[0]) = "Kain Pembungkus Waktu";
    PRICE((*L).buffer[0]) = 800;

    ID_GADGET((*L).buffer[1]) = 1;
    NAME((*L).buffer[1])  = "Senter Pembesar";
    PRICE((*L).buffer[1]) = 1200;

    ID_GADGET((*L).buffer[2]) = 2;
    NAME((*L).buffer[2])  = "Pintu Kemana Saja";
    PRICE((*L).buffer[2]) = 1500;

    ID_GADGET((*L).buffer[3]) = 3;
    NAME((*L).buffer[3])  = "Mesin Waktu";
    PRICE((*L).buffer[3]) = 3000;

    ID_GADGET((*L).buffer[4]) = 4;
    NAME((*L).buffer[4])  = "Senter Pengecil";
    PRICE((*L).buffer[4]) = 800;
}

void addGadget(GadgetList *I, GadgetList L, int IDs){
    for(int i=0; i<INVENTORY_CAP; i++){
        if (ID_GADGET((*I).buffer[i]) == ID_UNDEF){
            ID_GADGET((*I).buffer[i]) = IDs;
            NAME((*I).buffer[i]) = NAME(L.buffer[IDs]);
            break;
        }
    }
}

void buyGadget(GadgetList L, GadgetList *I, int *money){
    if (isInventoryFull(*I)){
        printf("Tidak dapat membeli gadget. Inventory penuh!\n");
    }
    else{
        int user_input;
        printf("Uang anda sekarang: %d Yen \n", *money);
        printf("Gadget yang tersedia: \n");
        for(int i = 0; i<5 ; i++){
            printf("%d. %s (%d Yen)\n",i+1,NAME(L.buffer[i]), PRICE(L.buffer[i]));
        }
        printf("Gadget mana yang ingin Anda beli? (Ketik 0 jika ingin kembali)\n");
        printf("\n");

        printf("ENTER COMMAND: ");
        startWord();
        user_input = atoi(currentWord.contents);
        if(user_input> 0 && user_input<=5){
            if (PRICE(L.buffer[user_input-1]) < *money){
                printf("%s berhasil dibeli!\n", NAME(L.buffer[user_input-1]));
                *money = *money- PRICE(L.buffer[user_input-1]);
                printf("Uang Anda sekarang: %d Yen\n", *money );
                addGadget(I,L,user_input-1);
            } 
            else{
                printf("Uang Anda tidak cukup untuk membeli gadget!\n");
            }
        }else if(user_input == 0){
          return;
        }
        else{
            printf("input tidak valid\n");
        }
        
    }
}

void kainPembungkusWaktu(Stack *s, List *l){
    boolean found = false;
    for(int i = IDX_TOP(*s); i >= 0; i--){
        if ((*s).buffer[i].tipeItem.type == 'P'){
            EXPIRY_NOW((*s).buffer[i].tipeItem) = EXPIRY((*s).buffer[i].tipeItem);
            found = true;
            break;
        }
    }
    if (!found){
        printf("Tidak ditemukan perishable item pada tas!\n");
    }
    else{
        onePerishableList(l);
        printf("Kain pembungkus waktu berhasil digunakan!\n");
    }
}

void senterPembesar (int *stack_capacity){
    if (*stack_capacity > 50)
        printf("Maaf Senter Pembesar tidak dapat digunakan. Kapasitas tas saat ini melebihi 50\n");
    else{
        *stack_capacity *= 2;
        printf("Senter Pembesar berhasil digunakan!\n");
        printf("Kapasitas tas saat ini: %d \n", *stack_capacity);
    }
}

// void pintuKemanaSaja(Game g, Lokasi *loc){
//     printf("Masukkan lokasi yang ingin dituju: ");
//     // BacaPOINT(&loc);
//     // POINT location_now = loc;
//     printf("Pintu Kemana Saja berhasil digunakan!\n");
// }

void mesinWaktu(int *time_now, Stack *s, List *l){
    int selisih;
    if(*time_now > 50){
      *time_now -= 50;
      selisih = 50;
    }
    else{
      selisih = *time_now;
      *time_now = 0;
    }
    //Loop buat tas
    for(int i = IDX_TOP(*s); i >= 0; i--){
        if ((*s).buffer[i].tipeItem.type == 'P'){
            if(EXPIRY_NOW((*s).buffer[i].tipeItem) + selisih >= EXPIRY((*s).buffer[i].tipeItem)){
              EXPIRY_NOW((*s).buffer[i].tipeItem) = EXPIRY((*s).buffer[i].tipeItem);
            }else{
              EXPIRY_NOW((*s).buffer[i].tipeItem) += selisih;
            }
        }
    }
    allPerishableList(l, selisih);
    //Loop buat list
    printf("Mesin Waktu berhasil digunakan!\n");
}
