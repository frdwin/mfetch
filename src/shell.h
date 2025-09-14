#ifndef SHELL_H
#define SHELL_H

/*
 * @brief Fetches the shell name from the environment variable.
 *
 * This function retrieves the shell path from the environment variable "SHELL"
 * and extracts the shell name (the last component of the path) into the provided buffer.
 *
 * @param shell_name A pointer to a buffer where the shell name will be stored.
 * @param len The length of the buffer to prevent overflow.
 * @return 0 on success, or -1 if the environment variable is not set or if an error occurs.
 *
 * @note The caller must ensure that the buffer is large enough to hold the shell name.
 * If the shell name is longer than `len`, it will be truncated.
 */
int fetch_shell(char *shell_name, int len);

#endif
