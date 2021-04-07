hello: hello.o link.lds
	riscv32-unknown-elf-ld -T link.lds -o hello hello.o

	riscv32-unknown-elf-ld -T link.lds -o retro retro.o
	riscv32-unknown-elf-objcopy -O binary -j .text retro.o retro.raw

hello.o: hello.s retro.s
	riscv32-unknown-elf-as -o hello.o hello.s
	riscv32-unknown-elf-as -o retro.o retro.s

clean:
	rm hello hello.o
	rm retro retro.o retro.raw
