/* ADT Item */
/* Definisi ADT Item yang merepresentasikan elemen Stack */
/* Contributor : 13520042 */

#include "../utility/boolean.h"

#ifndef MOBILITA_ITEM_H
#define MOBILITA_ITEM_H

typedef struct {
    char type;
    char* type_desc;
    int value;
    int expiry;
    int expiry_now;
} Item;

#define TYPE(i) (i).type
#define TYPE_DESC(i) (i).type_desc
#define VALUE(i) (i).value
#define EXPIRY(i) (i).expiry
#define EXPIRY_NOW(i) (i).expiry_now

/* Create new Item needed as Stack element*/
/* Generates new item_type and assign its value accordingly */
boolean isItemEqual(Item i1, Item i2);
void minusExpiry(Item *i);
void createItem(Item *item, char type, int expiry);
void displayItem(Item item);
#endif //MOBILITA_ITEM_H
