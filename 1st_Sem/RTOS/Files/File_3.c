//file3:coping data from a.txt,b.txt to c.txt 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2, *fp3;
    int ch;
    fp1 = fopen(argv[1],"r");
    fp3 = fopen(argv[3],"w");
    if(fp1 == NULL)
    {
        printf("--Error--");
        exit(-1);
    }
    if(fp3 == NULL)
    {
        printf("--Error--");
        exit(-1);
    }
    while(ch=(getc(fp1) != EOF))
    putc(ch,fp3);
    fclose(fp1);
    fclose(fp3);
    fp2 = fopen(argv[2],"r");
    fp3 = fopen(argv[3],"a");
    if(fp2 == NULL)
    {
        printf("--Error--");
        exit(-1);
    }
    while(ch=(getc(fp2) != EOF))
    putc(ch,fp3);
    fclose(fp2);
    fclose(fp3);
    return 0 ;
}