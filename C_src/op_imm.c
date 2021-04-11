#include "header.h"

void OP_IMM(unsigned int *bin)
{
  I_type *instr;

  instr = (I_type *)bin;
  /*
  unsigned int opcode = 0;
  unsigned int rd = 0;
  unsigned int funct3 = 0;
  unsigned int rs1 = 0;
  unsigned int imm = 0;

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
  /*
  printf("imm = ");
  print_bin(imm, 12);
  printf("\trs1 = ");
  print_bin(rs1, 5);
  printf("\tfunct3 = ");
  print_bin(funct3, 3);
  printf("\trd = ");
  print_bin(rd, 5);
  printf("\topcode = ");
  print_bin(opcode, 7);
  printf("\n\n");
  */
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
  printf("x%d, x%d 0x%x\n", instr->rd, instr->rs1, instr->imm11_0);  
}
