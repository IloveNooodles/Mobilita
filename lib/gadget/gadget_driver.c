#include <stdio.h>
#include <stdlib.h>
#include "gadget.h"
#include "gadget.c"
#include "../wordmachine/wordmachine.c"
#include "../wordmachine/charmachine.c"
#include "../prioqueue/prioqueue.c"
#include "../item/item.c"
#include "../stack/stack.c"
#include "../point/point.c"

int main(){
    GadgetList L, I;
    int money = 5000;
    createInventory(&I);
    gadgetInfo(&L);
    buyGadget(L,&I,&money);
    displayInventory(&I);
}