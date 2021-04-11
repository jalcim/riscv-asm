#include "header.h"

void LOAD(unsigned int *bin)
{
  I_type *instr;

  instr = (I_type *)bin;
  
  /*
  unsigned int opcode;
  unsigned int rd;
  unsigned int funct3;
  unsigned int rs1;
  unsigned int imm;

  opcode = instr & 0x7f;
  instr >>= 7;
  rd = instr & 0x1f;
  instr >>= 5;
  funct3 = instr & 0x7;
  instr >>= 3;
  rs1 = instr & 0x1f;
  instr >>= 5;
  imm = instr & 0xfff;
  */
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
  printf("x%d, x%d, 0x%x\n", instr->rd, instr->rs1, instr->imm11_0);
}
