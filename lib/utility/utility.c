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
    // loading();
    // printf("%i\n", g->bangunan.nEff);
    // checker();
    // displayMatrix(g->adj);
    // printf("\n%i %i\n", g->size.X, g->size.Y);

    // printf("%i %i\n", g->hq.X, g->hq.Y);
    // printf("%i %c %c %c\n", g->psn[2].t, g->psn[2].pickUp, g->psn[2].dropOff, g->psn[2].tipeItem);
}

int checkMenuInput(Word w){
    Word MOVE = {"MOVE", 4};
    Word PICK_UP = {"PICK_UP", 7};
    Word DROP_OFF = {"DROP_OFF", 8};
    Word MAP = {"MAP", 3};
    Word TO_DO = {"TO_DO", 5};
    Word IN_PROGRESS = {"IN_PROGRESS", 11};
    Word BUY = {"BUY", 3};
    Word INVENTORY = {"INVENTORY", 9};
    Word HELP = {"HELP", 4};
    Word RETURN = {"RETURN", 6};
    // Might need later //
    Word SAVE_GAME = {"SAVE_GAME", 9};
    Word DEBUG = {"DEBUG", 5};

    Word key[] = {MOVE, PICK_UP, DROP_OFF, MAP, TO_DO, IN_PROGRESS, BUY, INVENTORY, HELP, RETURN, SAVE_GAME, DEBUG};
    int i;
    // ! Change to 10 if there is SAVE_GAME
    for(i = 0; i < 11; i++){
        if(isWordEqual(w, key[i])){
            return i;
        }
    }
    return -1;
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


void help(){
    printf("==+ HELP MENU +==\n");
    printf("1. MOVE -> Untuk berpindah ke lokasi lainnya\n");
    printf("2. PICK_UP -> Untuk mengambil item yang ada di lokasi sekarang\n");
    printf("3. DROP_OFF -> Untuk mengantarkan item ke lokasi jika item di tumpukan teratas tas sesuai dengan pesanan.\n");
    printf("4. MAP -> Untuk memunculkan peta.\n");
    printf("5. TO_DO -> Untuk menampilkan pesanan yang masuk ke dalam To Do List\n");
    printf("6. IN_PROGRESS ->  Untuk menampilkan pesanan yang sedang diantar\n");
    printf("7. BUY -> Untuk membeli gadget (Hanya dapat dilakukan di HQ)\n");
    printf("8. INVENTORY -> Untuk menampilkan isi inventory.\n");
    printf("9. HELP -> Menampilkan menu Help yang berisi daftar command.\n");
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