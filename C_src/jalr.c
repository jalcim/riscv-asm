#include "header.h"

void JALR(unsigned int *bin)
{
  I_type *instr;

  instr = (I_type *)bin;

  /*
  int opcode;
  int rd;
  int funct3;
  int rs1;
  int imm;

  opcode = instr & 0x7f;
  instr >>= 7;
  rd = instr & 0x1f;
  instr >>= 5;
  funct3 = instr & 0x7;
  instr >>= 3;
  rs1 = instr & 0x1f;
  instr >>= 5;
  imm = instr & 0x7ff;
  */

  printf("jalr x%d, x%d, 0x%x\n", instr->rd, instr->rs1, instr->imm11_0);
}
