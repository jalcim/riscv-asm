#include "header.h"

void JAL(unsigned int *bin)
{
  J_type *instr;

  instr = (J_type *)bin;
  printf("jal x%d, 0xx\n", instr->rd);//, instr->imm);
}
