#ifndef ASCII_H
#define ASCII_H

#include <stdbool.h>

#define AA_BUF_SIZE 1024
#define AA_MAX_LINES 8

struct ascii_art {
  bool enabled;
  int n_lines;
  char lines[AA_MAX_LINES][AA_BUF_SIZE];
};

void generate_ascii_art(char *file_path, struct ascii_art *aa, int *max_len);

#endif
