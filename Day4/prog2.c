#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("Pid of program 2 = %d\n", getpid());
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}