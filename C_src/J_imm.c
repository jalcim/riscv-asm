#include "header.h"

unsigned int J_immediate(J_type *instr)
{
  J_imm j_imm;
  unsigned int value;

  j_imm.padding   = 0x0;
  j_imm.inst24_21 =  instr->imm10_1 & 0xf;
  j_imm.inst30_25 = (instr->imm10_1 >> 4) & 0x3f;
  j_imm.inst20    =  instr->imm11;
  j_imm.inst19_12 = instr->imm19_12;
  j_imm.inst31    = instr->imm20;
  value = *(unsigned int *)&j_imm;
  return (value);
}
