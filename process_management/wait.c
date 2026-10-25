
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child: Starting\n");
        sleep(2);
        printf("Child: Finished\n");
    }
    else if (pid > 0) {
        wait(NULL);
        printf("Parent: Child has finished\n");
    }

    return 0;
}
