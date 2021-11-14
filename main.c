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
    // do{
    //     startWord();
    //     for(i=0;i<3;i++){
    //         wordAr[i] = EMPTY;
    //     }
    //     endWord = false;
    //     int no = 0;
    //     while(!endWord){
    //         if(no<3){
    //             wordAr[no] = currentWord;
    //             no++;
    //         }
    //         advWord();
    //     }
    //     input = checkStartInput(wordAr);
    //     if(input == 0){
    //         printf("Input tidak valid. Ulangi input.\n");
    //     }
    // } while(input == 0);

    // Input == NEW GAME
    // if(input == 1){
        // Game game;
        printf("Selamat datang di Mobilita!\nSilahkan masukkan nama config file: ");
        // startWord();
        // TODO Initialize game bagian ini harusnya masukin ke bagian startgame 
        inputConfigFile(&game, Config);
        game.endGame = false;
        currentTime = 0;
        currentLocation = game.hq;
        currentMoney = 0;
        CreateLinkedList(&TODO);
        CreateLinkedList(&inProgress);
        CreateStack(&game.tas);
        // Main game loop
        while(!game.endGame){
            if(!isEmpty(psnTerurut)){
              while(HEAD(psnTerurut).t <= currentTime){
                insertLast(&TODO, HEAD(psnTerurut));
                dequeue(&psnTerurut, &tempPesanan);
              }
            }
            displayCurrentLocation();
            printf("Waktu: %d\n", currentTime);
            displayCurrentMoney();
            printf("ENTER COMMAND: ");
            startWord();
            input = checkMenuInput(currentWord);
            switch(input){
                case 0:
                    move(game);
                    break;
                case 1:
                    pickup(&game);
                    break;
                case 2:
                    dropOff(game);
                    break;
                case 3:
                    // MAP
                    displayPeta(game, currentTime);
                    break;
                case 4:
                    displayPesananTerurut(TODO);
                    break;
                case 5:
                    displayInProgressList(inProgress);
                    break;
                case 6:
                    // BUY
                    // TODO: Gadget
                    printf("buy\n");
                    break;
                case 7:
                    // INV
                    // TODO: Gadget
                    printf("inventory\n");
                    break;
                case 8:
                    // HELP
                    help();
                    break;
                case 9:
                    activateReturnToSender(game.b,game.tas,inProgress,TODO);
                    break;
                // case 10:
                //     printf("save\n");
                //     break;
                case 11:
                    // DEBUG
                    printf("DEBUG MODE ON\n");
                    displayListDin(game.bangunan);
                default:
                    printf("Invalid input.\n");
            }
        // }

        // checker();
    }

//     //Input == EXIT
//     else if(input == 2){
//         // ! Exit
//         quit();
//     }

}