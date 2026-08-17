#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char data[] = "Hello, World!\n";
    char buffer[20];

    fd = open("file.txt", O_CREAT | O_RDWR, 0644);

    write(fd, data, sizeof(data));
    lseek(fd, 0, SEEK_SET);
    read(fd, buffer, sizeof(data));
    close(fd);
    printf("Data read from file: %s\n", buffer);
    return 0;
}