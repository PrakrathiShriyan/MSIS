#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    int id;
    printf("My id %d \n",getpid());
    printf("My parent id %d \n",getppid());
    id = fork();//creates a new child process that is an exact duplicate of the parent process
   // sleep(10);
    printf("My id %d \n",getpid());
    printf("My parent id %d \n",getppid());
    if(id==-1)
    {
        printf("Not valid\n");
        exit(-1);
    }
    else if(id==0)
    {
        printf("Im child with id %d\n",getpid());
        printf("Im parent with id %d\n",getppid());
    }
    else if(id>0)//parent can have pid greater than 0 or 
    {
        printf("Im parent of child %d with id %d \n",getpid(),getppid());
    }
return 0;
}

//getpid() returns the Process ID (PID) of the calling process
//getppid() returns the Parent Process ID (PPID) of the calling process