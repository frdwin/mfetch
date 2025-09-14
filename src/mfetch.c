//os, uptime, pkg
// formatar o output
// possibilitar uma ascii art customizada, com X linhas em um arquivo
#include <stdio.h>
#include <sys/utsname.h>

#include "config.h"
#include "user.h"
#include "shell.h"
#include "kernel.h"
#include "os.h"

// /proc/uptime
// xbps-query (tem alguma base em arquivo?)

int main(void)
{
  int n;

  // Fetch and print username.
  int ulen = 30;
  char username[ulen];
  if ((n = fetch_user(username, ulen)) == 0)
    printf("%s %s\n", USER_LABEL, username);
  else
    printf("%s %s\n", USER_LABEL, "error");

  // Fetch and print shell name.
  int slen = 10;
  char shell_name[slen];
  if ((n = fetch_shell(shell_name, slen)) == 0)
    printf("%s %s\n", SHELL_LABEL, shell_name);
  else
    printf("%s %s\n", SHELL_LABEL, "error");

  // Fetch and print OS name.
  int olen = 30;
  char os_name[olen];
  if ((n = fetch_os(os_name, olen)) == 0)
    printf("%s %s\n", OS_LABEL, os_name);
  else
    printf("%s %s\n", OS_LABEL, "error");

  // Fetch and print kernel release number.
  char kern_release[_UTSNAME_RELEASE_LENGTH];
  if ((n = fetch_kernel(kern_release)) == 0)
    printf("%s %s\n", KERNEL_LABEL, kern_release);
  else
    printf("%s %s\n", KERNEL_LABEL, "error");

  return 0;
}
