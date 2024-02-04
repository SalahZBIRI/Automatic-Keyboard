
#include <stdlib.h>

int PropositionFreq(FrequentWordTab *hashtab,char* entry,Element* p1,Element* p2,Element* p3,int mode);
int CountZeros(long long num);
void FindTreeLargest(Element** arr,Element* p1,Element* p2,Element* p3,unsigned int n,int mode);
void SortByPrefix(Element** list,unsigned int n,char* entry);
Element** FindSimilarDictionnary(FrequentWordTab *hashtab,char* word);
int min(int a,int b);
void _three_not_nufirstll(Element** arr, int size, Element** out_arr,int n) ;
long ListElementSize(Element** arr,long index);
bool IsEmpty(Element** arr,long size);