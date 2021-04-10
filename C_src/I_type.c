void I_type(unsigned int instr)
{
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
}
