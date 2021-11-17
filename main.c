#include <stdio.h>
#include "lib/utility/utility.h"

int main(){
    Game game;
    Word EMPTY = {"", 0};
    Word wordAr[3];
    Word Config = {"config.txt", 10};
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

    // Input == NEW GAME or LOAD GAME
    if(input == 1 || input == 3){
        if(input == 1){
            startGame(&game);
        }
        else{
            startGameFromLoad(&game);
        }

        // Game game;
        // printf("Selamat datang di Mobilita!\nSilahkan masukkan nama config file: ");
        // startWord();
        // TODO Initialize game bagian ini harusnya masukin ke bagian startgame 
        // inputConfigFile(&game, Config);
        // game.endGame = false;
        // currentTime = 0;
        // currentLocation = game.hq;
        // currentMoney = 0;
        // CreateLinkedList(&TODO);
        // CreateLinkedList(&inProgress);
        // CreateStack(&game.tas);
        // Main game loop
        while(!game.endGame){
            printf("======================MENU=====================\n");
            if(!isEmpty(psnTerurut)){
              while(HEAD(psnTerurut).t <= currentTime && !isEmpty(psnTerurut)){
                insertLast(&TODO, HEAD(psnTerurut));
                dequeue(&psnTerurut, &tempPesanan);
              }
            }
            // printf("l %d\n", lengthPrioQueue(psnTerurut));
            displayCurrentLocation();
            printf("Waktu: %d\n", currentTime);
            displayCurrentMoney();
            printf("ENTER COMMAND: ");
            startWord();
            input = checkMenuInput(currentWord);
            switch(input){
                case 0:
                    move(&game);
                    break;
                case 1:
                    pickup(&game);
                    break;
                case 2:
                    dropOff(&game);
                    break;
                case 3:
                    displayPeta(game, currentTime);
                    break;
                case 4:
                    displayPesananTerurut(TODO);
                    break;
                case 5:
                    displayInProgressList(inProgress);
                    break;
                case 6:
                    buy(&game);
                    break;
                case 7:
                    displayInventory(&game.gl, &game);
                    break;
                case 8:
                    help();
                    break;
                case 9:
                    activateReturnToSender(&game.b,&game.tas, &TODO, &inProgress);
                    break;
                case 10:
                    saveGame(game, currentConfigFile);
                    break;
                case 11:
                    // DEBUG
                    printf("DEBUG MODE ON\n");
                default:
                    printf("Invalid input.\n");
            }
        }
    }

    //Input == EXIT
    else if(input == 2){
        // ! Exit
        quit();
    }

}