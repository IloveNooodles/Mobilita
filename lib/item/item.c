/* ADT Item */
/* Definisi ADT Item yang merepresentasikan elemen Stack */
/* Contributor : 13520042 */

#include <string.h>
#include "stdio.h"
#include "item.h"

void createItem(Item *item, char type) {
    if (type == 'N') {
        TYPE(*item) = 'N';
        TYPE_DESC(*item) = "Normal";
        VALUE(*item) = 200;
        EXPIRY(*item) = -1;
        EXPIRY_NOW(*item) = EXPIRY(*item);
    }
    else if (type == 'H') {
        TYPE(*item) = 'H';
        TYPE_DESC(*item) = "Heavy";
        VALUE(*item) = 400;
        EXPIRY(*item) = -1;
        EXPIRY_NOW(*item) = EXPIRY(*item);
    }
    else if (type == 'P') {
        int expiry;
        scanf("%d", &expiry);
        TYPE(*item) = 'P';
        TYPE_DESC(*item) = "Perishable";
        VALUE(*item) = 400;
        EXPIRY(*item) = expiry;
        EXPIRY_NOW(*item) = expiry;
    }else if(type == 'V'){
      TYPE(*item) = 'V';
      TYPE_DESC(*item) = "VIP";
      VALUE(*item) = 600;
      EXPIRY(*item) = -1;
      EXPIRY_NOW(*item) = EXPIRY(*item);
    }
    else{
      printf("Tidak ada item dengan tipe tersebut");
    }
}

void displayItem(Item item){
  printf("Item: %s ", TYPE_DESC(item));
  printf("Harga: %d ", VALUE(item));
  printf("Expire: %d\n", EXPIRY_NOW(item));
}
