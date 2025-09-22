#include <strings.h>
#include <string.h>
#include <stdio.h>

unsigned int read_pkgs_file(const char *f_path, char *search_expr)
{
  // Open the pkgs database instead of run a new instance of the package manager.
  // and check for errors.
  FILE *f = fopen(f_path, "r");
  if (f == NULL)
    return -1;
  
  char buf[1024];
  unsigned int counter = 0;

  while (fgets(buf, sizeof buf, f) != NULL)
  {
    const char *ptr = buf;
    while ((ptr = strstr(ptr, search_expr)) != NULL)
    {
      counter++;
      ptr += strlen(search_expr);
    }
  }
  
  fclose(f);
  return counter;
}

int fetch_pkgs(char *os_name, int *pkgs)
{
  // Void.
  if (strcasecmp(os_name, "void") == 0)
    *pkgs = read_pkgs_file("/var/db/xbps/pkgdb-0.38.plist", "<string>installed</string>");
  
  // Debian.
  if (strcmp(os_name, "debian") == 0)
    *pkgs = read_pkgs_file("/var/lib/dpkg/status", "Package:");

  return 0;
}

