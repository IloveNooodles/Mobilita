#include <stdio.h>
#include "lib\adt.h"
#include "lib\utility\utility.h"
#include "lib\tempdriver.h"


int main(){
    Game game;
    int time;
    POINT currentLokasi;
    Peta p;
    Word EMPTY = {"", 0};
    Word wordAr[3];
    int input = 0;
    int i;
    startMenu();

    // Input dan Validasi Input
    do{
        startWord();
        for(i=0;i<3;i++){
            wordAr[i] = EMPTY;
        }
        endWord = false;
        int no = 0;
        while(!endWord){
            if(no<3){
                wordAr[no] = currentWord;
                no++;
            }
            advWord();
        }
        input = checkStartInput(wordAr);
        if(input == 0){
            printf("Input tidak valid. Ulangi input.\n");
        }
    } while(input == 0);

    // Input == NEW GAME
    if(input == 1){
        Game game;
        // TODO: Masuk ke New Game
        // startWord();
        // inputConfigFile(&game, currentWord);
        checker();
    }

    //Input == EXIT
    else if(input == 2){
        // EXIT
        quit();
    }

}