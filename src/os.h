#ifndef OS_H
#define OS_H

/*
 * @brief Fetches the operating system name from the /etc/os-release file.
 *
 * This function reads the /etc/os-release file to find the line that starts
 * with "ID" and extracts the operating system name enclosed in quotes.
 *
 * @param os_name A pointer to a buffer where the operating system name will be stored.
 * @param len The length of the buffer to prevent overflow.
 * @return 0 on success, or -1 if an error occurs (e.g., file not found, line not found, or invalid format).
 *
 * @note The caller must ensure that the buffer is large enough to hold the operating system name.
 * If the name is longer than `len`, it will be truncated.
 */
int fetch_os(char *os_name, int len);

#endif
