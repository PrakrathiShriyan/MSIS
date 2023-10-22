
//file4:total no of characters in given file
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int ch;
    FILE *fp1;
    int count=0;
    fp1 = fopen(argv[1],"r");
    if(fp1 = NULL)
    {
        printf("--Error--");
        exit(-1);
    }
    while(ch=(getc(fp1)!=EOF))
    {
        count++;
    }
        printf("Count: %d",count);
    fclose(fp1);
    return 0;
}