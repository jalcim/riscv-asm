#include "header.h"

unsigned int B_immediate(B_type *instr)
{
  B_imm b_imm;
  unsigned int value;

  b_imm.padding     = 0x0;
  b_imm.inst11_8  = instr->imm4_1;
  b_imm.inst30_25 = instr->imm10_5;
  b_imm.inst7     = instr->imm11;
  b_imm.inst31    = instr->imm12;
  value = *(unsigned int *)&b_imm;

  return (value);
}
