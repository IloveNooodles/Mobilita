#include <stdio.h>
#include "lib\adt.h"
#include "lib\utility\utility.h"
#include "lib\tempdriver.h"


int main(){
    Game game;
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
        // Game game;
        printf("Selamat datang di Mobilita!\nSilahkan masukkan nama config file: ");
        startWord();
        // Initialize game
        inputConfigFile(&game, currentWord);
        game.endGame = false;
        currentTime = 0;
        currentLocation = game.hq;
        
        while(!game.endGame){
            printf("Waktu: %d\n", currentTime);
            printf("ENTER COMMAND: ");
            startWord();
            input = checkMenuInput(currentWord);
            switch(input){
                case 0:
                    move(game);
                    break;
                case 1:
                    printf("pickup\n");
                    break;
                case 2:
                    printf("dropoff\n");
                    break;
                case 3:
                    printf("map\n");
                    break;
                case 4:
                    printf("todo\n");
                    break;
                case 5:
                    printf("inprogress\n");
                    break;
                case 6:
                    printf("buy\n");
                    break;
                case 7:
                    printf("inventory\n");
                    break;
                case 8:
                    help();
                    break;
                // case 9:
                //     printf("save\n");
                //     break;
                default:
                    printf("Invalid input.\n");
            }
        }

        // checker();
    }

    //Input == EXIT
    else if(input == 2){
        // ! Exit
        quit();
    }

}