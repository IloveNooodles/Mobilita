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
    Inventory Inven, gadgetList;
    CreateInventory(&gadgetList);
    CreateInventory(&Inven);
    displayInventory(&Inven);
    if (isInventoryEmpty(Inven))
        printf("Empty\n");
    if(isInventoryFull(Inven))
        printf("Full\n");

    printf("\n **********BUY GADGET********** \n");
    int money = 2000;
    buyGadget(gadgetList,&Inven, money);

    displayInventory(&Inven);
    if (isInventoryEmpty(Inven))
        printf("Empty\n");
    if(isInventoryFull(Inven))
        printf("Full\n");

    
}