// Nama: Gagas Praharsa Bahar
// NIM: 13520016
// Word Machine

#include "../utility/boolean.h"
#include "charmachine.h"
#include "wordmachine.h"
#include <stdio.h>

boolean endWord;
Word currentWord;

void ignoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == BLANK){
        adv();
    }
}
void startWord()
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    start();
    ignoreBlank();
    if (currentChar == MARK){
        endWord = true;
    }
    else{
        endWord = false;
        copyWord();
    }
}

void startWordFromFile(char *str){
    startFromFile(str);
    ignoreBlank();
    if (currentChar == MARK){
        endWord = true;
    }
    else{
        endWord = false;
        copyWord();
    }
}

void advWord()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
{
    Word EMPTY = {"", 0};
    currentWord = EMPTY;
    ignoreBlank();
    if(currentChar == MARK){
        endWord = true;
    }
    else{
        copyWord();
        ignoreBlank();
    }
}

void advNewline()
{
    Word EMPTY = {"", 0};
    currentWord = EMPTY;
    if(currentChar == MARK){
        endWord = false;
        adv();
        copyWord();
    }
}

void copyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
{
    int i = 0;
    while(currentChar != MARK && currentChar != BLANK){
        currentWord.contents[i] = currentChar;
        adv();
        i++;
    }
    if (i > CAPACITY){
        currentWord.length = CAPACITY;
    }
    else{
        currentWord.length = i;
    }
}

void copyWordFromWord(Word w1, Word w2)
{
    w2.length = w1.length;
    for(int i = 0; i < w1.length; i++){
        w2.contents[i] = w1.contents[i];
    }
    
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