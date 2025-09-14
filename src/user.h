#ifndef USER_H
#define USER_H

/*
 * @brief Fetches the username from the environment variable.
 *
 * This function retrieves the username from the environment variable "USER"
 * and copies it into the provided buffer. The function ensures that the
 * buffer does not overflow by limiting the number of characters copied.
 *
 * @param username A pointer to a buffer where the username will be stored.
 * @param len The length of the buffer to prevent overflow.
 * @return 0 on success, or -1 if the environment variable is not set or if the buffer is NULL.
 *
 * @note The caller must ensure that the buffer is large enough to hold the username.
 * If the username is longer than `len`, it will be truncated.
 */
int fetch_user(char *username, int len);

#endif
