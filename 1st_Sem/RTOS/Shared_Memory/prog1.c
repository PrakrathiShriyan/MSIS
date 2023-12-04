/* 1. To demonstrate the usage of the various shared memory system
calls- WAP which creates a shared memory segment of length 100 bytes
and writes 'A' to 'Z' to it.
Next, let the same program access the segment area and display its
contents to the screen (all 100 bytes).Let the program next convert
the case of the alphabets in the segment to lowercase. Finally let
the program access the same area and display the segment contents
once again to the screen. Observe the output.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
int seg_id;
char *sm;
char *sm1;
char ch='a';
const int len=100; //declaring some adequate length
int low=32;
int id1,id2,data=0;

id1=fork();

if(id1>0)
{
printf("iam the first parent\n");
seg_id=shmget( IPC_PRIVATE, len, S_IRUSR | S_IWUSR ); //creating shared memeory segment, allocate memory
sm=(char *) shmat(seg_id, NULL, 0); // attach
sm1=(char *) shmat(seg_id, NULL, 0); // attach

for(int i=0;i<=10;i++)
{
*(sm+i)=data; // value in data is being put in sm one by one
data++;
}

for(int i=10;i<36;i++)
{
*(sm+i)=ch; // value in ch is being put in sm one by one
ch++;
}

for(int i=0;i<10;i++)
{
printf("%d\t",*(sm+i));
}
printf("\n");

for(int i=10;i<36;i++)
{
printf("%c\t",*(sm+i));// accessing same value and adding 32 to convert upper case to lower case
}
printf("\n");


id2=fork();

if(id2>0)
{
printf("iam the second parent\n");
for(int i=0;i<10;i++)
{
*(sm+i)=*(sm+i)+100; //incrementing the value by 100
}

for(int i=10;i<36;i++)
{
*(sm+i)=*(sm+i)-32; //characters to upper case
}
}
else if(id2==0) //child
{
printf("iam the second child\n");

for(int i=0;i<10;i++)
{
printf("%d\t",*(sm+i));
}
printf("\n");

for(int i=10;i<36;i++)
{
printf("%c\t",*(sm+i));// accessing same value and adding 32 to convert upper case to lower case
}
printf("\n");
}
}
shmctl(seg_id,IPC_RMID,NULL); //deallocating the segment from the memory area
return 0;
}