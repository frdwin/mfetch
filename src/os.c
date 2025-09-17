#include <stdio.h>
#include <string.h>

#define S_BUF_LEN 255

int fetch_os(char *os_name, int len)
{
  // Open /etc/os-release and check for error.
  FILE *f = fopen("/etc/os-release", "r");
  if (f == NULL)
    return -1;
  
  char s[S_BUF_LEN];
  char *p;

  // Detect the ID line inside /etc/os-release.
  while ((p = fgets(s, S_BUF_LEN, f)) != NULL)
    if (strncmp(s, "ID", 2) == 0)
      break;

  // Return -1 if it doesn't detect the ID line.
  if (p == NULL)
  {
    fclose(f);
    return -1;
  }

  // Locate first and last quotes and check for errors.
  const char *f_quote = strchr(s, '"');
  const char *l_quote = strrchr(s, '"');
  if (f_quote == NULL || l_quote == NULL || f_quote > l_quote)
  {
    fclose(f);
    return -1;
  }

  // Calculate the lenght of the OS name, without the quotes.
  int slen = l_quote - f_quote - 1;

  // Check if the buffer has space for the OS name.
  if (slen >= len)
    slen = len - 1;

  // Copy the OS name to the given buffer and NUL terminate it.
  strncpy(os_name, f_quote + 1, slen);
  os_name[slen] = '\0';

  // Check to see if the copy went ok.
  if (os_name == NULL)
    return -1;

  // Close the file descriptor for /etc/os-release.
  fclose(f);
  return 0;
}
