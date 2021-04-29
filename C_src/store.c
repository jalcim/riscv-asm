#include "header.h"

void STORE(unsigned int *bin)
{
  S_type *instr;
  unsigned int imm;

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
  imm = S_immediate(instr);
  printf("x%d, 0x%x(x%d)\n", instr->rs2, imm,instr->rs1);
}
