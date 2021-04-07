hello: hello.o link.lds
	riscv32-unknown-elf-ld -T link.lds -o hello hello.o

	riscv32-unknown-elf-ld -T link.lds -o retro retro.o
	riscv32-unknown-elf-objcopy -O binary -j .text retro.o retro.raw

	riscv32-unknown-elf-ld -T link.lds -o instr instr.o
	riscv32-unknown-elf-objcopy -O binary -j .text instr.o instr.raw

hello.o: hello.s retro.s instr.s
	riscv32-unknown-elf-as -o hello.o hello.s
	riscv32-unknown-elf-as -o retro.o retro.s
	riscv32-unknown-elf-as -o instr.o instr.s

clean:
	rm hello hello.o
	rm retro retro.o retro.raw
	rm instr instr.o instr.raw
