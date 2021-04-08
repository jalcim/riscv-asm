#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>

void print_bin(unsigned int instr, int size)
{
  unsigned int mask = 1;
  int cpt;

  cpt = -1;
  while (++cpt < size)
    {
      printf("%d", mask & instr ? 1 : 0);
      mask <<= 1;
    }
}

void I_TYPE_reg(unsigned int reg)
{
  printf("x%d", reg);
}

void I_TYPE_funct3(unsigned int funct3)
{
  switch (funct3)
    {
    case 0:
      printf("addi ");
      break;
    case 2:
      printf("slti ");      
      break;
    case 3:
      printf("sltiu ");
      break;
    case 7:
      printf("andi ");
      break;
    case 6:
      printf("ori ");
      break;
    case 4:
      printf("xori ");
      break;
    case 1:
      printf("slli ");
      break;
    case 5:
      printf("slri | srai ");
      break;
    default:
      break;
    }
}

void I_TYPE(unsigned int instr)
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

  printf("imm = ");
  print_bin(imm, 12);
  printf("\trs1 = ");
  print_bin(rs1, 5);
  printf("\tfunct3 = ");
  print_bin(funct3, 3);
  printf("\trd = ");
  print_bin(rd, 5);
  printf("\topcode = ");
  print_bin(opcode, 7);
  printf("\n\n");


  I_TYPE_funct3(funct3);
  I_TYPE_reg(rd);
  printf(", ");
  I_TYPE_reg(rs1);
  printf(", ");
  printf("0x%x\n\n\n", imm);
  
}


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
	{
	  instr[cpt2] = *binary_raw++;
	}
      cpt += cpt2;
      memcpy(&inst, instr, 4);
      printf("instr = %x\n", inst);
      //      print_bin(inst, 32);
      //      printf("\n");
      switch (inst & 0x7f) //1111111
	{
	case 0x13:
	  printf("OP-IMM\n");
	  I_TYPE(inst);
	  break;
	default :
	  //	  printf("unspecified\n");
	break;
	}
    }
}

void *projectm(int fd, int prot, int nb_oct);
int size_fd(int fd);
char *ft_writefd(int fd, int nb_oct);
char *ft_readfd(int fd, int nb_oct);

int main(int argc, char **argv)
{
  int binary_file;
  int sizefd;
  char filename[256];
  char *binary_raw;

  if (argc < 2)
    return (-1);


  strncpy(filename, argv[1], 255);
  filename[255] = 0;
  binary_file = open(filename, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
  if (binary_file == -1)
    {
      perror(filename);
      return (-1);
    }
  
  sizefd = size_fd(binary_file);
  binary_raw = ft_readfd(binary_file, sizefd);
  OPCODE(binary_raw, sizefd);

  munmap(binary_raw, sizefd);
}

char *ft_readfd(int fd, int nb_oct)
{
  char *str;

  str = (char *)projectm(fd, PROT_READ, nb_oct);

  return (str);
}

char *ft_writefd(int fd, int nb_oct)
{
  char *str;

  str = (char *)projectm(fd, PROT_WRITE, nb_oct);

  return (str);
}

int size_fd(int fd)
{
  struct stat status;

  fstat(fd, &status);

  return (status.st_size);
}

void *projectm(int fd, int prot, int nb_oct)
{
  void *addr = NULL;

  addr = mmap(addr, nb_oct, prot, MAP_SHARED, fd, 0);
  if (addr == MAP_FAILED)
    perror("mmap -> ");
  msync(addr, nb_oct, 0);
  return (addr);
}
