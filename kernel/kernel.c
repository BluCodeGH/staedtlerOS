#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"
#include "shell.h"

void main() {
    isr_install();
    irq_install();

    kprint("Type something, it will go through the kernel\n"
        "Type END to halt the CPU\n> ");
}

void user_input(char *input, int scancode) {
    if (strcmp(input, "END") == 0) {
        kprint("Stopping the CPU. Bye!\n");
        asm volatile("hlt");
    }
    if (scancode == 28) { //Enter key
        kprint("\n");
        whichWord(input);
    }
    kprint("\n> ");
}
