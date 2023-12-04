//copying the content in files to another file and diplay the uppercased letters in console
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    FILE *fp1, *fp2;
    char ch;
    fp1 = fopen(argv[1],"r");
    fp2 = fopen("text.txt","w");
    while((ch=getc(fp1))!=EOF){
        putc(ch,fp2);
        if(isupper(ch)){
            putchar(ch);
        }
    }
    printf("\n");
    fclose(fp1);
    fclose(fp2);
}