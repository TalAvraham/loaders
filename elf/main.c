#include <stdio.h>
#include <stdlib.h>

#include "elf.h"

int main(int argc, char *argv[], char *envp[])
{
   FILE *f = fopen(argv[1], "rb");

   fseek(f, 0, SEEK_END);
   int size = ftell(f);

   fseek(f, 0L, SEEK_SET);
   
   char *buf = malloc(size);
   fread(buf, size, 1, f);

   // Run the ELF
   elf_run(buf, &argv[1], envp);

   return 0;
}

