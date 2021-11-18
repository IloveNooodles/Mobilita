#ifndef UTILITY_H
#define UTILITY_H

#include "game.h"
#include "../wordmachine/wordmachine.h"
#include "../wordmachine/charmachine.h"

// Functions
void startMenu();
// Memulai startmenu


int checkStartInput(Word a[]);
// input checker for startmenu

void inputConfigFile(Game *g, Word cfg);
// Menginput config file

void checker();
// prints "masuk" (to check a functionality)


// ! Moved to wordmachine
// boolean isWordEqual(Word a, Word b);
// Check apakah dua word sama
// void displayWord(Word w);
// Menampilkan word
// Word concatWord(Word w1, Word w2);
// Concatenates two words

int checkMenuInput(Word w);
// Main menu input checker

void help();

void loading();
// Fancy loading for the lulz

void quit();
// Quit the program

#endif