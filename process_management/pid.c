#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid = getpid();
    printf("Process ID: %d\n", pid);

    pid_t ppid = getppid();
    printf("Parent Process ID: %d\n", ppid);

    return 0;
}
