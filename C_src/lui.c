#include "header.h"

void LUI(unsigned int instr)
{
  unsigned int opcode;
  unsigned int rd;
  unsigned int imm;

  opcode = instr & 0x7f;
  instr >>= 7;
  rd = instr & 0x1f;
  instr >>= 5;
  imm = instr & 0xfffff;

  printf("lui x%d, %x\n\n", rd, imm);
}
