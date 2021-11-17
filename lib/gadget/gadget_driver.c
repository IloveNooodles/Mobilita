#include <stdio.h>
#include <stdlib.h>
#include "gadget.h"
#include "gadget.h"
#include "../wordmachine/wordmachine.h"
#include "../wordmachine/charmachine.h"
#include "../prioqueue/prioqueue.h"
#include "../item/item.h"
#include "../stack/stack.h"
#include "../point/point.h"

int main(){
    GadgetList L, I;
    int money = 5000;
    createInventory(&I);
    gadgetInfo(&L);
    buyGadget(L,&I,&money);
    displayInventory(&I);
}