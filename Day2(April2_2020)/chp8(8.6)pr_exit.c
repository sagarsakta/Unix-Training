#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
int main(void)
{
void pr_exit(int status)
  {
  if (WIFEXITED(status))
  printf("normal termination, exit status = %d\n",
  WEXITSTATUS(status));
  else if (WIFSIGNALED(status))
  printf("abnormal termination, signal number = %d%s\n",
  WTERMSIG(status),
  WCOREDUMP(status) ? " (core file generated)" : "");
  else if (WIFSTOPPED(status))
  printf("child stopped, signal number = %d\n",
  WSTOPSIG(status));
  }
 exit(0);
 }
