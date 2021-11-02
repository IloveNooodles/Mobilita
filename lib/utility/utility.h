#ifndef UTILITY_H
#define UTILITY_H

#include "game.h"
#include "../adt.h"
// #include "../wordmachine/wordmachine.h"

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

Word concatWord(Word w1, Word w2);

void loading();

void quit();


#endif