#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>


void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
    srand(time(NULL));
     pid_t  pid;

     pid = fork();
     if (pid < 0) {
       printf("Error\n");
     }
     else if (pid == 0) 
          ChildProcess();
     else 
          ParentProcess();
}

void  ChildProcess(void)
{
     int   i;

     for (i = 1; i <= (rand() % 30 + 1); i++){
          printf("Child Pid: %d is going to sleep!\n", getpid());
          sleep(rand() % 10 + 1);
          printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", getpid(),getppid());
     }
     exit(0);
}

void  ParentProcess(void)
{
    pid_t  pid;
    pid = fork();
    if (pid == 0){
      ChildProcess();
    }
    else if (pid > 0){
      int status;
      pid_t child1 = wait(&status);
      pid_t child2 = wait(&status);
      printf("Child Pid: %d has completed\n", child1);
      printf("Child Pid: %d has completed\n", child2);
    }
}