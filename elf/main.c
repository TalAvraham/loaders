#include <stdio.h>
#include <stdlib.h>

#include "elf.h"

enum args_e {
    ARGS_PROGRAM_NAME = 0,
    ARGS_ELF_TO_LOAD,
    ARGS_EXPECTED_MIN_COUNT
};

int main(int argc, char *argv[], char *envp[])
{
    int exit_code = EXIT_FAILURE;

    if (ARGS_EXPECTED_MIN_COUNT > argc) {
        printf("Usage: %s <elf-to-load> [ARGS ...]\n", argv[ARGS_PROGRAM_NAME]);
        goto l_exit;
    }

    // Run the ELF
    elf_run(argv[ARGS_ELF_TO_LOAD], &argv[ARGS_ELF_TO_LOAD], envp);

    exit_code = EXIT_SUCCESS;

l_exit:
    return 0;
}

