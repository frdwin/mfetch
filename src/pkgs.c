#include <strings.h>
#include <string.h>
#include <stdio.h>

int fetch_pkgs(char *os_name, int *pkgs)
{
  // Void Linux.
  if (strcasecmp(os_name, "void") == 0)
  {
    // Open the pkgs database instead of run a new instance of the package manager.
    // and check for errors.
    FILE *f = fopen("/var/db/xbps/pkgdb-0.38.plist", "r");
    if (f == NULL)
      return -1;

    char buf[1024];
    long int counter = 0;

    while (fgets(buf, sizeof buf, f) != NULL)
    {
      const char *ptr = buf;
      while ((ptr = strstr(ptr, "<string>installed</string>")) != NULL)
      {
        counter++;
        ptr += strlen("<string>installed</string>");
      }
    }
    
    *pkgs = counter;
    fclose(f);
  }

  return 0;
}

