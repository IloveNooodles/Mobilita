#ifndef GADGET_H
#define GADGET_H

#include "../utility/boolean.h"
#include "../point/point.h"
#include "../stack/stack.h"
#include "../item/item.h"
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

void buyGadget(Inventory L, Inventory *I, int money);
void kainPembungkusWaktu(Stack *s);
void senterPembesar (int stack_capacity);
void pintuKemanaSaja();
void mesinWaktu(int time_now);
void senterPengecil();
void senterPengecil();
void displayInventory(Inventory *I);

#endif