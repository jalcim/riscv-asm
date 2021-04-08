ceci est mon travail de retro engineering (la specification risc-v ne fournit pas les binaires des instructions)

le repertoire man contient les pages de manuel que j'ai ecrit sur les binaires

le repertoire C_src contient le desassembleur ainsi que l'assembleur

le repertoire asm_src contient les fichiers sources assembleur

le repertoire retro contient mes analyses de retro-ingenieuring sur les binaires du repertoire asm_src

usage
```
make
./desassembleur instr.raw
qemu-system-riscv32 -machine sifive_u -nographic -kernel hello
make clean
```
