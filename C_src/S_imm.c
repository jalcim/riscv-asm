#include "header.h"

unsigned int S_immediate(S_type *instr)
{
  S_imm s_imm;
  unsigned int value;

  s_imm.inst7     =  instr->imm4_0  & 0x1;
  s_imm.inst11_8  = (instr->imm4_0  & 0x1e) >> 1;
  s_imm.inst30_25 =  instr->imm11_5 & 0x3f;
  s_imm.inst31    = (instr->imm11_5 & 0x40) >> 6;
  value = *(unsigned int *)&s_imm;
  return (value);
}
