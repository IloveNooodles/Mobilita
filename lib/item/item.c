/* ADT Item */
/* Definisi ADT Item yang merepresentasikan elemen Stack */
/* Contributor : 13520042 */

#include <string.h>
#include "item.h"

void createItem(Item *item, char type, int expiry) {
    if (type == 'N') {
        strcpy(TYPE(*item), "normal");
        VALUE(*item) = 200;
        EXPIRY(*item) = 0;
    }
    else if (type == 'H') {
        strcpy(TYPE(*item), "heavy");
        VALUE(*item) = 400;
        EXPIRY(*item) = 0;
    }
    else if (type == 'P') {
        strcpy(TYPE(*item), "perishable");
        VALUE(*item) = 400;
        EXPIRY(*item) = expiry;
    }
}
