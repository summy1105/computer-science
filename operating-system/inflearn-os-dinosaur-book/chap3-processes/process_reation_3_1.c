#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int value = 5;

int main()
{
    printf("before fork()\n");
    pid_t pid;
    pid = fork();

    if (pid == 0)
    { // child process
        value += 15;
        printf("child : value = %d\n", value);
        return 0;
    }
    else if (pid > 0) // parent process
    {
        wait(NULL);
        printf("Parent: value =  %d\n", value); // LINE A
    }

    return 0;
}