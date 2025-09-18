#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "ascii.h"

void generate_ascii_art(char *file_path, struct ascii_art *aa, int *max_len)
{
  FILE *f = fopen(file_path, "r");
  if (f == NULL)
  {
    perror("[!] Error opening ASCII art file");
    exit(EXIT_FAILURE);
  }

  int counter = 0;
  int line_max_len = 0;

  while((fgets(aa->lines[counter], AA_BUF_SIZE, f) != NULL) && (counter < AA_MAX_LINES))
  {
    int len = strlen(aa->lines[counter]);
    if (len > line_max_len)
    {
      line_max_len = len;
    }

    aa->n_lines++;
    counter++;
  }

 // Strip \n from every ASCII art line and add a \t instead.
  for (counter = 0; counter < AA_MAX_LINES; counter++)
  {
    int len = strlen(aa->lines[counter]);
    if (len < line_max_len)
    {
      char *p = aa->lines[counter] + len - 1;
      memset(p, ' ', line_max_len - len + 1);
      len += line_max_len - len;
    }

    char *p = aa->lines[counter] + len - 1;
    p[0] = '\0';
  }

  *max_len += line_max_len;
  
  aa->enabled = true;
  fclose(f);
}
