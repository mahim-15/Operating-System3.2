
#include <stdio.h>
#include <stdlib.h>

int global_init = 10;
int global_uninit;

int main() {
    int local = 20;
    int *dynamic = malloc(sizeof(int));

    if (dynamic == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    *dynamic = 30;

    printf("Initialized global: %p\n", (void *)&global_init);
    printf("Uninitialized global: %p\n", (void *)&global_uninit);
    printf("Local variable: %p\n", (void *)&local);
    printf("Dynamic memory: %p\n", (void *)dynamic);

    free(dynamic);
    return 0;
}
