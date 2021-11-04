#include <stdio.h>
#include "game.h"

void move(Game g){
    Lokasi possibleMoves[26] = {0};
    int i;
    int idx;
    int count = 0;

    // Checking index
    for(i = 0; i < 27; i++){
        if(EQ(g.bangunan.buffer[i].koor, currentLocation.koor)){
            idx = i;
        }
    }

    // Searching possible moves
    for(i = 0; i < g.adj.colEff; i++){
        if(g.adj.contents[idx][i] == 1){
            possibleMoves[count] = g.bangunan.buffer[i];
            count++;
        }
    }

    // Printing possible moves
    printf("Posisi yang dapat dicapai: \n");
    for(i = 0; i < count; i++){
        printf("%d. %c ", i+1, possibleMoves[i].tipeBangunan);  TulisPOINT(possibleMoves[i].koor); printf("\n");
    }

    // Execute moves
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
    printf("ENTER COMMAND: ");
    startWord();
    int choice = atoi(currentWord.contents);
    if(choice > count || choice < 0){
        printf("Input tidak valid. Mengembalikan ke menu utama.\n");
        return;
    }
    else{
        // Update variables
        if(choice == 0){
            return;
        }
        else{
            // ! CurrentTime diupdate tanpa mengecek item yang sedang dicarry. Harus diubah nanti
            currentTime += selisih(possibleMoves[choice-1].koor, currentLocation.koor); 
            updatePosition(possibleMoves[choice-1]);
            printf("Mobita sekarang berada di titik "); TulisLokasi(currentLocation);
        }
    }
}

void updatePosition(Lokasi l){
    currentLocation.koor.X = l.koor.X;
    currentLocation.koor.Y = l.koor.Y;
    currentLocation.tipeBangunan = l.tipeBangunan;
}