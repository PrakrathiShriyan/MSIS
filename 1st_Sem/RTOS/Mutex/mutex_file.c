#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#

//pthread_mutex_t is an variable datatype
pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;

void* f1(void*);
void* f2(void*);

int main(int argc, char* argv[1])
{
    pthread_t t1, t2;

//  better keep attribute NULL

    pthread_create(&t1, NULL, f1, argv[]); //give the filename argument here
    pthread_create(&t2, NULL, f2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;

}

//copy content from fp1 to fp2
void* f1(void* argv[1])
{
    FILE *fp1, *fp2;
    char ch;
    //take file fp1 as an argument in consol
    fp1 = fopen(argv[1], "r");
    //create a new file fp2 called output.txt
    fp2 = fopen("output.txt","w");

    //put mutex lock for copying and pasting the contents
    pthread_mutex_lock(&myMutex);
    while((ch = (getc(fp1)!=EOF));
        putc(ch,fp2);
    pthread_mutex_unlock(&myMutex);

    fclose(fp1);
    fclose(fp2);

    pthread_exit(NULL);
}

/*In 2nd function the thread is acquiring a lock on myMutex before reading user input and writing that input string 
count times into the "result.txt" file.
The mutex ensures that only one thread at a time performs these file-writing operations, preventing potential 
conflicts if multiple threads try to access the file simultaneously.
Once the operations are completed and the data is written, the mutex is unlocked, and the file is closed before
the thread exits.
This structure ensures that the file-writing process is synchronized between threads, allowing them to take turns 
writing their respective input strings to the file without interfering with each other's writing operation
*/
//here we get some data from user and append it to the output.txt
void* f2(void* arg)
{
    char data[10];

    FILE *fp;
    fp = fopen("output.txt","a");
    
    pthread_mutex_lock(&myMutex)

    int count = 5;

    printf("Enter the string:\n");

    fgetc(data, sizeof(data), stdin);

    //three parameters, 1-variable to store the data usually in an array
//2-sizeof(variable)-maximum number of characters that can be read into data. sizeof(variable)
//3-stdin: Represents the standard input stream, typically the keyboard when the program is run interactively in the console.
//The fgets function reads characters from stdin into data until either a newline character ('\n'), the maximum 
//number of characters (sizeof(data) - 1), or the end-of-file (EOF) is encountered. After reading, it stores the 
//characters in the data array and appends a null character ('\0') to mark the end of the string.
    
    for(int i=0; i<count; i++)
    {
        int index = 0;
        while(data[index]!='\0')
        {
            putc(data[index],fp);
            index++;
        }
    }

    pthread_mutex_unlock(&myMutex);
    fclose(fp);

    pthread_exit(NULL);
   
}