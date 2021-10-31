#include <stdio.h>
#include "peta.h"

int main(){
  Peta p;
  CreatePeta(&p);
  initializePeta(&p, 17);
  displayLokasiPeta(p);
  displayAdjPeta(p, 0);
  displayPeta(p, 10, 15);
}