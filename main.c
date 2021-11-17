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
            sprint_red("Input tidak valid. Ulangi input.\n");
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

        // Main game loop
        while(!game.endGame){
            printf("%s%s", RED, "======================MENU=====================\n");
            printf("%s", NORMAL);
            if(!isEmpty(psnTerurut)){
              while(HEAD(psnTerurut).t <= currentTime && !isEmpty(psnTerurut)){
                insertLast(&TODO, HEAD(psnTerurut));
                dequeue(&psnTerurut, &tempPesanan);
              }
            }
            displayCurrentLocation();
            printf("Waktu: %d\n", currentTime);
            displayCurrentMoney();
            sprint_blue("ENTER COMMAND: ");
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
                    quitWithSave(game);
                    break;
                default:
                    sprint_red("Invalid input.\n");
            }
        }
        // End game reached
        endGameReached(game);
    }

    //Input == EXIT
    else if(input == 2){
        // ! Exit
        quit();
    }

}