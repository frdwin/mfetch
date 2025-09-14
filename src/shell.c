#include <stdlib.h>
#include <string.h>

int fetch_shell(char *shell_name, int len)
{
  // Get the shell path from the environment variable and check for errors.
  char *shell_path = getenv("SHELL");
  if (shell_path == NULL)
    return -1;

  char *token;
  char *delim = "/";

  // Split the path in chunks between "/" and get the last chunk.
  token = strtok(shell_path, delim);
  while ((token = strtok(NULL, delim)) != NULL)
    // Copy the shell name to the given buffer.
    strncpy(shell_name, token, len);

  return 0;
}
