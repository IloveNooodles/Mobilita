#include <stdio.h>
#include "listpos.h"

void CreateListPos(ListPos *l){
  int i = 0;
  while(i != CAPACITY){
    (*l).contents[i] = VAL_UNDEF;
    i++;
  }
}

int listPosLength(ListPos l){
  int length = 0;
  for(int i = 0; i < CAPACITY; i++){
    if((l).contents[i] != VAL_UNDEF)length++;
    else break;
  }
  return length;
}

boolean isIdxListPosValid(ListPos l, int i){
  return ((i >= 0 && i < CAPACITY));
}

boolean isIdxListPosEff(ListPos l, int i){
  return((i >= 0 && i < listPosLength(l)));
}

boolean isListPosEmpty(ListPos l){
  return (listPosLength(l) == 0);
}

boolean isListPosFull(ListPos l){
  return (listPosLength(l) == CAPACITY);
}

void readListPos(ListPos *l){
  CreateListPos(l);
  int n;
  scanf("%d", &n);
  while(n < 0 || n > CAPACITY){
      scanf("%d", &n);
    }
  int x;
  for(int i = 0; i < n; i++){
    scanf("%d", &x);
    (*l).contents[i] = x;
  }
}

void displayListPos(ListPos l){ 
  if(isListPosEmpty(l)){
    printf("[]");
  }else{
    printf("[");
    for(int i = 0; i < listPosLength(l); i++){
      printf("%d", (l).contents[i]);
      if(i != listPosLength(l) - 1){
        printf(",");
      }
    }
    printf("]");
  }
}

ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus){
  ListPos l;
  CreateListPos(&l);
  if(plus){
    for(int i = 0; i < listPosLength(l1); i++){
      (l).contents[i] = (l1).contents[i] + (l2).contents[i];
    }
  }else{
    for(int i = 0; i < listPosLength(l1); i++){
      (l).contents[i] = (l1).contents[i] - (l2).contents[i];
    }
  }
  return l;
}

boolean isListPosEqual(ListPos l1, ListPos l2){
  boolean eq = true;
  if(listPosLength(l1) == listPosLength(l2)){
    for(int i = 0; i < listPosLength(l1); i++){
      if(l1.contents[i] != (l2).contents[i]){
        eq = false;
        break;
      }
    }
  }else{
    eq = false;
  }
  return eq;
}

int indexOfListPos(ListPos l, ElType val){
  int ans = IDX_UNDEF;
  boolean ada = false;
  for(int i = 0; i < listPosLength(l); i++){
    if((l).contents[i] == val){
      ans = i;
      ada = true;
      break;
    }
  }
  if(ada)return ans;
  else return IDX_UNDEF;
}

void extremes(ListPos l, ElType *max, ElType *min){
  for(int i = 0; i < listPosLength(l); i++){
    if(i == 0){
      *min = (l).contents[i];
      *max = (l).contents[i];
    }
    if(*min > (l).contents[i]){
      *min = (l).contents[i];
    }
    if(*max < (l).contents[i]){
      *max = (l).contents[i];
    }
  }
}

boolean isAllEvenListPos(ListPos l){
  boolean genap = true;
  for(int i = 0; i < listPosLength(l); i++){
    if(l.contents[i] % 2 != 0){
      genap = false;
      break;
    }
  }
  return genap;
}

void sortListPos(ListPos *l, boolean asc){
  if(!isListPosEmpty(*l)){
    for(int i = 0; i < listPosLength(*l); i++){
      for(int j = i+1; j < listPosLength(*l); j++){
        int temp;
        if(asc){
          if((*l).contents[i] > (*l).contents[j]){
            temp = (*l).contents[i];
            (*l).contents[i] = (*l).contents[j];
            (*l).contents[j] = temp;
          }
        }else{
          if((*l).contents[i] < (*l).contents[j]){
            temp = (*l).contents[i];
            (*l).contents[i] = (*l).contents[j];
            (*l).contents[j] = temp;
          }
        }
      }
    }
  }
}

void insertListPosLast(ListPos *l, ElType val){
  (*l).contents[listPosLength(*l)] = val;
}

void deleteListPosLast(ListPos *l, ElType *val){
  *val = (*l).contents[listPosLength(*l)-1];
  (*l).contents[listPosLength(*l)-1] = VAL_UNDEF;
}