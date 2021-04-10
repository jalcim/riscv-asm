#include "header.h"

void JAL(unsigned int instr)
{
  unsigned int opcode;
  unsigned int rd;
  unsigned int imm;

  opcode = instr & 0x7f;
  instr >>= 7;
  rd = instr & 0x1f;
  instr >>= 5;
  imm |= (instr & 0xff);
  instr >>= 8;
  imm |= (instr & 0x1) << 8;
  instr >>= 1;
  imm |= (instr & 0x3ff) << 9;
  instr >>= 10;
  imm |= (instr & 0x1) << 19;

  printf("jal x%d, %x\n", rd, imm);
}
