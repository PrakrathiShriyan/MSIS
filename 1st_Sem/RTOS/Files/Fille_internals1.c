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

  int main()
  {
    printf("Enter the value of n");
    scanf("%d",&n);
    int id = fork();
    if(id < 0){
        printf("Error");
        exit(1);
    }
    //if(id==0){printf}
    if(id==0){ //child 
        for(int i=0; i<=n; i++){
        printf("Hello World\n");
        }
        FILE *fp1;
        fp1 = fopen("a.txt" ,w );
        for(int i=0; i<=n; i++){
        fprintf("Hello World\n");
        }
    }
    
  }