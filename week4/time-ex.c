#include <sys/times.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
static void pr_times(clock_t, struct tms *, struct tms *);
static void do_cmd(char *);
void err_sys(char *p)
{
  perror(p);
  exit(-1);
}
int main(int argc, char *argv[])
{
  int i;
  for (i = 1; i < argc; i++)
    do_cmd(argv[i]); /* once for each command-line arg */
  exit(0);
}

static void do_cmd(char *cmd) /* execute and time the "cmd" */
{                             // 커맨드를 받아서
  struct tms tmsstart, tmsend;
  clock_t start, end;
  int status;
  printf("\ncommand: %s\n", cmd);
  if ((start = times(&tmsstart)) == -1) /* starting values */ // 시간을 측정하기위한 start
    err_sys("times error");

  if ((status = system(cmd)) < 0) /* execute command */
    err_sys("system() error");
  sleep(5);
  if ((end = times(&tmsend)) == -1) /* ending values */ // 시간을 측정하기위한 end
    err_sys("times error");
  pr_times(end - start, &tmsstart, &tmsend); // 시간 계산을 위함
}
static void pr_times(clock_t real, struct tms *tmsstart, struct tms *tmsend)
{
  static long clktck = 0;
  if (clktck == 0) /* fetch clock ticks per second first time */
    if ((clktck = sysconf(_SC_CLK_TCK)) < 0)
      err_sys("sysconf error");
  printf(" real: %7.2f\n", real / (double)clktck);
  printf(" user: %7.2f\n",
         (tmsend->tms_utime - tmsstart->tms_utime) / (double)clktck);
  printf(" sys: %7.2f\n",
         (tmsend->tms_stime - tmsstart->tms_stime) / (double)clktck);
  printf(" child user: %7.2f\n",
         (tmsend->tms_cutime - tmsstart->tms_cutime) / (double)clktck);
  printf(" child sys: %7.2f\n",
         (tmsend->tms_cstime - tmsstart->tms_cstime) / (double)clktck);
}

// 단순 sleep은 시스템 자원을 잡아두는 것이 아니기 때문에 real만 올라간다.
