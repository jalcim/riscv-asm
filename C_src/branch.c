#include "header.h"

void BRANCH(unsigned int *bin)
{
  B_type *instr;
  unsigned int imm;
  
  instr = (B_type *)bin;
  switch(instr->funct3)
    {
    case 0:
      printf("beq ");
      break;
    case 1:
      printf("bne ");
      break;
    case 4:
      printf("blt ");
      break;
    case 6:
      printf("bltu ");
      break;
    case 5:
      printf("bge ");
      break;
    case 7:
      printf("bgeu ");
      break;
    default :
      break;
    }
  imm = B_immediate(instr);
  printf("x%d, x%d, 0x%x\n", instr->rs1, instr->rs2, imm);
}
