#include "header.h"

void JAL(unsigned int *bin)
{
  J_type *instr;

  instr = (J_type *)bin;
  /*
  unsigned int opcode;
  unsigned int rd;
  unsigned int imm;

  opcode = instr & 0x7f;
  instr >>= 7;
  rd = instr & 0x1f;
  instr >>= 5;
  imm = (instr & 0xff) << 11;
  instr >>= 8;
  imm |= (instr & 0x1) << 10;
  instr >>= 1;
  imm |= instr & 0x3ff;
  instr >>= 10;
  imm |= (instr & 0x1) << 19;
  */
  printf("jal x%d, 0xx\n", instr->rd);//, instr->imm);
}
