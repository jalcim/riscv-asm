#include "header.h"

void OP_IMM(unsigned int *bin)
{
  I_type *instr;
  unsigned int imm;

  instr = (I_type *)bin;
  switch (instr->funct3)
    {
    case 0:
      printf("addi ");
      break;
    case 2:
      printf("slti ");      
      break;
    case 3:
      printf("sltiu ");
      break;
    case 7:
      printf("andi ");
      break;
    case 6:
      printf("ori ");
      break;
    case 4:
      printf("xori ");
      break;
    case 1:
      printf("slli ");
      break;
    case 5:
      printf("slri | srai ");
      break;
    default:
      break;
    }
  imm = I_immediate(instr);
  printf("x%d, x%d 0x%x\n", instr->rd, instr->rs1, imm);  
}
