#ifndef OPT_H
#define OPT_H

/*
 * @brief Prints the help message for the program.
 *
 * This function displays the usage instructions for the command-line program,
 * including the available options and their descriptions. It is intended to
 * guide users on how to properly use the program.
 *
 * @param pname A pointer to a string containing the name of the program.
 * This is used in the usage message to indicate how to call the program.
 *
 * @note The function exits the program with a failure status after printing
 * the help message.
 */
void print_help(char *pname);

#endif
