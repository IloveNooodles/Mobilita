/* ADT Item */
/* Definisi ADT Item yang merepresentasikan elemen Stack */
/* Contributor : 13520042 */

#include <string.h>
#include "stdio.h"
#include "item.h"

void createItem(Item *item, char type) {
    if (type == 'N') {
        strcpy(TYPE(*item), "normal");
        VALUE(*item) = 200;
        EXPIRY(*item) = -1;
    }
    else if (type == 'H') {
        strcpy(TYPE(*item), "heavy");
        VALUE(*item) = 400;
        EXPIRY(*item) = -1;
    }
    else if (type == 'P') {
        int expiry;
        scanf("%d", expiry);
        strcpy(TYPE(*item), "perishable");
        VALUE(*item) = 400;
        EXPIRY(*item) = expiry;
    }else if(type == 'V'){
      strcpy(TYPE(*item), "vip");
      VALUE(*item) = 600;
      EXPIRY(*item) = -1;
    }
    else{
      printf("Tidak ada item dengan tipe tersebut");
    }
}

void displayItem(Item item){
  printf("Item: %s ", TYPE(item));
  printf("Harga: %d ", VALUE(item));
  printf("Expire: %d\n", EXPIRY(item));
}
