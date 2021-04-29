#include "header.h"

unsigned int I_immediate(I_type *instr)
{
  I_imm i_imm;
  unsigned int value;
  
  i_imm.inst20    = instr->imm11_0 & 0x1;
  i_imm.inst24_21 = (instr->imm11_0 & 0x1e) >> 1;
  i_imm.inst30_25 = (instr->imm11_0 & 0x7e0) >> 5;
  i_imm.inst31    = (instr->imm11_0 & 0x800) >> 11;
  value = *(unsigned int *)&i_imm;

  return (value);
}
