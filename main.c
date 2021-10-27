#include <stdio.h>
#include "h\adt.h"
#include "h\util.h"

int main(){
    Word wordAr[3];
    int input = 0;
    startMenu();
    while(input == 0){
        // TODO: Validasi (Masih belom benar)
        int no = 0;
        startWord();
        while(!endWord){
            if(no<3){
                wordAr[no] = currentWord;
                no++;
            }
            advWord();
        }
        displayWord(currentWord);
        input = checkStartInput(wordAr);
    }
    if(input == 1){
        // TODO: Masuk ke New Game
    }
    else if(input == 2){
        // EXIT
        quit();
    }

}