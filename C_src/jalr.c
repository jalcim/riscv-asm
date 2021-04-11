#include "header.h"

void JALR(unsigned int *bin)
{
  I_type *instr;

  instr = (I_type *)bin;
  printf("jalr x%d, x%d, 0x%x\n", instr->rd, instr->rs1, instr->imm11_0);
}
