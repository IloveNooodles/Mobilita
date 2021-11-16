#ifndef GADGET_H
#define GADGET_H

#include "../utility/boolean.h"
#include "../list_linked/list_linked.h"
#include "../point/point.h"
#include "../stack/stack.h"
#include "../item/item.h"
#include "../lokasi/lokasi.h"
#include "../prioqueue/prioqueue.h"
#include "../wordmachine/wordmachine.h"
#include "../wordmachine/charmachine.h"
#include "../listdin/listdin.h"
#include <stdlib.h>

#define INVENTORY_CAP 5
#define ID_UNDEF -999

typedef struct {
    int id;
    char* name;
    int price;
}Gadget;

typedef struct{
    Gadget buffer[INVENTORY_CAP];
}GadgetList;


#define ID_GADGET(L) (L).id
#define NAME(L) (L).name
#define PRICE(L) (L).price

void createInventory(GadgetList *I);
int inventoryCapacity (GadgetList I);
boolean isInventoryEmpty (GadgetList I);
boolean isInventoryFull(GadgetList I);
void gadgetInfo (GadgetList *L);
/* I.S. sembarang */
/*F.S. terbentuk daftar gadget */
void addGadget(GadgetList *I, GadgetList L, int IDs);

void buyGadget(GadgetList L, GadgetList *I, int *money);
void kainPembungkusWaktu(Stack *s, List *l);
void senterPembesar (int *stack_capacity);
void mesinWaktu(int *time_now, Stack *s, List *l);

#endif