#include <strings.h>
#include <stdio.h>

int count_pkgs(const char *cmd, int *pkgs)
{
  FILE *fp = popen(cmd, "r");
  if (fp == NULL)
    return -1;

  if (fscanf(fp, "%d", pkgs) != 1)
  {
    pclose(fp);
    return -1;
  }

  int status = pclose(fp);
  if (status == -1)
    return -1;
  
  return 0;
}

int fetch_pkgs(char *os_name, int *pkgs)
{
  if (strcasecmp(os_name, "void") == 0)
    count_pkgs("xbps-query -l | wc -l", pkgs);

  return 0;
}

