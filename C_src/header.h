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
void JALR(unsigned int instr);

void BRANCH(unsigned int instr);

void LOAD(unsigned int instr);

void STORE(unsigned int instr);

void print_reg(unsigned int reg);
void print_bin(unsigned int instr, int size);
void *projectm(int fd, int prot, int nb_oct);
int size_fd(int fd);
char *ft_writefd(int fd, int nb_oct);
char *ft_readfd(int fd, int nb_oct);

typedef struct s_R_type R_type;
struct s_R_type
{
  unsigned int opcode : 7;
  unsigned int rd     : 5;
  unsigned int funct3 : 3;
  unsigned int rs1    : 5;
  unsigned int rs2    : 5;
  unsigned int funct7 : 7;
};

typedef struct s_I_type I_type;
struct I_type
{
  unsigned int opcode : 7;
  unsigned int rd     : 5;
  unsigned int funct3 : 3;
  unsigned int rs1    : 5;
  unsigned int imm    : 12;
};

typedef struct s_S_type S_type;
struct s_S_type
{
  unsigned int opcode : 7;
  unsigned int imm4_0 : 5;
  unsigned int funct3 : 3;
  unsigned int rs1    : 5;
  unsigned int rs2    : 5;
  unsigned int imm11_5: 7;
};

typedef struct s_B_type B_type;
struct s_B_type
{
  unsigned int opcode : 7;
  unsigned int imm11  : 1;
  unsigned int imm4_1 : 4;
  unsigned int funct3 : 3;
  unsigned int rs1    : 5;
  unsigned int rs2    : 5;
  unsigned int imm10_5: 6;
  unsigned int imm12  : 1;
};

typedef struct s_U_type U_type;
struct s_U_type
{
  unsigned int opcode   : 7;
  unsigned int rd       : 5;
  unsigned int imm31_12 : 20;
};

typedef struct s_J_type J_type;
struct s_J_type
{
  unsigned int opcode   : 7;
  unsigned int rd       : 5;
  unsigned int imm19_12 : 8;
  unsigned int imm11    : 1;
  unsigned int imm10_1  : 10;
  unsigned int imm20    : 1;
};

