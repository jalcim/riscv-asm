void MISC_MEM(unsigned int instr)
{
  unsigned int opcode;
  unsigned int rd;
  unsigned int funct3;
  unsigned int rs1;
  unsigned int sw, sr, so, si, pw, pr, po, pi, fm;

  opcode = instr &;
  instr >>= 7;
  rd = instr &;
  instr >>= 5;
  funct3 = instr &;
  instr >>= 3;
  rs1 = instr &;
  instr >>= 5;
  sw = instr &;
  instr >>= 1;
  sr = instr &;
  instr >>= 1;
  so = instr &;
  instr >>= 1;
  si = instr &;
  instr >>= 1;
  pw = instr &;
  instr >>= 1;
  pr = instr &;
  instr >>= 1;
  po = instr &;
  instr >>= 1;
  pi = instr &;
  instr >>= 1;
  fm = instr &;
  instr >>= 4;
}
