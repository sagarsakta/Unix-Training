#include<stdio.h>
#include<stdlib.h>
#include <setjmp.h>
#include<unistd.h>
#include<signal.h>
#include <sys/types.h>
static void sig_alrm(int);
static jmp_buf env_alrm;
int
main(void)
{
int n;
char line[MAXLINE];
if (signal(SIGALRM, sig_alrm) == SIG_ERR)
printf("signal(SIGALRM) error");
if (setjmp(env_alrm) != 0)
printf("read timeout");
alarm(10);
if ((n = read(STDIN_FILENO, line, MAXLINE)) < 0)
printf("read error");
alarm(0);
write(STDOUT_FILENO, line, n);
exit(0);
}
static void
sig_alrm(int signo)
{
longjmp(env_alrm, 1);
}
