#include "header.h"

void OP(unsigned int bin)
{
  R_type *instr;

  instr = (t_instr *)&bin;
  switch (instr->funct3)
    {
    case 0x0:
      printf("%s ", instr->funct7 ? "sub" : "add");
      break;
    case 0x2:
      printf("slt ");
      break;
    case 0x3:
      printf("sltu ");
      break;
    case 0x7:
      printf("and ");
      break;
    case 0x6:
      printf("or ");
      break;
    case 0x4:
      printf("xor ");
      break;
    case 0x1:
      printf("sll ");
      break;
    case 0x5:
      printf("%s ", instr->funct7 ? "sra" : "srl");
      break;
    default :
      break;
    }
  printf("x%d, x%d, 0x%d\n", instr->rd, instr->rs1, instr->rs2);
}
