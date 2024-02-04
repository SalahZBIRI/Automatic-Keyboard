#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define LENGTH_WORD 25 // anticonstitutionnellement
#define HASH_SIZE 99999999

typedef struct element{
    char word[LENGTH_WORD];
    unsigned int freq;
    time_t time;
    bool personal;
    struct element *next;
} Element;

typedef struct frequentWordTab{
    unsigned long long size;
    Element** Elements;

} FrequentWordTab;

void InitializeFrequentWordTab(FrequentWordTab *hashtab);
long long HashFunctionFeequent(char* word);
long long Int_Concatenate(long long n1,long long n2);
void InsertElement(FrequentWordTab *hashtab,char* word,bool pers);
void RemoveElement(FrequentWordTab *hashtab,char* word);
char* StrToUpper(char* str);
void AddAllDictionnary(FrequentWordTab *hashtab,char* dictfr);
void AddPersonalDict(FrequentWordTab *hashtab,char* fichier);
void ShowDictionnary(FrequentWordTab *hashtab);
void ShowPersonalDictionnary(FrequentWordTab *hashtab);
bool CheckExistence(FrequentWordTab *hashtab, char* word);



