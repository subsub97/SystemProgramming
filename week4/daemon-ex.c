#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
  pid_t pid;
  int i = 10000;
  if ((pid = fork()) < 0)
  {
    perror("fork error");
  }
  else if (pid == 0)
  { /* child process  daemon */
    printf("Child: pid = % d\n", getpid());
    close(0);
    close(1);
    close(2);
    setsid(); // terminal close, create new session and process group
    while(1) {
    printf("c(% d)\n", i);
    i++;
    sleep(1);
  }

  else
  { /* parent process */
    printf("Parent: pid = % d\n", getpid());
    printf("Parint: Child pid = % d\n", pid);
    sleep(1);
    printf("Parent: exit\n");
    exit(0);
  }
}
