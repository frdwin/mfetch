// TODO: pkgs; customized ascii art
#include <stdio.h>
#include <sys/utsname.h>
#include <string.h>
#include "config.h"
#include "user.h"
#include "shell.h"
#include "kernel.h"
#include "os.h"
#include "uptime.h"
#include "color.h"
#include "pkgs.h"
#include "opt.h"

// Macro to calculate the size of the label and return the biggest label.
#define LABEL_LENGTH(l) (int)(strlen(l))
#define MAX_LABEL(l1, l2) ((LABEL_LENGTH(l1) > LABEL_LENGTH(l2)) ? l1 : l2)

int main(int argc, char **argv)
{
  if (argc > 3)
    print_help(argv[0]);

  int n;

  // Calculate the maximum label length the user setted in config.h.
  // The max_len will be used to format the labels when printing them.
  const char *max_label = MAX_LABEL(USER_LABEL, SHELL_LABEL);
  max_label = MAX_LABEL(max_label, OS_LABEL);
  max_label = MAX_LABEL(max_label, KERNEL_LABEL);
  int max_len = LABEL_LENGTH(max_label);

  // Print an empty line
  printf("\n");
  
  // Fetch and print username.
  int ulen = 30;
  char username[ulen];
  printf("%s%*s ", LABEL_COLOR, max_len, USER_LABEL);
  if ((n = fetch_user(username, ulen)) == 0)
    printf(" %s%s\n", RESET, username);
  else
    printf(" %s%s\n", RESET, "error");

  // Fetch and print shell name.
  int slen = 10;
  char shell_name[slen];
  printf("%s%*s ", LABEL_COLOR, max_len, SHELL_LABEL);
  if ((n = fetch_shell(shell_name, slen)) == 0)
    printf(" %s%s\n", RESET, shell_name);
  else
    printf(" %s%s\n", RESET, "error");

  // Fetch and print OS name.
  int olen = 30;
  char os_name[olen];
  printf("%s%*s ", LABEL_COLOR, max_len, OS_LABEL);
  if ((n = fetch_os(os_name, olen)) == 0)
    printf(" %s%s\n", RESET, os_name);
  else
    printf(" %s%s\n", RESET, "error");

  // Fetch and print kernel release number.
  char kern_release[_UTSNAME_RELEASE_LENGTH];
  printf("%s%*s ", LABEL_COLOR, max_len, KERNEL_LABEL);
  if ((n = fetch_kernel(kern_release)) == 0)
    printf(" %s%s\n", RESET, kern_release);
  else
    printf(" %s%s\n", RESET, "error");

  // Fetch and print uptime.
  char uptime[8];
  printf("%s%*s ", LABEL_COLOR, max_len, UPTIME_LABEL);
  if ((n = fetch_uptime(uptime)) == 0)
    printf(" %s%s\n", RESET, uptime);
  else
    printf(" %s%s\n", RESET, "error");

  // Fetch and print pkgs.
  int pkgs;
  printf("%s%*s ", LABEL_COLOR, max_len, PKGS_LABEL);
  if ((n = fetch_pkgs(os_name, &pkgs)) == 0)
    printf(" %s%d\n", RESET, pkgs);
  else
    printf(" %s%s\n", RESET, "error");

  // Print colors
  #ifdef COLOR
  printf(
    " %s* %s* %s* %s* %s* %s* %s* %s* \n",
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
  );
  #endif

  return 0;
}
