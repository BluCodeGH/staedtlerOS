#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"
#include "shell.h"

void main() {
    isr_install();
    irq_install();

    kprint("Type something, it will go through the kernel\n"
        "Type HELP for help.\n> ");
}

void user_input(char *input, int scancode) {
    if (scancode == 28) { //Enter key
        whichWord(input);
    }
    kprint("\n> ");
}
