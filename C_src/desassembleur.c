#include "header.h"

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

void print_reg(unsigned int reg)
{
  printf("x%d", reg);
}

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
