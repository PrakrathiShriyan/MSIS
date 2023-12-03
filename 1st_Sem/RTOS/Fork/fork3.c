/*1. WAP which forks a new process. Both the parent as well as the child
    processes should display their process ids to the screen. {use getpid(),
    getppid() system calls}
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main()
{
    int pid = fork(); // function creates a new process
    if (pid == 0) //child
    {
        printf("Child Process ID %d\n", getpid()); //child process id 
        printf("Child Process Parent ID %d\n", getppid()); //parent process id 
    }
    else if (pid > 0) //parent
    {
        wait((int *)(NULL));
        printf("Main Process ID %d\n", getpid());
        printf("Main Process Parent ID %d\n", getppid());
    }
    else
    {
        printf("child process creation failed");
    }
    return 0;
}