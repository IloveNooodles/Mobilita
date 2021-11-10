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

void activateReturnToSender(Ability b);