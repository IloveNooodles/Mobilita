#ifndef GADGET_H
#define GADGET_H

#include "boolean.h"
#include <stdlib.h>

typedef struct {
    char* name;
    char* desc;
    int price;
    int amount;
}Gadget;

typedef struct{
    Gadget buffer[5];
}List;

#define NAME(L) (L).name
#define DESC(L) (L).desc
#define PRICE(L) (L).price
#define AMOUNT(L) (L).amount

void CreateInventory (List *L);
/* I.S. sembarang */
/*F.S. terbentuk daftar gadget */

boolean isEmpty(List L);
/* Mengirim true jika L kosong inventoryCapacity(L) = 0;*/

boolean isFull(List L);
/* Mengirim true jika L penuh inventoryCapacity(L) = 5;*/

int inventoryCapacity (List L);
/*Mengirimkan kapasitas inventory saat ini*/

#endif