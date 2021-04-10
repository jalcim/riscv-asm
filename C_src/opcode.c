#include "header.h"

void OPCODE(char *binary_raw, int sizefd)
{
  int cpt, cpt2;
  unsigned char instr[4];
  unsigned int inst;

  cpt = 0;
  while (cpt < sizefd)
    {
      cpt2 = -1;
      while (++cpt2 < 4)
	instr[cpt2] = *binary_raw++;

      cpt += cpt2;
      memcpy(&inst, instr, 4);
      //      printf("instr = %x\n", inst);
      //      print_bin(inst, 7);
      //      printf("\n");
      switch (inst & 0x7f) //1111111
	{
	case 0x13://OP-IMM
	  OP_IMM(inst);
	  break;
	case 0x37://LUI
	  LUI(inst);
	  break;
	case 0x17://AUIPC
	  AUIPC(inst);
	  break;
	case 0x33://OP
	  OP(inst);
	  break;
	case 0x6f://JAL
	  JAL(inst);
	  break;
	case 0x67://JALR
	  JALR(inst);
	  break;
	case 0x63://BRANCH
	  BRANCH(inst);
	  break;
	case 0x3://LOAD
	  LOAD(inst);
	  break;
	case 0x23:
	  STORE(inst);
	  break;
	case 0xf://MISC-MEM
	  //	  MISC_MEM();
	  break;
	case 0x73://SYSTEM
	  //	  SYSTEM();
	  break;
	default :
	  printf("unspecified opcode = 0x%x\n", inst & (0xff >> 1));
	break;
	}
    }
}
