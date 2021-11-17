#include "ability.h"
#include <stdio.h>

int main(){
  Lokasi currentLocation;
  currentLocation.koor.X = 1;
  currentLocation.koor.Y = 1;
  currentLocation.tipeBangunan = 'A';
  Ability b;
  createAbility(&b);
  Stack tas;
  CreateStack(&tas);
  Item i;
  createItem(&i, 'H', -1);
  Pesanan p;
  Pesanan temp;
  p.dropOff = 'A';
  p.pickUp = 'B';
  p.t = '1';
  p.tipeItem = i;
  push(&tas, p);
  createItem(&i, 'H', -1);
  p.tipeItem = i;
  push(&tas, p);
  displayPesanan(TOP(tas));
  displayPesanan(tas.buffer[1]);
  if(getTipeBangunan(currentLocation) == DROPOFF(TOP(tas))){
    printf("Item berhasil didropoff\n");
    pop(&tas, &temp);
    switch(TYPE(tipeItem(temp))){
      case 'V':
          printf("VIP ITEM\n");
          // RETURNTOSENDER(b) = true;
          break;
      case 'H':
          printf("HeavyItem\n");
          checkHeavyIteminBag(&b, tas);
          if(!HEAVYITEM(b)){
            printf("AKTIF BOS");
            activateSpeedBoost(&b);
          }else{
            printf("gak aktif gan. ada heavy di tas");
          }
          
          break;
      case 'P':
          printf("Perishable ITEM\n");
          // activateIncreaseCapacity();
          break;
      default:
          printf("NORMAL ITEM\n");
          break;
    }
  }
}