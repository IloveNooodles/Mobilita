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
        // Initialize game
        inputConfigFile(&game, Config);
        game.endGame = false;
        currentTime = 0;
        currentLocation = game.hq;
        currentMoney = 0;
        
        // Main game loop
        while(!game.endGame){
            displayCurrentLocation();
            printf("Waktu: %d\n", currentTime);
            displayCurrentMoney();
            printf("ENTER COMMAND: ");
            startWord();
            input = checkMenuInput(currentWord);
            switch(input){
                case 0:
                    // MOVE
                    move(game);
                    break;
                case 1:
                    displayListDin(game.bangunan);
                    for(int i = 0; i < game.jumlah_pesanan; i++){
                      displayPesanan(game.psn[i]);
                    }
                    printf("pickup\n");
                    break;
                case 2:
                    // DROPOFF
                    printf("dropoff\n");
                    break;
                case 3:
                    // MAP
                    displayPeta(game, currentTime);
                    break;
                case 4:
                    // TO DO
                    // TODO: Prioqueue
                    printf("todo\n");
                    break;
                case 5:
                    // IN PROG
                    // TODO: Tas
                    printf("inprogress\n");
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
                // case 9:
                //     printf("save\n");
                //     break;
                case 10:
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