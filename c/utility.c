#include <stdio.h>
#include <stdlib.h>
#include "../h/wordmachine.h"

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

void checker(){
    printf("Masuk!\n");
}

void quit(){
    printf("Sampai jumpa kembali!\n");
    exit(0);
}