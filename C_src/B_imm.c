#include <stdio.h>
#include <stdlib.h>
#include "header.h"

unsigned int B_immediate(B_type *instr)
{
  B_imm *bim = (B_imm *)malloc(sizeof(B_imm));
  unsigned int value;

  bim->imm0 = 0;
  bim->imm11_8 = instr->imm4_1;
  bim->imm30_25 = instr->imm10_5;
  bim->imm7 = instr->imm11;
  bim->imm31 = instr->imm12;
  value = *(unsigned int *)bim;

  return (value);
}
