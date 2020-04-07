#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
int main(void)
  {
        pid_t pid;
       	int status;
        if ((pid = fork()) < 0)
       printf("fork error");
       else if (pid == 0)
       exit(7);
       if (waitid(&status) != pid)
       printf("wait error");
       pr_exit(status);
       if ((pid = fork()) < 0)
       printf("fork error");
       else if (pid == 0)
       abort();
       if (waitid(&status) != pid)
       printf("wait error");
       pr_exit(status);
       if ((pid = fork()) < 0)
       printf("fork error");
       else if (pid == 0)
       status /= 0;
       if (waitid(&status) != pid)
       printf("wait error");
       pr_exit(status);
       exit(0);
  
   }
