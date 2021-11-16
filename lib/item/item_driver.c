#include "item.c"
#include <stdio.h>

int main(){
  Item i;
  createItem(&i, 'P', 10);
  minusExpiry(&i);
  printf("%d", i.expiry_now);
  minusExpiry(&i);
  printf("%d", i.expiry_now);
  minusExpiry(&i);
  printf("%d", i.expiry_now);
  minusExpiry(&i);
  printf("%d", i.expiry_now);
  minusExpiry(&i);
  printf("%d", i.expiry_now);
  minusExpiry(&i);
  printf("%d", i.expiry_now);
  minusExpiry(&i);
  printf("%d", i.expiry_now);
  minusExpiry(&i);
  printf("%d", i.expiry_now);
  minusExpiry(&i);
  printf("%d", i.expiry_now);
  minusExpiry(&i);
  printf("%d", i.expiry_now);
}