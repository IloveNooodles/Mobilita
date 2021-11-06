#include <stdio.h>
#include "stack.h"

int main(){
  Stack s;
  Item a;
  CreateStack(&s);
  createItem(&a, 'N');
  push(&s, a);
  createItem(&a, 'P');
  push(&s, a);
  CreateStack(&s);
  createItem(&a, 'H');
  displayStack(s);
}