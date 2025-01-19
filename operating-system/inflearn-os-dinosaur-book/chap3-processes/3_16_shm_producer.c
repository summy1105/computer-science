#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h> // 유닉스 표준 함수(POSIX)들을 정의
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
    const int SIZE = 4096; // the size of shared memory
    const char *name = "OS"; // the name of shared memory
    const char *message_0 = "Hello, ";
    const char *message_1 = "Shared Memory!\n";

    int shm_fd; // the file descriptor of shared memory
    char *ptr; // the pointer to shared memory

    // create the shared memory object
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    if (shm_fd == -1) {
        perror("shm_open failed");
        return 1;
    }

    // configure the size fo the shared memory
    ftruncate(shm_fd, SIZE); // unistd.h 파일크기 변경 : 파일 디스크립터, 설정하려는 파일 크기

    // map the shared memory object
    ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // write to the shred memory
    sprintf(ptr, "%s", message_0);
    ptr += strlen(message_0);
    sprintf(ptr, "%s", message_1);
    ptr += strlen(message_1);

    return 0;
}