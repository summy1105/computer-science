#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    pid_t pid;
    pid = fork();

    if(pid == 0){ //child process
        execlp("/bin/ls", "ls", NULL);
        printf("LINE J\n");
    }
    else if(pid >0){
        wait(NULL);
        printf("Child Complete\n");
    }

    return 0;
}