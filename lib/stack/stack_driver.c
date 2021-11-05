#include <stdio.h>
#include "stack.h"

int main(){
  Stack s;
  Item a;
  CreateStack(&s);
  createItem(&a, 'N');
  push(&s, a);
  createItem(&a, 'H');
  push(&s, a);
  displayStack(s);
}