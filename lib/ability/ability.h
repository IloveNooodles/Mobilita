#ifndef ABILITY_H
#define ABILITY_H

#include "../stack/stack.c"
#include "../utility/boolean.h"
#include "../lokasi/lokasi.c"
#include "../item/item.c"
#include "../list_linked/list_linked.c"

typedef struct {
  int time; //ngitung dari 10 sampe 1 atau dari 1 smpe 10 nanti baru set freezenya off
  boolean freezeTime; //check lagi berenti waktu apa engga
  boolean heavyItem; //check ada heavy apa engga 
  boolean returnToSender;
  boolean isSenterPengecilActivated; //kalau true bisa activateReturnToSender
} Ability;


//Selektor
#define FREEZE(l) (l).freezeTime
#define TIME(l) (l).time
#define HEAVYITEM(l) (l).heavyItem
#define RETURNTOSENDER(l) (l).returnToSender
#define SENTERPENGECIL(l) (l).isSenterPengecilActivated

void createAbility(Ability *b);
void checkHeavyIteminBag(Ability *b, Stack s);
void activateSpeedBoost(Ability *b);
void deactivateSpeedBoost(Ability *b);
void activateIncreaseCapacity();
void activateReturnToSender(Ability *b, Stack *s, List *Todo, List *inProgress);

#endif