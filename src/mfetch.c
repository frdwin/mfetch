//uptime, pkg
// possibilitar uma ascii art customizada, com X linhas em um arquivo
#include <stdio.h>
#include <sys/utsname.h>
#include <string.h>

#include "config.h"
#include "user.h"
#include "shell.h"
#include "kernel.h"
#include "os.h"
#include "uptime.h"

// Macro to calculate the size of the label and return the biggest label.
#define LABEL_LENGTH(l) (int)(strlen(l))
#define MAX_LABEL(l1, l2) ((LABEL_LENGTH(l1) > LABEL_LENGTH(l2)) ? l1 : l2)

// xbps-query (tem alguma base em arquivo?)

int main(void)
{
  int n;

  // Calculate the maximum label length the user setted in config.h.
  const char *max_label = MAX_LABEL(USER_LABEL, SHELL_LABEL);
  max_label = MAX_LABEL(max_label, OS_LABEL);
  max_label = MAX_LABEL(max_label, KERNEL_LABEL);
  int max_len = LABEL_LENGTH(max_label);

  // Print an empty line
  printf("\n");
  
  // Fetch and print username.
  int ulen = 30;
  char username[ulen];
  printf("%*s ", max_len, USER_LABEL);
  if ((n = fetch_user(username, ulen)) == 0)
    printf(" %s\n", username);
  else
    printf(" %s\n", "error");

  // Fetch and print shell name.
  int slen = 10;
  char shell_name[slen];
  printf("%*s ", max_len, SHELL_LABEL);
  if ((n = fetch_shell(shell_name, slen)) == 0)
    printf(" %s\n", shell_name);
  else
    printf(" %s\n", "error");

  // Fetch and print OS name.
  int olen = 30;
  char os_name[olen];
  printf("%*s ", max_len, OS_LABEL);
  if ((n = fetch_os(os_name, olen)) == 0)
    printf(" %s\n", os_name);
  else
    printf(" %s\n", "error");

  // Fetch and print kernel release number.
  char kern_release[_UTSNAME_RELEASE_LENGTH];
  printf("%*s ", max_len, KERNEL_LABEL);
  if ((n = fetch_kernel(kern_release)) == 0)
    printf(" %s\n", kern_release);
  else
    printf(" %s\n", "error");

  // Fetch and print uptime.
  char uptime[8];
  printf("%*s ", max_len, UPTIME_LABEL);
  if ((n = fetch_uptime(uptime)) == 0)
    printf(" %s\n", uptime);
  else
    printf(" %s\n", "error");

  return 0;
}
