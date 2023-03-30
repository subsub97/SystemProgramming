#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int ac, char *av[]) // 리턴타입을 가져야한다.
{
  int i;
  char cmdstr[1024];
  strcpy(cmdstr, "/bin/ls ");
  for (i = 1; i < ac; i++)
  {
    strcat(cmdstr, av[i]);
    strcat(cmdstr, " ");
  }
  fprintf(stdout, "cmdstr = \"%s\"\n", cmdstr);
  system(cmdstr);
  exit(0);
}