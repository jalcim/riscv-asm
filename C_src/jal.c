#include "header.h"

void JAL(unsigned int *bin)
{
  J_type *instr;
  unsigned int imm;

  instr = (J_type *)bin;
  imm = J_immediate(instr);
  printf("jal x%d, 0x%x\n", instr->rd, imm);
}
