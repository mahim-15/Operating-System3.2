
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <semaphore.h>

#define ITERATIONS 100000

struct SharedData {
    int counter;
    sem_t lock;
};

int main() {
    struct SharedData *data = mmap(
        NULL, sizeof(struct SharedData),
        PROT_READ | PROT_WRITE,
        MAP_SHARED | MAP_ANONYMOUS, -1, 0
    );

    if (data == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    data->counter = 0;

    if (sem_init(&data->lock, 1, 1) == -1) {
        perror("sem_init");
        munmap(data, sizeof(*data));
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        for (int i = 0; i < ITERATIONS; i++) {
            sem_wait(&data->lock);
            data->counter++;
            sem_post(&data->lock);
        }
        _exit(0);
    } else if (pid > 0) {
        for (int i = 0; i < ITERATIONS; i++) {
            sem_wait(&data->lock);
            data->counter++;
            sem_post(&data->lock);
        }

        wait(NULL);
        printf("Final counter: %d\n", data->counter);
    } else {
        perror("fork");
        sem_destroy(&data->lock);
        munmap(data, sizeof(*data));
        return 1;
    }

    sem_destroy(&data->lock);
    munmap(data, sizeof(*data));
    return 0;
}
