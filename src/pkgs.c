#include <strings.h>
#include <string.h>
#include <stdio.h>

int fetch_pkgs(char *os_name, int *pkgs)
{
  if (strcasecmp(os_name, "void") == 0)
  {
    FILE *f = fopen("/var/db/xbps/pkgdb-0.38.plist", "r");
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

