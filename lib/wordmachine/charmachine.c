/* File: charmachine.c */
/* Implementasi Character Engine */

#include "charmachine.h"
#include <stdio.h>
#include <stdlib.h>

char currentChar;
boolean eot;

static FILE * tape;
static int retval;

void start() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	tape = stdin;
	adv();
}

void startFromFile(char *str){
       // fclose(tape);
       tape = fopen(str, "r");
       if(tape == NULL){
              printf("File tidak ditemukan. Exiting....\n");
              exit(0);
       }
       adv();
}

void adv() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
		      Jika  currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = fscanf(tape,"%c",&currentChar);
       // if (retval == EOF){
       //        fclose(tape);
       // }
	eot = (currentChar == MARK);
	// if (eot) {
       // fclose(tape);
 	// }
}