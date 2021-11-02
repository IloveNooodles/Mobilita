/* ADT Item */
/* Definisi ADT Item yang merepresentasikan elemen Stack */
/* Contributor : 13520042 */

#ifndef MOBILITA_ITEM_H
#define MOBILITA_ITEM_H

typedef char item_type[10];
typedef struct {
    item_type type;
    int value;
} Item;

extern const char type_list[3][10];

#define TYPE(i) (i).type
#define VALUE(i) (i).value

/* Create new Item needed as Stack element*/
/* Generates new item_type and assign its value accordingly */
void createItem(Item *item);

#endif //MOBILITA_ITEM_H
