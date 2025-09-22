#include <stdlib.h>
#include <string.h>

int fetch_user(char *username, int len)
{
  // Get the username from the environment variable and check for errors.
  const char *u = getenv("USER");
  if (u == NULL || (strcmp(u, "") == 0))
    return -1;

  // Copy the username to the given buffer.
  strncpy(username, u, len);
  return 0;
}
