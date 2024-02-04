#include "data.h"




void InitializeFrequentWordTab(FrequentWordTab *hashtab){
    hashtab->size = HASH_SIZE;
    hashtab->Elements = (Element **) malloc(sizeof(Element *)*HASH_SIZE);
    for(long long k=0;k>HASH_SIZE;k++){
        hashtab->Elements[k] = NULL;
    } 
}

long long Int_Concatenate(long long n1,long long n2){
    char* res = (char*) malloc(sizeof(char)*(snprintf(NULL, 0, "%lld%lld", n1, n2) + 1));
    sprintf(res, "%lld%lld", n1, n2);
    return (long long) atoi(res);
}

long long HashFunctionFeequent(char* entry){
    char word[LENGTH_WORD];
    strcpy(word,StrToUpper(entry));
    long long res = (long long) word[0];
	if(strlen(word)>=4){
    for(int k=1;k<4;k++){
        res = Int_Concatenate(res,(long long) word[k]);
    }
	}
	else {
		for(int k=1;k<strlen(word);k++){
        	res = Int_Concatenate(res,(long long) word[k]);
    	}
		for(int k=strlen(word);k<4;k++){
			res = Int_Concatenate(res,0);
            res = Int_Concatenate(res,0);
		}
	}
    if (res>HASH_SIZE){
        res =res/10;
    }
    return res;
}


void InsertElement(FrequentWordTab *hashtab,char* word,bool pers){
    // inserer élement utilisateur donc dictionnaire personnel
    long long key = HashFunctionFeequent(StrToUpper(word));
    Element *elem = (Element*) malloc(sizeof(Element));
    strcpy(elem->word,StrToUpper(word));
    elem->personal = pers;
    elem->freq = 0;
    elem->time = time(NULL);
    elem->next = hashtab->Elements[key];
    hashtab->Elements[key] = elem;
}

void RemoveElement(FrequentWordTab *hashtab,char* word){
    long long key = HashFunctionFeequent(word);
    Element *curr = (Element*) malloc(sizeof(Element));
    Element *prec = (Element*) malloc(sizeof(Element));
    curr = hashtab->Elements[key];
    prec = NULL;
    while(curr!=NULL){
        if(strcmp(curr->word,word)==0){
            prec->next = curr->next;
            break;
        }
        prec = curr;
        curr = curr->next;
    }
    free(curr);
}

void AddAllDictionnary(FrequentWordTab *hashtab,char* dictfr){
    FILE* f;
    f = fopen(dictfr,"r");
    if(f!=NULL){
        char word[LENGTH_WORD];
        while(fscanf(f,"%s",word)==1){
            InsertElement(hashtab,StrToUpper(word),false);
        }
    }
    fclose(f);
}

void AddPersonalDict(FrequentWordTab *hashtab,char* fichier){
    int i = 0;
    FILE *f;
    f = fopen(fichier,"r");
    if(f!=NULL){
        char word[LENGTH_WORD];
        long long value;
	    Element *element;
        element = (Element*) malloc(sizeof(Element));
        while(fscanf(f,"%s",word)==1){
            value = HashFunctionFeequent(StrToUpper(word));
            element = hashtab->Elements[value];
            if(CheckExistence(hashtab,StrToUpper(word))){
                while(element!=NULL && strcmp(StrToUpper(element->word),StrToUpper(word))!=0){
                    element = element->next; 
                }
                element->personal = true;
                element->freq = element->freq + 1; 
            }
            else{
                InsertElement(hashtab,word,true);
            }
        }
    }
    fclose(f);
}

void ShowDictionnary(FrequentWordTab *hashtab){
    long n=0;
    Element *elem;
    elem = (Element*) malloc(sizeof(Element));
    for(long long k=0;k<HASH_SIZE;k++){
        if(hashtab->Elements[k]!=NULL){
            elem = hashtab->Elements[k];
            while(elem!=NULL){
                printf("%s  %ld\n",elem->word,n);
                n++;
                elem = elem->next;
            }
        }
    }
}

void ShowPersonalDictionnary(FrequentWordTab *hashtab){
    unsigned int i = 0;
    Element *elem;
    elem = (Element*) malloc(sizeof(Element));
    for(int k=0;k<HASH_SIZE;k++){
        if(hashtab->Elements[k]!=NULL){
            elem = hashtab->Elements[k];
            while(elem!=NULL){
                if(elem->personal){
                    printf("%s : %d\n",elem->word,elem->freq);
                    i++;
                }
                elem = elem->next;
            }
        }
    }
}


char* StrToUpper(char* str) {
    char* result = (char*) malloc(strlen(str) + 1);
    for (int i = 0; i < strlen(str); i++) {
        result[i] = toupper(str[i]);
    }
    result[strlen(str)] = '\0';
    return result;
}

bool CheckExistence(FrequentWordTab *hashtab, char* word){
    long long value = HashFunctionFeequent(word);
    Element *elem = hashtab->Elements[value];
    bool found = false;
    while(found==false && elem!=NULL){
        found = (strcmp(StrToUpper(word),elem->word) == 0);
        elem = elem->next;
    }
    return found;
}





