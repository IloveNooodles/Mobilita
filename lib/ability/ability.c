#include "ability.h"
#include <stdio.h>

void createAbility(Ability *b){
  TIME(*b) = 0;
  FREEZE(*b) = true;
  HEAVYITEM(*b) = false;
  SENTERPENGECIL(*b) = false;
  RETURNTOSENDER(*b) = false;
}

void checkHeavyIteminBag(Ability *b, Stack s){
  if(HEAVY(s) == 0){
    HEAVYITEM(*b) = false;
  }else{
    HEAVYITEM(*b) = true;
  }
}

void activateSpeedBoost(Ability *b){
  if(!HEAVYITEM(*b)){
    FREEZE(*b) = true;
    TIME(*b) = 10;
    printf("Speed Boost Berhasil teraktivasi!\n");
  }else{
    printf("Speed Boost gagal teraktivasi\n");
  }
}

void deactivateSpeedBoost(Ability *b){
  if(TIME(*b) == 0 && FREEZE(*b)){
    FREEZE(*b) = false;
    printf("Speed Boost telah di deaktivasi!\n");
  }
}

void activateIncreaseCapacity(){
  increaseCapacity(1);
  printf("Ability increase capacity telah aktif!\n");
  printf("Kapasitas tas bertambah sebanyak 1!\n");
}

void activateReturnToSender(Ability *b, Stack *s, List *Todo, List *inProgress){
  if (RETURNTOSENDER(*b) && TYPE(tipeItem(TOP(*s))) != 'V'){
    Pesanan returned;
    Pesanan addReturned;
    pop(s, &returned);
    deleteLast(inProgress, &addReturned);
    EXPIRY_NOW(addReturned.tipeItem) = EXPIRY(addReturned.tipeItem);
    insertLast(Todo, addReturned);
    RETURNTOSENDER(*b) = false;
    printf("%s berhasil dikembalikan ke Pick Up Point %c\n", TYPE_DESC(tipeItem(returned)), DROPOFF(returned));
  }else{
    printf("Mobita tidak bisa memakai Ability Return To Sender!\n");
  }
}