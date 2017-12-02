#include "shell.h"
#include "../libc/string.h"
#include "../drivers/screen.h"
#define TABLE_LENGTH 4

void aaFunc();
void bbFunc();
void ccFunc();

char * keyWordTable[TABLE_LENGTH] = {"aa","bb","cc","0"};
void (*funcs[3])() = {&aaFunc, &bbFunc, &ccFunc};

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
	//wordIndex = searchKeyWord(str,0,4);
	int i = 0;
	for(i;i<TABLE_LENGTH;i++){
		if(strcmp(keyWordTable[i],str)==0){
			funcs[wordIndex]();
			break;
		}
	}
}

/*
int searchKeyWord(char str[], int firstIndex, int lastIndex){
	if(firstIndex > lastIndex){
		return 0;
	}
	char *p;
	p = keyWordTable[0];
	char *mid;
	mid = p+((firstIndex+lastIndex)/2);
	if(strcmp(str, mid) == 0 ){
		return mid - p;
	}
	else if(strcmp(str, mid) > 0 ){
		return searchKeyWord(str,mid-p,lastIndex);
	}
	else{
		return searchKeyWord(str,firstIndex,mid-p);
	}
	return 0;
}
*/
void aaFunc(){
	kprint("aaFunc");
}
void bbFunc(){
	kprint("bbFunc");
}
void ccFunc(){
	kprint("ccFunc");
}
