#include <stdio.h>
#include <stdlib.h>
// 환경변수를 확인 하기 위한 코
int main(int argc, char *argv[])
{
  char **ptr;
  char *nptr;
  extern char **environ;
  for (ptr = environ; *ptr != 0; ptr++) /* print all environments */
    printf("%s \n", *ptr);
  nptr = getenv("HOME");
  printf("HOME = %s \n", nptr);
  nptr = getenv("SHELL");
  printf("SHELL = %s \n", nptr);
  nptr = getenv("PATH");
  printf("PATH = %s \n", nptr);
  exit(0);
}
// 아래 주석은 fptr-ex에관한 주석
/* C 언어에서 함수는 메모리 상의 주소를 갖습니다. 함수 이름 그 자체는 해당 함수가 위치한 메모리 주소를 나타내며, 이를 함수 포인터라고 부릅니다. 함수 포인터는 일반적인 변수와 마찬가지로 선언하여 사용할 수 있습니다. */
