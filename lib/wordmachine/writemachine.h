#ifndef WRITEMACHINE_H
#define WRITEMACHINE_H
#include <stdio.h>
#include <stdlib.h>
#include "../utility/game.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "../list_linked/list_linked.h"

void copyFromFile(Word cfg, Word savefile);

void saveGame(Game g, Word cfg);

#endif