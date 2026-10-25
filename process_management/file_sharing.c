
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int fd = open("shared.txt", O_RDONLY);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    char c;
    read(fd, &c, 1);
    printf("Before fork: %c\n", c);

    pid_t pid = fork();

    if (pid == 0) {
        read(fd, &c, 1);
        printf("Child reads: %c\n", c);
    }
    else if (pid > 0) {
        wait(NULL);
        read(fd, &c, 1);
        printf("Parent reads: %c\n", c);
    }
    else {
        perror("fork");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}
