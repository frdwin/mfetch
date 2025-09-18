#ifndef PKGS_H
#define PKGS_H

/*
 * @brief Fetches the number of installed packages for a given operating system.
 *
 * @param os_name A pointer to a string containing the name of the operating system.
 * @param pkgs A pointer to an integer where the count of installed packages will be stored.
 * @return 0 on success. The function does not return an error code for failure to open the file.
 *
 */
int fetch_pkgs(char *os_name, int *pkgs);

#endif
