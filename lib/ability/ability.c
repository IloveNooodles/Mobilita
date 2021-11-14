#include "ability.h"

void createAblity(Ability b){
  TIME(b) = 0;
  FREEZE(b) = true;
  HEAVYITEM(b) = false;
}

void checkHeavyIteminBag(Ability b, Stack s){
  if(HEAVY(s) == 0){
    HEAVYITEM(b) = true;
  }else{
    HEAVYITEM(b) = false;
  }
}

void activateSpeedBoost(Ability b){
  if(!HEAVYITEM(b)){ //kalogaada heavy item
    FREEZE(b) = true;
    TIME(b) = 10;
  }
}

void deactivateSpeedBoost(Ability b){
  if(TIME(b) == 0 && FREEZE(b)){
    FREEZE(b) = false;
  }
}

void activateIncreaseCapacity(){
  increaseCapacity(1);
}

void activateReturnToSender(Ability b, Stack s, List l1, List l2){
  // NOTE belom dicek karena ngantuk
  if (RETURNTOSENDER(b) && TYPE(tipeItem(TOP(s))) != 'V'){
    Pesanan returned;
    Pesanan addReturned;
    pop(&s, &returned);
    deleteLast(&l1, &addReturned);
    insertFirst(&l2, addReturned);
    RETURNTOSENDER(b) = false;
  }
}