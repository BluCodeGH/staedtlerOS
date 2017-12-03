#include "shell.h"
#include "../libc/string.h"
#include "../drivers/screen.h"
#include "../libc/mem.h"
#include "../libc/function.h"

#define N_COMMANDS 6

void echo(char args[][32]){
	int i = 0;
	while (*args[i] != '\0') {
		kprint(args[i]);
		kprint(" ");
		i++;
	}
}
void help(char _[][32]){
	kprint("ECHO: Echos any arguments back.\n\
COLCHANGE [fg] [bg]: Changes the terminal colors. fg and bg are numbers 0-15.\n\
END: Halt the CPU.\n\
MAKEMYDAY: Makes your day, duh!");
	UNUSED(_);
}
void end(char _[][32]){
	kprint("Stopping the CPU. Bye!\n");
  asm volatile("hlt");
	UNUSED(_);
}
void meaning(char _[][32]){
	kprint("*Insert cheezy \"I'm smart\" reference here*");
	UNUSED(_);
}
void colChange(char args[][32]){
	int fg = ascii_to_int(args[0]);
	int bg = ascii_to_int(args[1]);
	colorData = bg << 4;
	colorData += fg;
	kprint("Color changed.");
}
void makeMyDay(char _[][32]){
    kprint("          _          \n");
    kprint("        -   -        \n");
    kprint("       - | | -       \n");
    kprint("      |   .   |      \n");
    kprint("       \\_\\_/_/       \n");
    kprint("          |          \n");
    kprint("       ---|---       \n");
    kprint("          |          \n");
    kprint("          |          \n");
    kprint("         / \\         \n");
    kprint("        /   \\        \n");
    UNUSED(_);
}

void whichWord(char str[]){
		char names[N_COMMANDS][16] = {"ECHO", "HELP", "END", "COLCHANGE", "42", "MAKEMYDAY"};
		void (*funcs[N_COMMANDS])(char [][32]) = {&echo, &help, &end, &colChange, &meaning, &makeMyDay};
    
		char cmd[16] = {'\0'};
		char args[32][32] = {'\0'};
		int i = 0;
		int argn = -1;
		while (*str != '\0') {
			if (*str == ' ') {
				argn++;
				i = -1;
			} else {
				if (argn < 0) {
					cmd[i] = *str;
				} else {
					args[argn][i] = *str;
				}
			}
			i++;
			str++;
		}

		int found = 0;
    for(int i = 0;i<N_COMMANDS;i++) {
        if(strcmp(names[i],cmd)==0) {
        		kprint("\n");
            funcs[i](args);
            found = 1;
            break;
        }
    }
    if (found == 0 && strcmp(cmd, "") != 0) {
    	kprint("\nErr: Command not found. Type HELP for help.");
    }
}
