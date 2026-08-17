#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int pid;

    pid = fork(); // Creates a child PID

    if (pid == 0) {
        // Child process
        printf("Child Process %d \n", getpid());
        exit(0);
    } else {
        wait(NULL); // Parent process waits for the child to finish
        printf("Parent Process %d \n", getpid());
    }
}