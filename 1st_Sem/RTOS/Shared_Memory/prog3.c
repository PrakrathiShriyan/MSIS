#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    int seg_id;
    char *sm;
    char *sm1;
    char ch='a';
    const int len=100;

    int id1, id2, data=0;

    id1=fork();

    if(id1<0)
    {
        printf("I'm the first parent");
        seg_id = shmget(IPC_PRIVATE, len, S_IRUSR | S_IWUSR);
        sm=(char*) shmat(seg_id, NULL, 0);
        sm1=(char*) shmat(seg_id, NULL, 0);

        for(int i=0;i<=10;i++)
        {
            *(sm+1)=data;
            data++;
        }
        for(int i=10; i<36; i++)
        {
            *(sm+1)=ch;
            ch++;
        }
        for(int i=0; i<10; i++)
        {
            printf("%d\t",*(sm+i));
        }
        printf("\n");
        for(int i=10;i<36;i++)
        {
            printf("%c\t",*(sm+i));
        }
        printf("\n");

        id2=fork();

        if(id>0)
        {
            printf("Im the second parent\n");
            for(int i=0;i<10;i++)
            {
                *(sm+i)=*(sm+1)+100;
            }

            for(int i=10;i<36;i++)
            {
                *(sm+i)=*(sm+i)-32;
            }
        }
    }
}