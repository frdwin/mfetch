#ifndef KERNEL_H
#define KERNEL_H

/*
 * @brief Fetches the kernel version of the operating system (only Linux).
 *
 * This function uses the `uname` system call to fill a `utsname` structure
 * with information about the system. The kernel version is copied into the
 * provided buffer.
 *
 * @param kern_version A pointer to a buffer where the kernel version will be stored.
 * @return 0 on success, or -1 if an error occurs while retrieving the kernel version.
 *
 * @note The caller must ensure that the buffer is large enough to hold the
 * kernel version. The size of the buffer should be at least `_UTSNAME_RELEASE_LENGTH`.
 */
int fetch_kernel(char *kern_version);

#endif
