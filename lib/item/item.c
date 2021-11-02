/* ADT Item */
/* Definisi ADT Item yang merepresentasikan elemen Stack */
/* Contributor : 13520042 */

#include <stdlib.h>
#include <string.h>
#include "item.h"

const char type_list[3][10] = {"normal", "heavy", "perishable"};

void createItem(Item *item) {
    strcpy(TYPE(*item), type_list[rand() % 3]);
    if (strcmp(TYPE(*item), "normal") == 0) {
        VALUE(*item) = 200;
    }
    else if (strcmp(TYPE(*item), "heavy") == 0 || strcmp(TYPE(*item), "perishable") == 0) {
        VALUE(*item) = 400;
    }
}
