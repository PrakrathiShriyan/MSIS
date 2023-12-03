#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    fork(); //creates a new process by duplicating the existing one
    fork(); //2 more processes are created
    fork(); //4 more processes creared form 4 procd 
    printf("hello\n"); //8 processes will     ed
    return 0;
}

