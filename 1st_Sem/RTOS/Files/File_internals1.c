/*Write a C program which uses the fork system call for spawning new processes as described below:
 Let the parent create a child process, and let it display 'Hello world' message 'n' times, both to
  the screen, and to a newly created output File wherein the value of 'n' is input by the user. 
  Let the child process compute the sum of the 1st 'n' natural numbers and print it to the screen. 
  Once the child completes its execution the parent should fork again. This time the new child 
  should execute the "pwd" shell command. The parent process ends by displaying "Main thread exits" 
  message to the screen.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    int n;
    printf("Enter a value for 'n': ");
    scanf("%d", &n);

    // Create the child process , first fork
    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (child_pid == 0) {
        // Child process
        printf("Child process (PID %d) calculates the sum of the first %d natural numbers.\n", getpid(), n);

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }

        printf("Sum of the first %d natural numbers is: %d\n", n, sum);

        // Create a new child process to execute "pwd" command
        pid_t pwd_child_pid = fork(); //second fork

        if (pwd_child_pid < 0) { 
            perror("Fork for pwd failed");
            exit(1);
        }

        if (pwd_child_pid == 0) {
            // This is the new child process
            printf("Child process (PID %d) executes 'pwd' command:\n", getpid());
            execlp("pwd", "pwd", NULL); //https://www.javatpoint.com/execlp-function-in-c

            // If exec fails, print an error
            perror("exec");
            exit(1);
        }

        // Wait for the "pwd" child process to complete
        int status;
        waitpid(pwd_child_pid, &status, 0);

        printf("Child process (PID %d) has executed 'pwd' and exited.\n", getpid());
    } else {
        // Parent process , main parent
        printf("Parent process (PID %d) displays 'Hello world' %d times and writes to the output file.\n", getpid(), n);

        // Create and open the output file
        FILE *output_file = fopen("output.txt", "w");
        if (output_file == NULL) {
            perror("Error opening output file");
            exit(1);
        }

        for (int i = 0; i < n; i++) {
            printf("Hello world\n");
            fprintf(output_file, "Hello world\n");
            /*The fprintf function works similarly to printf, but instead of writing to the standard output, 
            it writes to the specified file*/
        }

        fclose(output_file);//close the file

        // Wait for the child process to complete
        int status;
        waitpid(child_pid, &status, 0);

        printf("Parent process (PID %d) has completed.\n");
    }

    printf("Main thread exits.\n");
    return 0;
}
