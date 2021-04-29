#include "header.h"

unsigned int U_immediate(U_type *instr)
{
  U_imm u_imm;
  unsigned int value;

  u_imm.padding   = 0x0;
  u_imm.inst19_12 = (instr->imm31_12 & 0xff);
  u_imm.inst30_20 = (instr->imm31_12 >> 8) & 0x7ff;
  u_imm.inst31    = (instr->imm31_12 >> 19) & 0x1;
  value = *(unsigned int *)&u_imm;
  return (value);
}
