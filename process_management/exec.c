
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before exec\n");
    fflush(stdout);

    execl("/bin/ls", "ls", "-l", NULL);

    printf("This line runs only if exec fails\n");

    return 0;
}
