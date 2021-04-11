#include "header.h"

void LUI(unsigned int *bin)
{
  U_type *instr;

  instr = (U_type *)bin;
  printf("lui x%d, 0x%x\n", instr->rd, instr->imm31_12);
}
