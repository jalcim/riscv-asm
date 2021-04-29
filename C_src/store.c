#include "header.h"

void STORE(unsigned int *bin)
{
  S_type *instr;

  instr = (S_type *)bin;

  switch(instr->funct3)
    {
    case 0x0:
      printf("sb ");
      break;
    case 0x1:
      printf("sh ");
      break;
    case 0x2:
      printf("sw ");
      break;
    default :
      break;
    }
  printf("x%d, x(x%d)\n", instr->rs2, /*instr->imm,*/ instr->rs1);
}
