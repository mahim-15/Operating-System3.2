
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *user = getenv("USER");
    char *home = getenv("HOME");

    printf("User: %s\n", user ? user : "Not set");
    printf("Home: %s\n", home ? home : "Not set");

    return 0;
}
