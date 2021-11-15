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
    int money = 5000;
    GadgetList L,I;
    createInventory(&I);
    gadgetInfo(&L);
    displayInventory(&I);
    printf("\n");
    buyGadget(L,&I,&money);
    buyGadget(L,&I,&money);
    displayInventory(&I);
    printf("\n");
      
}