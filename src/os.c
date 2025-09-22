#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

  // Locate equal sign and check for errors.
  const char *e_sign = strchr(s, '=');
  if (e_sign == NULL)
  {
    fclose(f);
    return -1;
  }

  // Calculate the lenght of the OS name, without the "ID=" part.
  // e_sign + 1 should be distro_name\n
  // Thats why we subtract 1 from it.
  int slen = strlen(e_sign + 1) - 1;

  // Check if double quotes are present.
  const char *first_quote = strchr(e_sign, '"');
  const char *last_quote = strrchr(e_sign, '"');
  if (first_quote != NULL && last_quote != NULL)
    slen = last_quote - first_quote - 1;

  // Check if the buffer has space for the OS name.
  if (slen >= len)
    slen = len - 1;

  // Copy the OS name to the given buffer and NUL terminate it.
  if (first_quote != NULL && last_quote != NULL)
  {
    strncpy(os_name, first_quote + 1, slen);
    os_name[slen] = '\0';
  }
  else
  {
    strncpy(os_name, e_sign + 1, slen);
    os_name[slen] = '\0';
  }

  // Check to see if the copy went ok.
  if (os_name == NULL)
    return -1;

  // Close the file descriptor for /etc/os-release.
  fclose(f);
  return 0;
}
