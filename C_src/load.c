#include "header.h"

void LOAD(unsigned int *bin)
{
  I_type *instr;
  unsigned int imm;

  instr = (I_type *)bin;
  switch(instr->funct3)
    {
    case 0x2:
      printf("lw ");
      break;
    case 0x1:
      printf("lh ");
      break;
    case 0x5:
      printf("lhu ");
      break;
    case 0x0:
      printf("lb ");
      break;
    case 0x4:
      printf("lbu ");
      break;
    default :
      break;
    }
  imm = I_immediate(instr);
  printf("x%d, x%d, 0x%x\n", instr->rd, instr->rs1, imm);
}
