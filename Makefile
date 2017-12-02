run: os.bin
	qemu-system-i386 -fda os.bin

runFile: $(file).bin
	qemu-system-i386 -fda $(file).bin

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm -rf *.bin
