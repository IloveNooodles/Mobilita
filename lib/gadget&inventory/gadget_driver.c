#include <stdio.h>
#include <stdlib.h>
#include "gadget.h"
#include "../point/point.h"
#include "../stack/stack.h"
#include "../item/item.h"
#include "gadget.c"
#include "../point/point.c"
#include "../stack/stack.c"
#include "../item/item.c"

int main(){
    List Inven, gadgetList;
    CreateInventory(&gadgetList);
    CreateInventory(&Inven);
    Inventory(&Inven);
    if (isEmpty(Inven))
        printf("Empty\n");
    if(isFull(Inven))
        printf("Full\n");

    printf("\n **********BUY GADGET********** \n");
    int money = 2000;
    buyGadget(gadgetList,&Inven, money);

    Inventory(&Inven);
    if (isEmpty(Inven))
        printf("Empty\n");
    if(isFull(Inven))
        printf("Full\n");

    
}