#include "shell.h"
#define TABLE_LENGTH 4

void aaFunc();
void bbFunc();
void ccFunc();

char * keyWordTable[MAX_TABLE_LENGTH] = {"aa","bb","cc","0"};
int (*funcs[3]) = {aaFunc, bbFunc, ccFunc};
int *null = keyWordTable + 3;

/*
void addKeyWords(){
	int *nextFree = keyWordTable;
	while(strcmp(*nextFree,'0')!= 0){
		// add to this index, add 0 for next char
	}
}
*/

void whichWord(char str[]){
	int wordIndex;
	wordIndex = searchKeyWord(str,MAX_TABLE_LENGTH,0,4);
	funcs[wordIndex]();
}

int searchKeyWord(char str[], int firstIndex, int lastIndex){
	if(first > last){
		return null;
	}
	char *p;
	p = keyWordTable;
	char *mid;
	mid = p+((firstIndex+lastIndex)/2);
	if(strcmp(*str, *mid) == 0 ){
		return mid - p;
	}
	else if(strcmp(*str, *mid) > 0 ){
		return findKeyWord(str,mid-p,lastIndex);
	}
	else{
		return findKeyWord(str,first,mid-p);
	}
}
void aaFunc(){
	kprint("aaFunc");
}
void bbFunc(){
	kprint("bbFunc");
}
void ccFunc(){
	kprint("ccFunc");
}
