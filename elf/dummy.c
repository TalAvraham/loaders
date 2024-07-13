#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

__attribute__((noreturn))
void main(int argc, char *argv[], char *envp[])
{
    printf("Hello from dummy! Got %d args:\n", argc);
    for (int i = 0; i < argc; i++)
    {
        puts(argv[i]);
    }
    _exit(EXIT_SUCCESS);
}
