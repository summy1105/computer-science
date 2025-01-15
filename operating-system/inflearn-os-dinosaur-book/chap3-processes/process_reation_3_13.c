#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    pid_t pid;
    pid = fork();

    if(pid == 0){ //child process
        pid_t childPid = getpid();
        printf("child: pid = %d\n", pid); // 새로 생성된 process에서는 fork()반환값은 0
        printf("child's pid = %d\n", childPid);
    }
    else if(pid >0){ // parent process
        wait(NULL);
        pid_t parentPid = getpid();
        printf("parent's child pid = %d\n", pid);
        printf("parent pid = %d\n", parentPid);
    }

    return 0;
}