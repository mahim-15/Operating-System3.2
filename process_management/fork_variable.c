
#include <stdio.h>
#include <unistd.h>

int main() {
    int x = 10;

    pid_t pid = fork();

    if (pid == 0) {
        x = 20;
        printf("Child: x = %d\n", x);
    }
    else if (pid > 0) {
        x = 30;
        printf("Parent: x = %d\n", x);
    }

    return 0;
}

