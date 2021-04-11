#include "header.h"

void STORE(unsigned int *bin)
{
  S_type *instr;

  instr = (S_type *)bin;
  /*
  unsigned int opcode;
  unsigned int imm;
  unsigned int funct3;
  unsigned int rs1, rs2;

  opcode = instr & 0x7f;
  instr >>= 7;
  imm = instr & 0x1f;
  instr >>= 5;
  funct3 = instr & 0x7;
  instr >>= 3;
  rs1 = instr & 0x1f;
  instr >>= 5;
  rs2 = instr & 0x1f;
  instr >>= 5;
  imm |= instr & (0x7f << 5);
  */
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
