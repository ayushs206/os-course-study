#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Pid of program 1 = %d\n", getpid());

    char *args[] = {"prog2", "hello", "world", NULL}; // Arguments for execv
    execv("./prog2", args);

    perror("execv failed"); // If execv returns, it must have failed
    return 1;
}