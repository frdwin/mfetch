/*
 * mfetch is a minimal yet bazingly fast information
 * fetcher for GNU/Linux.
 *
 * https://github.com/frdwin/mfetch
 */
#include <stdio.h>
#include <sys/utsname.h>
#include <string.h>
#include <stdbool.h>
#include "config.h"
#include "user.h"
#include "shell.h"
#include "kernel.h"
#include "os.h"
#include "uptime.h"
#include "color.h"
#include "pkgs.h"
#include "opt.h"
#include "ascii.h"

// Macro to calculate the size of the label and return the biggest label.
#define LABEL_LENGTH(l) (int)(strlen(l))
#define MAX_LABEL(l1, l2) ((LABEL_LENGTH(l1) > LABEL_LENGTH(l2)) ? l1 : l2)

int main(int argc, char **argv)
{
  // Calculate the maximum label length the user setted in config.h.
  // The max_len will be used to format the labels when printing them.
  const char *max_label = MAX_LABEL(USER_LABEL, SHELL_LABEL);
  max_label = MAX_LABEL(max_label, OS_LABEL);
  max_label = MAX_LABEL(max_label, KERNEL_LABEL);
  int max_len = LABEL_LENGTH(max_label);
  int max_len_ascii = max_len;

  // Initialize ascii art struct.
  struct ascii_art aa = {
    .enabled = false,
    .n_lines = 0,
  };

  // Check for wrong cli arguments.
  int status = validate_opts(argc, argv);
  if (status == 128)
    generate_ascii_art(argv[2], &aa, &max_len_ascii);

  // Print an empty line
  printf("\n");
  
  // Fetch and print username.
  int ulen = 30;
  char username[ulen];
  if (aa.enabled && aa.n_lines > 1)
  {
    printf("%s\n", aa.lines[0]);
    printf("%s\t%s%*s ", aa.lines[1], LABEL_COLOR, max_len, USER_LABEL);
  }
  else
  {
    printf("%s%*s ", LABEL_COLOR, max_len_ascii, USER_LABEL);
  }

  if ((status = fetch_user(username, ulen)) == 0)
    printf(" %s%s\n", RESET, username);
  else
    printf(" %s%s\n", RESET, "error");

  // Fetch and print shell name.
  int slen = 10;
  char shell_name[slen];
  if (aa.enabled && aa.n_lines > 2)
    printf("%s\t%s%*s ", aa.lines[2], LABEL_COLOR, max_len, SHELL_LABEL);
  else
    printf("%s%*s ", LABEL_COLOR, max_len_ascii, SHELL_LABEL);

  if ((status = fetch_shell(shell_name, slen)) == 0)
    printf(" %s%s\n", RESET, shell_name);
  else
    printf(" %s%s\n", RESET, "error");

  // Fetch and print OS name.
  int olen = 30;
  char os_name[olen];
  if (aa.enabled && aa.n_lines > 3)
    printf("%s\t%s%*s ", aa.lines[3], LABEL_COLOR, max_len, OS_LABEL);
  else
    printf("%s%*s ", LABEL_COLOR, max_len_ascii, OS_LABEL);

  if ((status = fetch_os(os_name, olen)) == 0)
    printf(" %s%s\n", RESET, os_name);
  else
    printf(" %s%s\n", RESET, "error");

  // Fetch and print kernel release number.
  char kern_release[_UTSNAME_RELEASE_LENGTH];
  if (aa.enabled && aa.n_lines > 4)
    printf("%s\t%s%*s ", aa.lines[4], LABEL_COLOR, max_len, KERNEL_LABEL);
  else
    printf("%s%*s ", LABEL_COLOR, max_len_ascii, KERNEL_LABEL);

  if ((status = fetch_kernel(kern_release)) == 0)
    printf(" %s%s\n", RESET, kern_release);
  else
    printf(" %s%s\n", RESET, "error");

  // Fetch and print uptime.
  char uptime[8];
  if (aa.enabled && aa.n_lines > 5)
    printf("%s\t%s%*s ", aa.lines[5], LABEL_COLOR, max_len, UPTIME_LABEL);
  else
    printf("%s%*s ", LABEL_COLOR, max_len_ascii, UPTIME_LABEL);

  if ((status = fetch_uptime(uptime)) == 0)
    printf(" %s%s\n", RESET, uptime);
  else
    printf(" %s%s\n", RESET, "error");

  // Fetch and print pkgs.
  unsigned int pkgs;
  if (aa.enabled && aa.n_lines > 6)
    printf("%s\t%s%*s ", aa.lines[6], LABEL_COLOR, max_len, PKGS_LABEL);
  else
    printf("%s%*s ", LABEL_COLOR, max_len_ascii, PKGS_LABEL);

  if ((status = fetch_pkgs(os_name, &pkgs)) == 0)
  {
    printf(" %s%d\n", RESET, pkgs);

    if (aa.enabled && aa.n_lines > 7)
      printf("%s\n", aa.lines[7]);
  }
  else
  {
    printf(" %s%s\n", RESET, "error");

    if (aa.enabled && aa.n_lines > 7)
      printf("%s\n", aa.lines[7]);
  }

  // Print colors
  #ifdef COLOR
  if (aa.enabled)
    printf(
      " %*s\t* %s* %s* %s* %s* %s* %s* %s* \n",
      max_len_ascii,
      BLACK,
      RED,
      GREEN,
      YELLOW,
      BLUE,
      MAGENTA,
      CYAN,
      WHITE
    );
  else
    printf(
      " %s* %s* %s* %s* %s* %s* %s* %s* \n",
      BLACK,
      RED,
      GREEN,
      YELLOW,
      BLUE,
      MAGENTA,
      CYAN,
      WHITE
    );
  #endif

  return 0;
}
