#include "header.h"

void OP(unsigned int instr)
{
  unsigned int opcode;
  unsigned int rd;
  unsigned int funct3;
  unsigned int rs1;
  unsigned int rs2;
  unsigned int funct7;

  opcode = instr & 0x7f;
  instr >>= 7;
  rd = instr & 0x1f;
  instr >>= 5;
  funct3 = instr & 0x7;
  instr >>= 3;
  rs1 = instr & 0x1f;
  instr >>= 5;
  rs2 = instr & 0x1f;
  instr >>= 5;
  funct7 = instr & 0x7f;

  switch (funct3)
    {
    case 0x0:
      printf("%s ", funct7 ? "sub" : "add");
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
      printf("%s ", funct7 ? "sra" : "srl");
      break;
    default :
      break;
    }
  printf("x%d, x%d, x%d\n", rd, rs1, rs2);
}
