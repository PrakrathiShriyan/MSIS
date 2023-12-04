/*program that creates three child processes using fork(). Each child process performs a specific task as described:
The first child uses execlp("pwd", "pwd", NULL) to execute the pwd command, which prints the current working directory.
The second child uses execlp("ls", "ls", "-l", NULL) to execute the ls -l command, which lists detailed information 
about files in the current directory.
The third child reads from a file, converts uppercase characters to lowercase, counts alphabetic characters, digits,
and newline characters, and then prints the modified text and counts.
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>

void countAndPrint(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int alphaCount = 0, digitCount = 0, newlineCount = 0;
    int ch;

    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            alphaCount++;
            putchar(tolower(ch)); // Convert to lowercase and print
        } else if (isdigit(ch)) {
            digitCount++;
            putchar(ch);
        } else if (ch == '\n') {
            newlineCount++;
            putchar(ch);
        }
    }

    printf("\nAlphabetic characters: %d\n", alphaCount);
    printf("Digits: %d\n", digitCount);
    printf("Newlines: %d\n", newlineCount);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pid_t pid1, pid2, pid3;

    pid1 = fork();

    if (pid1 == 0) {
        // First child: Print current working directory
        execlp("pwd", "pwd", NULL);
        perror("exec");
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);

        pid2 = fork();

        if (pid2 == 0) {
            // Second child: List detailed information about files in the current directory
            execlp("ls", "ls", "-l", NULL);
            perror("exec");
            exit(EXIT_FAILURE);
        } else {
            wait(NULL);

            pid3 = fork();

            if (pid3 == 0) {
                // Third child: Process file, convert uppercase to lowercase, count characters
                countAndPrint(argv[1]); // Use the provided filename argument
                exit(EXIT_SUCCESS);
            } else {
                wait(NULL);
                printf("All child processes completed.\n");
            }
        }
    }

    return 0;
}
