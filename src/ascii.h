#ifndef ASCII_H
#define ASCII_H

#include <stdbool.h>

// Define the maximum buffer size for each line.
#define AA_BUF_SIZE 1024

// Define the maximum number of lines for ASCII art.
#define AA_MAX_LINES 8

struct ascii_art {
  bool enabled; // Flag to indicate if ASCII art is enabled.
  int n_lines; // Number of lines read.
  char lines[AA_MAX_LINES][AA_BUF_SIZE]; // Array to store ASCII art lines.
};

/*
 * @brief Generates ASCII art from a specified file.
 *
 * This function reads ASCII art from a file specified by `file_path` and stores
 * the lines in the provided `ascii_art` structure. It also calculates the maximum
 * line length and updates the provided `max_len` pointer.
 *
 * @param file_path A pointer to a string containing the path to the ASCII art file.
 * @param aa A pointer to an `ascii_art` structure where the lines will be stored.
 * @param max_len A pointer to an integer that will be updated with the maximum line length.
 *
 * @note If the file cannot be opened, the function prints an error message and exits
 *       the program with a failure status. The function reads up to `AA_MAX_LINES`
 *       lines from the file and ensures that each line is properly formatted.
 */
void generate_ascii_art(char *file_path, struct ascii_art *aa, int *max_len);

#endif
