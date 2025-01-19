#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> // 파일제어
#include <unistd.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h> // 메모리 매핑과 관련된 함수들을 정의

int main()
{
    const int SIZE = 4096; // the size of shared memory
    const char *name = "OS"; // the name of shared memory

    int shm_fd; // the file descriptor of shared memory
    char *ptr; // the pointer to shared memory

    // create the shared memory object
    shm_fd = shm_open(name, O_RDONLY, 0666); //fcntl.h: 공유 메모리 이름, 열기모드(O_CREAT, O_RDWR, O_RDONLY 등), 파일권한(8진수)

    // map the shared memory object
    ptr = (char *)mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0); // 파일을 가상메모리 주소 공간에 매핑
    // 파라미터 :  매핑시작 주소, 매핑할 메모리 크기, 메모리 보호 모드, 매핑 속성, 매핑할 파일 디스크립터, 파일의 매핑 시작위치
    // 반환 : sys/mman.h 매핑된 메모리의 시작주소
    if (ptr == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }
    // write to the shred memory
    printf("%s", ptr);

    // remove the shared memory
    shm_unlink(name); // 공유메모리 객체 제거 -> 여기서는 /dev/shm/OS 파일 제거

    return 0;
}