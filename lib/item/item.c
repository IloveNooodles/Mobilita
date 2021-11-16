/* ADT Item */
/* Definisi ADT Item yang merepresentasikan elemen Stack */
/* Contributor : 13520042 */

#include <stdio.h>
#include "item.h"

void createItem(Item *item, char type, int expiry) {
    if (type == 'N') {
        TYPE(*item) = 'N';
        TYPE_DESC(*item) = "Normal";
        VALUE(*item) = 200;
        EXPIRY(*item) = expiry;
        EXPIRY_NOW(*item) = expiry;
    }
    else if (type == 'H') {
        TYPE(*item) = 'H';
        TYPE_DESC(*item) = "Heavy";
        VALUE(*item) = 400;
        EXPIRY(*item) = expiry;
        EXPIRY_NOW(*item) = expiry;
    }
    else if (type == 'P') {
        TYPE(*item) = 'P';
        TYPE_DESC(*item) = "Perishable";
        VALUE(*item) = 400;
        EXPIRY(*item) = expiry;
        EXPIRY_NOW(*item) = expiry;
    }else if(type == 'V'){
      TYPE(*item) = 'V';
      TYPE_DESC(*item) = "VIP";
      VALUE(*item) = 600;
      EXPIRY(*item) = expiry;
      EXPIRY_NOW(*item) = expiry;
    }
}

void minusExpiry(Item *i){
  if(i->type == 'P'){
    i->expiry_now--;
  }
}

void displayItem(Item item){

  printf("Item: %s ", TYPE_DESC(item));
  printf("Harga: %d ", VALUE(item));
  printf("Expire: %d\n", EXPIRY_NOW(item));
}
