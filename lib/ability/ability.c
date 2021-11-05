#include "ability.h"

void createAblity(Ability b){
  TIME(b) = 0;
  FREEZE(b) = true;
  HEAVYITEM(b) = false;
  BONUSCAPACITY(b) = 0;
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

void activateIncreaseCapacity(Ability b){
  setCapacity(BONUSCAPACITY(b));
}
void activateReturnToSender(Ability b);