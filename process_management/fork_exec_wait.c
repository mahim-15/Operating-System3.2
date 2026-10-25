
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Child: Running ls command\n");
        fflush(stdout);

        execl("/bin/ls", "ls", "-l", NULL);

        perror("execl");
        return 1;
    }

    wait(NULL);
    printf("Parent: Child process finished\n");

    return 0;
}
