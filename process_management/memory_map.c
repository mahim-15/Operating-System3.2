
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Process PID: %d\n", getpid());
    printf("Press Enter to exit...\n");
    getchar();

    return 0;
}
