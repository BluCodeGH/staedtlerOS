#include "shell.h"
#include "../libc/string.h"
#include "../drivers/screen.h"
#include "../libc/mem.h"
#include "../libc/function.h"

#define N_COMMANDS 3

void aaFunc(){
	kprint("aaFunc");
}
void bbFunc(){
	kprint("bbFunc");
}
void ccFunc(){
	kprint("ccFunc");
}

/*
void addKeyWords(){
    int *nextFree = keyWordTable;
    while(strcmp(*nextFree,'0')!= 0){
        // add to this index, add 0 for next char
    }
}
*/

void whichWord(char str[]){
		char names[N_COMMANDS][16] = {"AA", "BB", "CC"};
		void (*funcs[N_COMMANDS])() = {&aaFunc, &bbFunc, &ccFunc};
    //int wordIndex;
    //wordIndex = searchKeyWord(str,0,4);
    for(int i = 0;i<256;i++){
        if(strcmp(names[i],str)==0){
            funcs[i]();
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
        return searchKeyWord(str,mid-p+1,lastIndex);
    }
    else{
        return searchKeyWord(str,firstIndex,mid-p-1);
    }
    return 0;
}
*/
