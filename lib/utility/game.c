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
            // currentTime += selisih(possibleMoves[choice-1].koor, currentLocation.koor); 
            // NOTE ini currentTime nya nambah 1 setiap move ga nambah selisih dari pointnya aing salah ngerti kayaknya
            if(FREEZE(g.b)){
              if(TIME(g.b) % 2 != 0){
                TIME(g.b)--;
                checkHeavyIteminBag(g.b, g.tas);
              }else{
                currentTime += 1;
              }
            }else{
              currentTime += 1;
            }
            updatePosition(possibleMoves[choice-1]);
            // printf("Mobita sekarang berada di titik "); TulisLokasi(currentLocation);
        }
    }
}

void pickup(Game g){
  //FIXME masih ada error kalo misalkan ngambil di G gatau kenapa
  Pesanan inputPesanan;
  if(checkPesanan(TODO, currentLocation) == -1){
    printf("Tidak ada item pada bangunan ini.\n");
  }else{
    if(!isStackFull(g.tas)){
      deletePesanan(TODO, &inputPesanan, checkPesanan(TODO, currentLocation));
      push(&g.tas, inputPesanan);
      insertLast(&inProgress, inputPesanan);
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
                  printf("1");
                  blue = true;
                }
                printf("%c", TOP(g.tas).dropOff);
                
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

void dropOff(Game g){
    // NOTE belom dicek karena ngantuk
    if (!isStackEmpty(g.tas)){
        if (getTipeBangunan(currentLocation) == DROPOFF(TOP(g.tas))){
            Pesanan dropped;
            deleteLast(&inProgress, &dropped);
            pop(&g.tas,&dropped);
            currentMoney += VALUE(tipeItem(dropped));
            switch (TYPE(tipeItem(dropped))){
                case 'V':
                    RETURNTOSENDER(g.b) = true;
                    break;
                case 'H':
                    checkHeavyIteminBag(g.b, g.tas);
                    activateSpeedBoost(g.b);
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