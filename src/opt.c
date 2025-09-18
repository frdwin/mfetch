#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_help(char *pname)
{
  printf("Usage: %s [-a ascii_art_file]\n\n", pname);
  printf("-a\tOptional. Print an ASCII art from a given file.\n");
  printf("\tIMPORTANT: the ASCII art must have a maximum of 8 lines. If the art is longer than 8 lines, it will be truncated.\n");
  exit(EXIT_FAILURE);
}

int validate_opts(int n_opts, char **opts)
{
  switch (n_opts) {
  case 1:
    break;
  case 2:
    if (strcmp(opts[1], "-h") == 0 || strcmp(opts[1], "--help") == 0)
      print_help(opts[0]);
    break; // Just to bypass warnings.
  case 3:
    if (strcmp(opts[1], "-a") == 0)
      return 128;
    break; // Just to bypass warnings.
  default:
    print_help(opts[0]);
    break; // Just to bypass warnings.
  }

  return 0;
}
