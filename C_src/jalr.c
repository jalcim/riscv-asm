#include "header.h"

void JALR(unsigned int *bin)
{
  I_type *instr;
  unsigned int imm;

  instr = (I_type *)bin;
  imm = I_immediate(instr);
  printf("jalr x%d, x%d, 0x%x\n", instr->rd, instr->rs1, imm);
}
