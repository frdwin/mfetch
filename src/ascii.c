#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "ascii.h"

void generate_ascii_art(char *file_path, struct ascii_art *aa, int *max_len)
{
  // Open file and check for errors.
  FILE *f = fopen(file_path, "r");
  if (f == NULL)
  {
    perror("[!] Error opening ASCII art file");
    exit(EXIT_FAILURE);
  }

  int counter = 0;
  int line_max_len = 0;

  // Read every line and register the maximum line length and the number of lines.
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

 // Add spaces to ensure the formatting.
 // Strip \n from every ASCII art line and add a \0 instead.
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

  // Update the maximum line length with the local variable value.
  *max_len += line_max_len;
  
  // Enable the flag.
  aa->enabled = true;
  fclose(f);
}
