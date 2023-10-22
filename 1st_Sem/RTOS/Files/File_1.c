//file1:counting and printing the arguments
#include <stdio.h>
#include <stdlib.h>

int main(int argc , char* argv[]) //argc - argument count, argv - argument vector
{
int i;
printf("Number of arguments: %d\n", argc);
for(i=0;i<argc;i++)
    printf("%s\n", argv[i]);
return 0;
}