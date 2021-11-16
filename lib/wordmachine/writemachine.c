#include "writemachine.h"


void copyFromFile(Word cfg, Word savefile){
    char ch;
    Word NulTerm = {"\0", 1};
    FILE *source, *target;
    Word dir = {"./config/", 9};
    Word savepath = concatWord(dir, savefile);
    Word path = concatWord(dir, cfg);
    savepath = concatWord(savepath, NulTerm);
    path = concatWord(path, NulTerm);
    // source = fopen(path.contents, "r");
    source = fopen("./config/config.txt", "r");
    if(source == NULL){
        printf("Error: File source not found. Exiting..\n");
        exit(0);
    }
    // target = fopen(savepath.contents, "w");
    target = fopen("./config/coba.txt", "w");
    if(target == NULL){
        printf("Error: File not found. Exiting..\n");
        exit(0);
    }
    fprintf(target, "a");
    while((ch = fgetc(source)) != EOF){
        printf("%c\n", ch);
        fputc(ch, target);
    }
    fclose(source);
    fclose(target);
}

void saveGame(Game g, Word cfg){
    FILE *save;

    printf("Masukkan nama file penyimpanan: ");
    startWord();
    Word savefile = currentWord;
    copyFromFile(cfg, savefile);
    Word dir = {"./config/", 9};
    Word savepath = concatWord(dir, savefile);
    save = fopen("./config/coba.txt", "w");
    // Curr Time Curr Money
    fprintf(save, "%d %d\n", currentTime, currentMoney);
    // Curr Loc
    fprintf(save, "%c %d %d\n", currentLocation.tipeBangunan, currentLocation.koor.X, currentLocation.koor.Y);
    // TODO
    int todolength = listLinkedLength(TODO);
    fprintf(save, "%d\n", todolength);
    for(int i = 0; i < todolength; i++){
        Pesanan tempP = getElmt(TODO,i);
        if(tempP.tipeItem.type == 'P'){
            fprintf(save, "%d %c %c %c %d\n", tempP.t, tempP.pickUp, tempP.dropOff, tempP.tipeItem.type, tempP.tipeItem.expiry);
        }
        else{
            fprintf(save, "%d %c %c %c\n", tempP.t, tempP.pickUp, tempP.dropOff, tempP.tipeItem.type);
        }
    }
    // InProgress
    int inprolength = listLinkedLength(inProgress);
    fprintf(save, "%d\n", inprolength);
    for(int i = 0; i < inprolength; i++){
        Pesanan tempP = getElmt(TODO,i);
        if(tempP.tipeItem.type == 'P'){
            fprintf(save, "%d %c %c %c %d %d\n", tempP.t, tempP.pickUp, tempP.dropOff, tempP.tipeItem.type, tempP.tipeItem.expiry, tempP.tipeItem.expiry_now);
        }
        else{
            fprintf(save, "%d %c %c %c\n", tempP.t, tempP.pickUp, tempP.dropOff, tempP.tipeItem.type);
        }
    }

    // PsnTerurut


    // Tas
    // idxTop, heavyItem
    fprintf(save, "%d %d\n", g.tas.idxTop, g.tas.heavyItem);
    for(int i = 0; i < inprolength; i++){
        Pesanan tempP = getElmt(TODO,i);
        if(tempP.tipeItem.type == 'P'){
            fprintf(save, "%d %c %c %c %d %d\n", tempP.t, tempP.pickUp, tempP.dropOff, tempP.tipeItem.type, tempP.tipeItem.expiry, tempP.tipeItem.expiry_now);
        }
        else{
            fprintf(save, "%d %c %c %c\n", tempP.t, tempP.pickUp, tempP.dropOff, tempP.tipeItem.type);
        }
    }
    // GadgetList
    for(int i = 0; i < 5; i++){
        Gadget tempG = g.gl.buffer[i];
        fprintf(save, "%d\n", tempG);
    }
    // Ability
    fprintf(save, "%d\n", g.b.time);
    if(g.b.freezeTime == true){
        fprintf(save, "%d\n", 1);
    }
    else{
        fprintf(save, "%d\n", 0);
    }
    if(g.b.heavyItem == true){
        fprintf(save, "%d\n", 1);
    }
    else{
        fprintf(save, "%d\n", 0);
    }
    if(g.b.returnToSender == true){
        fprintf(save, "%d\n", 1);
    }
    else{
        fprintf(save, "%d\n", 0);
    }
    if(g.b.isSenterPengecilActivated == true){
        fprintf(save, "%d\n", 1);
    }
    else{
        fprintf(save, "%d\n", 0);
    }
}