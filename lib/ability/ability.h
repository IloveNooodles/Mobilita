#include "../stack/stack.h"
#include "../utility/boolean.h"
#include "../lokasi/lokasi.h"
#include "../item/item.h"

typedef struct {
  int time; //ngitung dari 10 sampe 1 atau dari 1 smpe 10 nanti baru set freezenya off
  int bonusCapacity; //ini jumlah banyaknya bonus item
  boolean freezeTime; //check lagi berenti waktu apa engga
  boolean heavyItem; //check ada heavy apa engga 
} Ability;


//Selektor
#define FREEZE(l) (l).freezeTime
#define TIME(l) (l).time
#define BONUSCAPACITY(l) (l).bonusCapacity
#define HEAVYITEM(l) (l).heavyItem

void createAbility(Ability b);
void checkHeavyIteminBag(Ability b, Stack s);
void activateSpeedBoost(Ability b);
void deactivateSpeedBoost(Ability b);
void activateIncreaseCapacity(Ability b);
void activateReturnToSender(Ability b);

