hello: hello.o link.lds
	riscv32-unknown-elf-ld -T link.lds -o hello hello.o

	riscv32-unknown-elf-ld -T link.lds -o melimelo melimelo.o
	riscv32-unknown-elf-objcopy -O binary -j .text melimelo.o melimelo.raw

	riscv32-unknown-elf-ld -T link.lds -o instr instr.o
	riscv32-unknown-elf-objcopy -O binary -j .text instr.o instr.raw

	riscv32-unknown-elf-ld -T link.lds -o reg reg.o
	riscv32-unknown-elf-objcopy -O binary -j .text reg.o reg.raw

hello.o:
	riscv32-unknown-elf-as -o hello.o asm_src/hello.s
	riscv32-unknown-elf-as -o melimelo.o asm_src/melimelo.s
	riscv32-unknown-elf-as -o instr.o asm_src/instr.s
	riscv32-unknown-elf-as -o reg.o asm_src/reg.s
	gcc C_src/desassembleur.c -o desassembleur

clean:
	rm hello hello.o
	rm melimelo melimelo.o melimelo.raw
	rm instr instr.o instr.raw
	rm reg reg.o reg.raw
	rm desassembleur
