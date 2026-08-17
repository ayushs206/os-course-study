#include <stdio.h>
#include <unistd.h>

int main() {
    int pid;

    pid = fork(); // Creates a child PID

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("This is the child process. PID: %d\n", getpid());
    } else {
        // Parent process
        printf("This is the parent process. PID: %d, Child PID: %d\n", getpid(), pid);
    }
}