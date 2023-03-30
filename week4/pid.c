#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
  int pid;
  printf("Original process : pid = %d \t ppid = %d \t pgrp = %d \t pgid = %d\n", getpid(), getppid(), getpgrp(), getpgid(getpid()));

  pid = fork();
  if (pid != 0)
  { // parent
    printf("parent process : pid = %d \t ppid = %d \t pgrp = %d \t pgid = %d\n", getpid(), getppid(), getpgrp(), getpgid(getpid()));
  }
  else
  {
    printf("child process : pid = %d \t ppid = %d \t pgrp = %d \t pgid = %d\n", getpid(), getppid(), getpgrp(), getpgid(getpid()));
  }
  return 0;
}