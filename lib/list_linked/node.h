#ifndef NODE_H
#define NODE_H

#include "../PrioQueue/prioqueue.c"
#include <stdlib.h>

typedef Pesanan PesananElType;
typedef struct node* Address;
typedef struct node {
    PesananElType info;
    Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(PesananElType val);


#endif