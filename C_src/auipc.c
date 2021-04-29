#include "header.h"

void AUIPC(unsigned int *bin)
{
  U_type *instr;
  unsigned int imm;

  instr = (U_type *)bin;
  imm = U_immediate(instr);
  printf("auipc x%d, 0x%x\n", instr->rd, imm);
}
