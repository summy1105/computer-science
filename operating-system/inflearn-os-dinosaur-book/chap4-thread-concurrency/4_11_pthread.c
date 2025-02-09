#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum; // the data shared by the threads
void *runner(void *param);

int main(int argc, char *argv[])
{
    pthread_t tid; // thread identifier
    pthread_attr_t attr; // thread attributes

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);
    pthread_join(tid, NULL);

    printf("sum = %d\n", sum);

    return 0;
}

void *runner(void *param)
{
    int i, upper=atoi(param);
    sum =0;
    for(i = 0; i<=upper; i++)
        sum+=i;
    pthread_exit(0);
}