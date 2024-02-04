#include <stdlib.h>
#include <math.h>
#include "data.h"
#include "prediction.h"
#include <string.h>
#include <stdio.h>

int PropositionFreq(FrequentWordTab *hashtab,char* entry,Element* p1,Element* p2,Element* p3,int mode){
    long long value = HashFunctionFeequent(StrToUpper(entry));
    unsigned int index = 0;
    int n = CountZeros(value);
    Element* elem;
    elem = (Element*) malloc(sizeof(Element));
    Element** PossibleSolutions;
    PossibleSolutions = (Element**) malloc(1000000*sizeof(Element*));
    if(n>1){
        int borneSup = 0;
        for(int k=0;k<n;k++){
            borneSup = borneSup + 9*pow(10,k);
        }
        for(int k=value;k<value+borneSup;k++){
            elem = hashtab->Elements[k];
            while(elem!= NULL){
                if(elem->personal){
                    PossibleSolutions[index] = elem;
                }
                index ++;
                elem = elem->next;
            }
        }
    }
    else{
        elem = hashtab->Elements[value];
        while(elem!=NULL){
            if(elem->personal)
                PossibleSolutions[index] = elem;
            index ++;
            elem = elem->next; 
        }
    }
    SortByPrefix(PossibleSolutions,index,entry);
    Element **tmp;
    tmp = (Element**) malloc(sizeof(Element*)*index);
    if(ListElementSize(PossibleSolutions,index)>=3){
        FindTreeLargest(PossibleSolutions,p1,p2,p3,index,mode);
    }
    else if(IsEmpty(FindSimilarDictionnary(hashtab,entry),100000)){
        printf("proposition impossible surement");
    }
    else{
        switch (ListElementSize(PossibleSolutions,index)){
        case 2:
            _three_not_nufirstll(PossibleSolutions,index,tmp,2);
            strcpy(p1->word,tmp[0]->word);
            strcpy(p2->word,tmp[1]->word);
            strcpy(p3->word,FindSimilarDictionnary(hashtab,entry)[1]->word);
            break;
        case 1:
            _three_not_nufirstll(PossibleSolutions,index,tmp,1);
            strcpy(p1->word,tmp[0]->word);
            strcpy(p2->word,FindSimilarDictionnary(hashtab,entry)[0]->word);
            strcpy(p3->word,FindSimilarDictionnary(hashtab,entry)[1]->word);
            break;
        case 0:
            strcpy(p1->word,FindSimilarDictionnary(hashtab,entry)[0]->word);
            strcpy(p2->word,FindSimilarDictionnary(hashtab,entry)[1]->word);
            strcpy(p3->word,FindSimilarDictionnary(hashtab,entry)[2]->word);
            break;
        }
    }
    return 0;
}

Element** FindSimilarDictionnary(FrequentWordTab *hashtab,char* word){
    int index = 0;
    int size = 0;
    Element* elem;
    //elem = (Element*) malloc(sizeof(Element));
    Element** PSB;
    PSB = (Element**) malloc(100000*sizeof(Element*));
    for(int k=0;k<HASH_SIZE;k++){
        elem = hashtab->Elements[k];
        while(elem!=NULL){
            size = min(strlen(word),strlen(elem->word));
                if(strncmp(StrToUpper(elem->word),StrToUpper(word),size)==0 && elem->personal==false){
                    PSB[index] = elem;
                    index++;
            }
            if(index>=3)
                break;
            elem = elem->next;
        }
    }
    return PSB;
}

void FindTreeLargest(Element** arr,Element* p1,Element* p2,Element* p3,unsigned int n,int mode) {
    Element **tmp;
    tmp = (Element**) malloc(sizeof(Element*)*n);
    _three_not_nufirstll(arr,n,tmp,3);
    Element* elem1;
    Element* elem2; 
    Element* elem3;
    elem1 = (Element*) malloc(sizeof(Element));
    elem2 = (Element*) malloc(sizeof(Element));
    elem2 = (Element*) malloc(sizeof(Element));
    elem1 = tmp[0];
    elem2 = tmp[1];
    elem3 = tmp[2];
    if(mode == 0){
        for (int i=1;i<n;i++){
            if(arr[i]!=NULL){
                if (arr[i]->freq > elem1->freq) {
                    elem3 = elem2;
                    elem2 = elem1;
                    elem1 = arr[i];
                }
                else if (arr[i]->freq > elem2->freq) {
                    elem3 = elem2;
                    elem2 = arr[i];
                }
                else if (arr[i]->freq > elem3->freq) {
                    elem3 = arr[i];
                }
            }
        }
    }
    else if(mode==1){
         for (int i=1;i<n;i++){
            if(arr[i]!=NULL){
                if (arr[i]->time > elem1->time) {
                    elem3 = elem2;
                    elem2 = elem1;
                    elem1 = arr[i];
                }
                else if (arr[i]->time > elem2->time) {
                    elem3 = elem2;
                    elem2 = arr[i];
                }
                else if (arr[i]->time > elem3->time) {
                    elem3 = arr[i];
                }
            }
        }
    }
    
    strcpy(p1->word,elem1->word);
    strcpy(p2->word,elem2->word);
    strcpy(p3->word,elem3->word);
}

int CountZeros(long long num){
    int count = 0;
    while (num % 10 == 0){
        count++;
        num /= 10; 
    }
    return count;
}

void SortByPrefix(Element** list,unsigned int n,char* entry){ 
    int size = 0;
    for(int k=0;k<n;k++){
        if(list[k]!=NULL){
            size = min(strlen(entry),strlen(list[k]->word));
            if(strncmp(list[k]->word,StrToUpper(entry),size)!=0)
                list[k] = NULL; 
        }
        
    }
}

int min(int a, int b){
    return (a < b) ? a : b;
}

void _three_not_nufirstll(Element** arr, int size, Element** out_arr,int n) {
    int count = 0;
    for (int i = 0; i < size && count < n; i++) {
        if (arr[i] != NULL) {
            out_arr[count] = arr[i];
            count++;
        }
    }
}

long ListElementSize(Element** arr,long index){
    long res=0;
    for(int k=0;k<index;k++){
        if(arr[k]!=NULL)
            res++;
    }
    return res;
}

bool IsEmpty(Element** arr,long size){
    bool res = true;
    for(int k=0;k<size;k++){
        if(arr[k]!=NULL){
            res = false;
        }
    }
    return res;
}

