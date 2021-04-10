#include "header.h"

void BRANCH(unsigned int instr)
{
  unsigned int opcode;
  unsigned int rs1, rs2;
  unsigned int funct3;
  unsigned int imm;

  opcode = instr & 0x7f;
  instr >>= 7;
  imm = instr & (0x1 << 10);
  instr >>= 1;
  imm |= instr & 0xf;
  instr >>= 4;
  funct3 = instr & 0x7;
  instr >>= 3;
  rs1 = instr & 0x1f;
  instr >>= 5;
  rs2 = instr & 0x1f;
  instr >>= 5;
  imm |= instr & (0x3f << 4);
  instr >>= 6;
  imm |= instr & (0x1 << 11);

  switch(funct3)
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
  printf("x%d, x%d, 0x%x\n", rs1, rs2, imm);
}
