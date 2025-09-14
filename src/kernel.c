#include <sys/utsname.h>
#include <string.h>

int fetch_kernel(char *kern_version)
{
  struct utsname sysinfo;
  int n;

  // Check if uname call was successful.
  if ((n = uname(&sysinfo)) != 0)
    return -1;

  // Copy the kernel release version to the given buffer.
  memcpy(kern_version, sysinfo.release, _UTSNAME_RELEASE_LENGTH);

  return 0;
}
