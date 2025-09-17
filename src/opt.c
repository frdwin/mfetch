#include <stdio.h>
#include <stdlib.h>

void print_help(char *pname)
{
  printf("Usage: %s [-a ascii_art_file]\n\n", pname);
  printf("-a\tOptional. Print an ASCII art from a given file.\n");
  printf("\tIMPORTANT: the ASCII art must have a maximum of 8 lines. If the art is longer than 8 lines, it will be truncated.\n");
  exit(EXIT_FAILURE);
}
