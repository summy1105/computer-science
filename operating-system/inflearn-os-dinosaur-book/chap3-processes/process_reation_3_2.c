#include <stdio.h>
#include <unistd.h>
#include <wait.h>


int main()
{
    fork();
    fork();
    fork();
    printf("process done\n");
    return 0;
}