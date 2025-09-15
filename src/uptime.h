#ifndef UPTIME_H
#define UPTIME_H

/**
 * @brief Fetches the system uptime and formats it as hours, minutes, and seconds.
 *
 * This function reads the uptime from the /proc/uptime file, which contains
 * the total uptime of the system in seconds. It converts this value into
 * hours, minutes, and seconds, and stores the formatted string in the provided buffer.
 *
 * @param uptime A pointer to a buffer where the formatted uptime will be stored.
 * @return 0 on success, or -1 if an error occurs (e.g., file not found, read error, or formatting error).
 *
 * @note The caller must ensure that the buffer is large enough to hold the formatted uptime string.
 * The expected format is "Xh Ym Zs", where X, Y, and Z are integers representing hours, minutes, and seconds.
 */
int fetch_uptime(char *uptime);

#endif
