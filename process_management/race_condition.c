
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>

int main() {
    int *counter = mmap(NULL, sizeof(int),
                        PROT_READ | PROT_WRITE,
                        MAP_SHARED | MAP_ANONYMOUS,
                        -1, 0);

    if (counter == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    *counter = 0;

    pid_t pid = fork();

    if (pid == 0) {
        for (int i = 0; i < 100000; i++)
            (*counter)++;
        exit(0);
    }
    else if (pid > 0) {
        for (int i = 0; i < 100000; i++)
            (*counter)++;

        wait(NULL);
        printf("Final counter: %d\n", *counter);
    }
    else {
        perror("fork");
        munmap(counter, sizeof(int));
        return 1;
    }

    munmap(counter, sizeof(int));
    return 0;
}
