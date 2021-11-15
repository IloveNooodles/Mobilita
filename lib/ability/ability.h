#ifndef ABILITY_H
#define ABILITY_H

#include "../stack/stack.h"
#include "../utility/boolean.h"
#include "../lokasi/lokasi.h"
#include "../item/item.h"
#include "../list_linked/list_linked.h"

typedef struct {
  int time; //ngitung dari 10 sampe 1 atau dari 1 smpe 10 nanti baru set freezenya off
  boolean freezeTime; //check lagi berenti waktu apa engga
  boolean heavyItem; //check ada heavy apa engga 
  boolean returnToSender; //kalau true bisa activateReturnToSender
} Ability;


//Selektor
#define FREEZE(l) (l).freezeTime
#define TIME(l) (l).time
#define HEAVYITEM(l) (l).heavyItem
#define RETURNTOSENDER(l) (l).returnToSender

void createAbility(Ability *b);
void checkHeavyIteminBag(Ability *b, Stack s);
void activateSpeedBoost(Ability b);
void deactivateSpeedBoost(Ability b);
void activateIncreaseCapacity();
void activateReturnToSender(Ability b, Stack s, List l1, List l2);

#endif