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
    // Curr Config File
    fprintf(save, "%s\n", currentConfigFile.contents);
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
        Pesanan tempP = g.tas.buffer[i];
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
        fprintf(save, "%d\n", tempG.id);
    }
    // Ability
    fprintf(save, "%d\n", g.b.time);
    if(g.b.freezeTime){
        fprintf(save, "%d\n", 1);
    }
    else{
        fprintf(save, "%d\n", 0);
    }
    if(g.b.heavyItem){
        fprintf(save, "%d\n", 1);
    }
    else{
        fprintf(save, "%d\n", 0);
    }
    if(g.b.returnToSender){
        fprintf(save, "%d\n", 1);
    }
    else{
        fprintf(save, "%d\n", 0);
    }
    if(g.b.isSenterPengecilActivated){
        fprintf(save, "%d\n", 1);
    }
    else{
        fprintf(save, "%d\n", 0);
    }
}


void loadGame(Game *g, Word cfg){
    Word EMPTY = {"", 0};
    currentWord = EMPTY;
    Word dir = {"./config/", 9};
    Word path = concatWord(dir, cfg);
    // displayWord(path);
    startFromFile(path.contents);
    CreateListDin(&g->bangunan, 30);
    advWord();
    g->size.X = atoi(currentWord.contents);
    advWord();
    g->size.Y = atoi(currentWord.contents);
    advNewline();
    g->hq.koor.X = atoi(currentWord.contents);
    advWord();
    g->hq.koor.Y = atoi(currentWord.contents);
    g->hq.tipeBangunan = '8';
    insertLastListDin(&g->bangunan, g->hq);
    advNewline();
    g->jumlah_lokasi = atoi(currentWord.contents);
    int i;
    Lokasi temploc;
    for(i = 1; i < g->jumlah_lokasi+1; i++){
        advNewline();
        temploc.tipeBangunan = currentWord.contents[0];
        advWord();
        temploc.koor.X = atoi(currentWord.contents);
        advWord();
        temploc.koor.Y = atoi(currentWord.contents);
        insertLastListDin(&g->bangunan, temploc);
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
        if(currentWord.contents[0] == 'P'){
          char temp = currentWord.contents[0];
          advWord();
          int temp2 = atoi(currentWord.contents);
          createItem(&g->psn[i].tipeItem, temp, temp2);
        }else{
          createItem(&g->psn[i].tipeItem, currentWord.contents[0], -1);
        }
        psnTerurut = transformToPrioQueue(*g);
    }
    // ! LINE CODE INI JANGAN DIHAPUS, TANPA INI LISTDIN TIDAK STABIL!
    int len = listDinLength(g->bangunan);

    advNewline();
    // Currents
    copyWordFromWord(currentWord, currentConfigFile);
    advWord();
    currentTime = atoi(currentWord.contents);
    advWord();
    currentMoney = atoi(currentWord.contents);
    advNewline();
    currentLocation.tipeBangunan = currentWord.contents[0];
    advWord();
    currentLocation.koor.X = atoi(currentWord.contents);
    advWord();
    currentLocation.koor.X = atoi(currentWord.contents);
    
    // TODOs
    int todolength = atoi(currentWord.contents);
    for(i = 0; i < todolength; i++){
        Pesanan tempP;
        advNewline();
        tempP.t = atoi(currentWord.contents);
        advWord();
        tempP.pickUp = currentWord.contents[0];
        advWord();
        tempP.dropOff = currentWord.contents[0];
        advWord();
        if(currentWord.contents[0] == 'P'){
          char temp = currentWord.contents[0];
          advWord();
          int temp2 = atoi(currentWord.contents);
          createItem(&tempP.tipeItem, temp, temp2);
          
        }else{
          createItem(&tempP.tipeItem, currentWord.contents[0], -1);
        }
        setElmt(&TODO, i, tempP);
    }


    // In Progress
    advNewline();
    int inprolength = atoi(currentWord.contents);
    for(int i = 0; i < inprolength; i++){
        Pesanan tempP;
        advNewline();
        tempP.t = atoi(currentWord.contents);
        advWord();
        tempP.pickUp = currentWord.contents[0];
        advWord();
        tempP.dropOff = currentWord.contents[0];
        advWord();
        if(currentWord.contents[0] == 'P'){
          char temp = currentWord.contents[0];
          advWord();
          int temp2 = atoi(currentWord.contents);
          createItem(&tempP.tipeItem, temp, temp2);
          advWord();
          int temp3 = atoi(currentWord.contents);
          tempP.tipeItem.expiry_now = temp3;
        }else{
          createItem(&tempP.tipeItem, currentWord.contents[0], -1);
        }
        setElmt(&inProgress, i, tempP);
    }


    // Tas
    // idxTop, heavyItem
    advNewline();
    g->tas.idxTop = atoi(currentWord.contents);
    advWord();
    g->tas.heavyItem = atoi(currentWord.contents);
    for(int i = 0; i < inprolength; i++){
        Pesanan tempP;
        advNewline();
        tempP.t = atoi(currentWord.contents);
        advWord();
        tempP.pickUp = currentWord.contents[0];
        advWord();
        tempP.dropOff = currentWord.contents[0];
        advWord();
        if(currentWord.contents[0] == 'P'){
          char temp = currentWord.contents[0];
          advWord();
          int temp2 = atoi(currentWord.contents);
          createItem(&tempP.tipeItem, temp, temp2);
          advWord();
          int temp3 = atoi(currentWord.contents);
          tempP.tipeItem.expiry_now = temp3;
        }else{
          createItem(&tempP.tipeItem, currentWord.contents[0], -1);
        }
        g->tas.buffer[i] = tempP;
    }

    // Gadget List
    advNewline();
    for(int i = 0; i < 5; i++){
        g->gl.buffer[i].id = atoi(currentWord.contents);
        if(i != 4){
            advWord();
        }
    }

    // Ability
    advNewline();
    g->b.time = atoi(currentWord.contents);
    advNewline();
    g->b.freezeTime = atoi(currentWord.contents);
    advNewline();
    g->b.heavyItem = atoi(currentWord.contents);
    advNewline();
    g->b.returnToSender = atoi(currentWord.contents);
    advNewline();
    g->b.isSenterPengecilActivated = atoi(currentWord.contents);
}