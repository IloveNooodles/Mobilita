/* ADT Item */
/* Definisi ADT Item yang merepresentasikan elemen Stack */
/* Contributor : 13520042 */

#ifndef MOBILITA_ITEM_H
#define MOBILITA_ITEM_H

typedef char item_type[10];
typedef struct {
    item_type type;
    int value;
    int expiry;
} Item;

#define TYPE(i) (i).type
#define VALUE(i) (i).value
#define EXPIRY(i) (i).expiry

/* Create new Item needed as Stack element*/
/* Generates new item_type and assign its value accordingly */
void createItem(Item *item, char type, int expiry);

#endif //MOBILITA_ITEM_H
