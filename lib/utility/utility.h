#ifndef UTIL_H
#define UTIL_H

#include "game.h"
#include "../adt.h"
// Functions
void startMenu();
// Memulai startmenu

boolean isWordEqual(Word a, Word b);
// Check apakah dua word sama

void displayWord(Word w);
// Menampilkan word

int checkStartInput(Word a[]);
// input checker for startmenu

void inputConfigFile(Game *g, Word cfg);
// Menginput config file

void checker();
// prints "masuk" (to check a functionality)

void quit();


#endif