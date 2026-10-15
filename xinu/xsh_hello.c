#include <xinu.h>

shellcmd xsh_hello(int nargs, char *args[])
{
    printf("Hello from XINU!\n");
    return OK;
}


