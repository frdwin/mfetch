#include <stdio.h>
#include <stdlib.h>

void print_help(char *pname)
{
  printf("Usage: %s [-a ascii_art_file]\n\n", pname);
  printf("-a\tOptional. Print an ascii art from a given file.\n");
  printf("\tIMPORTANT: the ascii art must have a maximum of 8 lines.\n");
  exit(EXIT_FAILURE);
}
