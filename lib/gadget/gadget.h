#ifndef GADGET_H
#define GADGET_H

#include "../utility/boolean.h"
#include <stdlib.h>

typedef struct {
    char* name;
    char* desc;
    int price;
    int amount;
}Gadget;

typedef struct{
    Gadget buffer[5];
}Inventory;

#define NAME(L) (L).name
#define DESC(L) (L).desc
#define PRICE(L) (L).price
#define AMOUNT(L) (L).amount

void CreateInventory (Inventory *L);
/* I.S. sembarang */
/*F.S. terbentuk daftar gadget */

boolean isInventoryEmpty(Inventory L);
/* Mengirim true jika L kosong inventoryCapacity(L) = 0;*/

boolean isInventoryFull(Inventory L);
/* Mengirim true jika L penuh inventoryCapacity(L) = 5;*/

int inventoryCapacity (Inventory L);
/*Mengirimkan kapasitas inventory saat ini*/

#endif