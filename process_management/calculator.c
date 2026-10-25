
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int a = 20, b = 5;
    char operations[] = {'+', '-', '*', '/'};

    for (int i = 0; i < 4; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            return 1;
        }

        if (pid == 0) {
            switch (operations[i]) {
                case '+':
                    printf("Child PID %d: %d + %d = %d\n",
                           getpid(), a, b, a + b);
                    break;

                case '-':
                    printf("Child PID %d: %d - %d = %d\n",
                           getpid(), a, b, a - b);
                    break;

                case '*':
                    printf("Child PID %d: %d * %d = %d\n",
                           getpid(), a, b, a * b);
                    break;

                case '/':
                    if (b != 0) {
                        printf("Child PID %d: %d / %d = %d\n",
                               getpid(), a, b, a / b);
                    }
                    break;
            }

            exit(0);
        } else {
            wait(NULL);
        }
    }

    printf("Parent: All calculations completed.\n");
    return 0;
}
