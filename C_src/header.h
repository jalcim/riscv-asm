#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>

void OPCODE(char *binary_raw, int sizefd);

void OP_IMM(unsigned int instr);
void LUI(unsigned int instr);
void AUIPC(unsigned int instr);

void OP(unsigned int instr);

void JAL(unsigned int instr);

void print_reg(unsigned int reg);
void print_bin(unsigned int instr, int size);
void *projectm(int fd, int prot, int nb_oct);
int size_fd(int fd);
char *ft_writefd(int fd, int nb_oct);
char *ft_readfd(int fd, int nb_oct);
