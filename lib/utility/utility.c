#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

void startMenu(){
    printf("Selamat datang ke Mobilita.\n");
    printf("1. NEW GAME\n");
    printf("2. EXIT\n");
}

boolean isWordEqual(Word a, Word b){
    if(a.length != b.length){
        return false;
    }
    else{
        int i = 0;
        boolean flag = true;
        while(i < a.length && flag){
            if(a.contents[i] != b.contents[i]){
                flag = false;
            }
            i++;
        }
        return flag;
    }
}

void displayWord(Word w){
    int i;
    for(i = 0; i<w.length;i++){
        printf("%c", w.contents[i]);
    }
    printf("\n");
}

int checkStartInput(Word a[]){
    Word EXIT = {"EXIT", 4};
    Word NEW = {"NEW", 3};
    Word GAME = {"GAME", 4};
    Word EMPTY = {"", 0};
    if(isWordEqual(a[0], EXIT)){
        if(isWordEqual(a[1], EMPTY)){
            return 2;
        }
        else{
            return 0;
        }
    }
    else if(isWordEqual(a[0], NEW)){
        if(isWordEqual(a[1], GAME)){
            if(isWordEqual(a[2], EMPTY)){
                return 1;
            }
        }
        return 0;
    }
    else{
        return 0;
    }
}

void inputConfigFile(Game *g, Word cfg){
    // TODO
    Word EMPTY = {"", 0};
    currentWord = EMPTY;
    Word dir = {"./config/", 9};
    Word path = concatWord(dir, cfg);
    // displayWord(path);
    startFromFile(path.contents);
    advWord();
    g->size.X = atoi(currentWord.contents);
    advWord();
    g->size.Y = atoi(currentWord.contents);
    advNewline();
    g->hq.X = atoi(currentWord.contents);
    advWord();
    g->hq.Y = atoi(currentWord.contents);
    advNewline();
    g->jumlah_lokasi = atoi(currentWord.contents);
    int i;
    for(i = 0; i < g->jumlah_lokasi; i++){
        advNewline();
        g->bangunan[i].tipeBangunan = currentWord.contents[0];
        advWord();
        g->bangunan[i].koor.X = atoi(currentWord.contents);
        advWord();
        g->bangunan[i].koor.Y = atoi(currentWord.contents);
    }
    g->adj.colEff = g->jumlah_lokasi+1;
    g->adj.rowEff = g->jumlah_lokasi+1;
    int j;
    advNewline();
    // displayWord(currentWord);
    for(i = 0; i < g->adj.rowEff; i++){
        for(j = 0; j < g->adj.colEff; j++){
            g->adj.contents[i][j] = atoi(currentWord.contents);
            if(j == g->adj.colEff-1){
                advNewline();
            }
            else{
                advWord();
            }
        }
    }
    g->jumlah_pesanan = atoi(currentWord.contents);
    for(i = 0; i < g->jumlah_pesanan; i++){
        advNewline();
        g->psn[i].t = atoi(currentWord.contents);
        advWord();
        g->psn[i].pickUp = currentWord.contents[0];
        advWord();
        g->psn[i].dropOff = currentWord.contents[0];
        advWord();
        g->psn[i].tipeItem = currentWord.contents[0];
    }

    // loading();

    // checker();
    // displayMatrix(g->adj);
    // printf("\n%i %i\n", g->size.X, g->size.Y);

    // printf("%i %i\n", g->hq.X, g->hq.Y);
    // printf("%i %c %c %c\n", g->psn[2].t, g->psn[2].pickUp, g->psn[2].dropOff, g->psn[2].tipeItem);
}

void checker(){
    printf("Masuk!\n");
}

Word concatWord(Word w1, Word w2){
    Word ans;
    ans.length = w1.length + w2.length;
    int i;
    for(i = 0; i < w1.length; i++){
        ans.contents[i] = w1.contents[i];
    }
    for(i = 0; i < w2.length;i++){
        ans.contents[i+w1.length] = w2.contents[i];
    }
    return ans;
}


void loading(){
    int i = 0;
    for (i = 0; i <= 10000; i++){
        printf("\rLoading... (%d)", i/100);
        fflush(stdout);
    }
    printf("\n");
}

void quit(){
    printf("Sampai jumpa kembali!\n");
    exit(0);
}