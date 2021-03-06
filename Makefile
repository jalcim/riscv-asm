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
	gcc -Wall -Werror C_src/desassembleur.c \
	C_src/opcode.c C_src/op_imm.c C_src/lui.c \
	C_src/auipc.c C_src/op.c C_src/jal.c \
	C_src/jalr.c C_src/branch.c C_src/load.c \
	C_src/store.c C_src/I_imm.c \
	C_src/S_imm.c C_src/B_imm.c \
	C_src/U_imm.c C_src/J_imm.c \
	-o desassembleur

clean:
	rm hello hello.o
	rm melimelo melimelo.o melimelo.raw
	rm instr instr.o instr.raw
	rm reg reg.o reg.raw
	rm desassembleur
