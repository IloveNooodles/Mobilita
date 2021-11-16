#include <stdio.h>
#include <stdlib.h>
#include "../utility/utility.h"

Word Config = {"config.txt", 10};

void startGame(Game *game){
  printf("Selamat datang di Mobilita!\nSilahkan masukkan nama config file: ");
  printf("\n");
  // startWord();
  inputConfigFile(game, Config);
  game->endGame = false;
  currentTime = 51;
  currentLocation = game->hq;
  currentMoney = 60000;
  CreateLinkedList(&TODO); // buat to do list
  CreateLinkedList(&inProgress); // buat  inprogress
  CreateStack(&game->tas); // buat tas baru
  createInventory(&game->gl); // ini buat new inven
  gadgetInfo(&Toko); // ini inisialisasi toko
  createAbility(&game->b);
}

void buy(Game *g){
  if(EQ(currentLocation.koor, g->hq.koor)){
    buyGadget(Toko, &g->gl, &currentMoney);
  }else{
    printf("Tidak bisa membeli item karena tidak di HQ.\n");
  }
}

void progress(Game *g){
  if(!isStackEmpty(g->tas)){
    Stack tasTemp;
    Pesanan temp;
    Pesanan temp2;
    int len = IDX_TOP(g->tas);
    CreateStack(&tasTemp);
    for(int i = 0; i <= len; i++){
      pop(&g->tas, &temp);
      if(TYPE(tipeItem(temp)) == 'P'){
        minusExpiry(&temp.tipeItem);
        minusExpiryList(&inProgress);
        if(temp.tipeItem.expiry_now == 0){
          if(checkInProgress(inProgress, temp) != -1){
            deletePesanan(&inProgress, &temp2, checkInProgress(inProgress, temp));
          }
        }else{
          push(&tasTemp, temp);
        }
      }else{
        push(&tasTemp, temp);
      }
    }
    len = IDX_TOP(tasTemp);
    //NOTE Ngebalikin lagi soalnya tadi pasti kebalik hasilnya
    for(int i = 0; i <= len; i++){
      pop(&tasTemp, &temp);
      push(&g->tas, temp);
    }
  }
}

void move(Game *g){
    Lokasi possibleMoves[26] = {0};
    int i;
    int idx;
    int count = 0;
    // Checking index
    for(i = 0; i < 27; i++){
        if(EQ(g->bangunan.buffer[i].koor, currentLocation.koor)){
            idx = i;
        }
    }

    // Searching possible moves
    for(i = 0; i < g->adj.colEff; i++){
        if(g->adj.contents[idx][i] == 1){
            possibleMoves[count] = g->bangunan.buffer[i];
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
            checkHeavyIteminBag(&g->b, g->tas);
            if(HEAVYITEM(g->b) && FREEZE(g->b)){
              TIME(g->b) = 0;
              deactivateSpeedBoost(&g->b);
            }
            if(FREEZE(g->b)){
              TIME(g->b)--;
              if(TIME(g->b) % 2 == 0 && TIME(g->b) < 10){
                currentTime++;
              }
              deactivateSpeedBoost(&g->b);
            }
            else if(HEAVY(g->tas) >= 1){
              currentTime = currentTime + HEAVY(g->tas) + 1;
            }
            else{
              currentTime++;
            }
            progress(g);
            updatePosition(possibleMoves[choice-1]);
            // printf("Mobita sekarang berada di titik "); TulisLokasi(currentLocation);
        }
    }
}

void pickup(Game *g){
  Pesanan inputPesanan;
  if(checkPesanan(TODO, currentLocation) == -1){
    printf("Tidak ada item pada bangunan ini.\n");
  }else{
    if(TOP(g->tas).tipeItem.type == 'V'){
      printf("Antarkan dulu VIP Itemnya!\n");
    }else if(!isStackFull(g->tas)){
      deletePesanan(&TODO, &inputPesanan, checkPesanan(TODO, currentLocation));
      push(&g->tas, inputPesanan);
      insertLast(&inProgress, inputPesanan);
      printf("Pesanan %s berhasil diambil.\n", TYPE_DESC(tipeItem(inputPesanan)));
    }else{
      printf("Tas sudah penuh tidak bisa mengambil barang lagi.\n");
    }
  }
}

int checkPossibleMoves(Game g, int *possibleMoves){
    int i;
    int idx;
    int count = 0;
    for(i = 0; i < 27; i++){
        if(EQ(g.bangunan.buffer[i].koor, currentLocation.koor)){
            idx = i;
        }
    }
    for(i = 0; i < g.adj.colEff; i++){
        if(g.adj.contents[idx][i] == 1){
            possibleMoves[count] = i;
            count++;
        }
    }
    return count;
}

void displayPeta(Game g, int time){
    int row = g.size.X;
    int col = g.size.Y;

    Matrix m;
    CreateMatrix(row, col, &m);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
        MATRIXELMT(m, i, j) = -1;
        }
    }
    // printf("%i\n", g.bangunan.nEff);
    for(int i = 0; i < g.bangunan.nEff; i++){
        MATRIXELMT(m, g.bangunan.buffer[i].koor.X-1, g.bangunan.buffer[i].koor.Y-1) = i;
        // MATRIXELMT(m, ELMTADJMTRX(p, i).X-1, ELMTADJMTRX(p, i).Y-1) = i;
    }
    for(int i = 0; i < row-1; i++){
        if(i == row - 1){
        printf("*");
        }else printf("* ");
    }
    printf("\n");

    int possMoves[30];
    int possMoveCnt = checkPossibleMoves(g, possMoves);
    boolean green = false;
    boolean red = false;
    boolean blue = false;
    
    int loc;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            green = false;
            red = false;
            blue = false;
            loc = MATRIXELMT(m, i, j);
            if(j == 0){
                printf("*");
            }
            if(loc != -1){
                for(int k = 0; k < possMoveCnt; k++){
                    if(loc == possMoves[k]){
                        green = true;
                    }
                }
                if(hasItem(TODO, g.bangunan.buffer[loc])){
                  red = true;
                }
                if(g.bangunan.buffer[loc].tipeBangunan == TOP(g.tas).dropOff){
                  blue = true;
                }
                
                if(isLocationEqual(currentLocation, g.bangunan.buffer[loc])){
                    print_yellow(g.bangunan.buffer[loc].tipeBangunan);
                }
                else if(blue){
                  print_blue(g.bangunan.buffer[loc].tipeBangunan);
                }
                else if(red){
                  print_red(g.bangunan.buffer[loc].tipeBangunan);
                }

                else if(green){
                    print_green(g.bangunan.buffer[loc].tipeBangunan);
                }
                
                // TODO: Check back ketika sudah ada dropoff dan pickup
                // else if(dropoffterataspadatas){
                //     print_blue(g.bangunan.buffer[loc].tipeBangunan);
                // }
                else{
                    printf("%c", g.bangunan.buffer[loc].tipeBangunan);
                }
            }else printf(" ");
            if(j == col - 1){
                printf("*");
            }
            }
            printf("\n");
    }
        // for(int i = 0; i < row; i++){
        //     for(int j = 0; j < col; j++){
                
        //     }
        // }

    for(int i = 0; i < row-1; i++){
        if(i == row - 1){
        printf("*");
        }else printf("* ");
    }
    printf("\n");
}

void displayCurrentLocation(){
    printf("Mobita sekarang berada di titik "); TulisLokasi(currentLocation);
}

void displayCurrentMoney(){
    printf("Uang yang dimiliki: %d Yen\n", currentMoney);
}



void updatePosition(Lokasi l){
    currentLocation.koor.X = l.koor.X;
    currentLocation.koor.Y = l.koor.Y;
    currentLocation.tipeBangunan = l.tipeBangunan;
}

void dropOff(Game *g){
    if (!isStackEmpty(g->tas)){
        if (getTipeBangunan(currentLocation) == DROPOFF(TOP(g->tas))){
            Pesanan dropped;
            deleteLast(&inProgress, &dropped);
            if(SENTERPENGECIL(g->b)){
              HEAVY(g->tas)++;
              SENTERPENGECIL(g->b) = false;
            }
            pop(&g->tas,&dropped);
            currentMoney += VALUE(tipeItem(dropped));
            switch (TYPE(tipeItem(dropped))){
                case 'V':
                    RETURNTOSENDER(g->b) = true;
                    break;
                case 'H':
                    checkHeavyIteminBag(&g->b, g->tas);
                    activateSpeedBoost(&g->b);
                    break;
                case 'P':
                    activateIncreaseCapacity();
                    break;
                default:
                    break;
            }
            printf("Pesanan %s berhasil diantarkan.\n", TYPE_DESC(tipeItem(dropped)));
            printf("Uang yang didapatkan: %d Yen\n", VALUE(tipeItem(dropped)));
        }
    }else{
        printf("Tidak ada pesanan yang dapat diantarkan!\n");
    }
}

PrioQueue transformToPrioQueue(Game g){
  PrioQueue pq;
  CreatePrioQueue(&pq);
  for(int i = 0; i < g.jumlah_pesanan; i++){
    enqueue(&pq, g.psn[i]);
  }
  return pq;
}

void pintuKemanaSaja(Game *g){
    int i;
    int idx;
    int count = listDinLength(g->bangunan);
    // Checking index
    printf("Posisi yang dapat dicapai: \n");
    for(i = 0; i < count; i++){
        printf("%d. %c ", i+1, g->bangunan.buffer[i].tipeBangunan);  TulisPOINT(g->bangunan.buffer[i].koor); printf("\n");
    }
    printf("Masukkan lokasi yang ingin dituju: ");
    startWord();
    int choice = atoi(currentWord.contents);
    if(choice > count || choice < 1){
        printf("Input tidak valid. Gadget terpakai.\n");
        return;
    }
    else{
        progress(g);
        updatePosition(g->bangunan.buffer[choice-1]);
    }
    printf("Pintu Kemana Saja berhasil digunakan!\n");
}

void senterPengecil(Game *g){
  if(TOP(g->tas).tipeItem.type == 'H'){
    SENTERPENGECIL(g->b) = true;
    HEAVY(g->tas)--;
    printf("Senter pengecil berhasil digunakan\n");
  }else{
    printf("JIAKH SIA SIA BOS HAHA\n");
  }
}

void displayInventory(GadgetList *I, Game *g){
    int user_input;
    for(int i=0; i<INVENTORY_CAP; i++){
        printf("%d. ", i+1);
        if(ID_GADGET((*I).buffer[i]) == ID_UNDEF){
            printf("-\n");
        }else{
            int ids = ID_GADGET((*I).buffer[i]);
            printf("%s\n", NAME((*I).buffer[i]));
        }
    }
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
    printf("\n");

    printf("ENTER COMMAND: ");
    startWord();
    user_input = atoi(currentWord.contents);
    if (user_input > 0 && user_input <= 5){
        int gadget_id = ID_GADGET((*I).buffer[user_input-1]);
        if (gadget_id != ID_UNDEF){
            if (gadget_id == 0){
                kainPembungkusWaktu(&g->tas, &inProgress);
                ID_GADGET((*I).buffer[user_input-1]) = ID_UNDEF;
            }
            else if(gadget_id == 1){
              senterPembesar(&stack_capacity);
              ID_GADGET((*I).buffer[user_input-1]) = ID_UNDEF;
            }
            else if(gadget_id == 2){
              pintuKemanaSaja(g);
              ID_GADGET((*I).buffer[user_input-1]) = ID_UNDEF;
            }
            else if(gadget_id == 3){
                mesinWaktu(&currentTime, &g->tas, &inProgress);
                ID_GADGET((*I).buffer[user_input-1]) = ID_UNDEF;
            }
            else if(gadget_id == 4){
                senterPengecil(g);
                ID_GADGET((*I).buffer[user_input-1]) = ID_UNDEF;
            }
        }else{
            printf("Tidak ada gadget yang dapat digunakan!\n");
        }
    }else if(user_input == 0 ){
        printf("Kembali ke menu\n");
        /* back to menu*/
    }
    else{
        printf("input tidak valid\n");
    }
}

void save(Game *g) {
  FILE *savefile;
  printf("Masukkan nama save file permainan: ");
  startWord();
  Word filename = atoi(currentWord);
  savefile = fopen(filename, "w");
  fprintf(savefile, "%d %d\n", g->size.X, g->size.Y);
  fprintf(savefile, "%d %d\n", g->hq.koor.X, g->hq.koor.Y);
  fprintf(savefile, "%d\n", g->jumlah_lokasi);
  for (int i = 0; i < g->bangunan.nEff; i++) {
    fprintf(savefile, "%c %d %d\n", g->bangunan.buffer[i].tipeBangunan, g->bangunan.buffer[i].koor.X, g->bangunan.buffer[i].koor.Y);
  }
}