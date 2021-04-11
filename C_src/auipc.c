#include "header.h"

void AUIPC(unsigned int *bin)
{
  U_type *instr;

  instr = (U_type *)bin;
  printf("auipc x%d, 0x%x\n", instr->rd, instr->imm31_12);
}
