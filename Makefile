hello: hello.o link.lds
	riscv32-unknown-elf-ld -T link.lds -o hello hello.o

	riscv32-unknown-elf-ld -T link.lds -o retro retro.o
	riscv32-unknown-elf-objcopy -O binary -j .text retro.o retro.raw

	riscv32-unknown-elf-ld -T link.lds -o instr instr.o
	riscv32-unknown-elf-objcopy -O binary -j .text instr.o instr.raw

	riscv32-unknown-elf-ld -T link.lds -o reg reg.o
	riscv32-unknown-elf-objcopy -O binary -j .text reg.o reg.raw

hello.o: hello.s retro.s instr.s
	riscv32-unknown-elf-as -o hello.o hello.s
	riscv32-unknown-elf-as -o retro.o retro.s
	riscv32-unknown-elf-as -o instr.o instr.s
	riscv32-unknown-elf-as -o reg.o reg.s
	gcc desassembleur.c -o desassembleur

clean:
	rm hello hello.o
	rm retro retro.o retro.raw
	rm instr instr.o instr.raw
	rm reg reg.o reg.raw
	rm desassembleur
