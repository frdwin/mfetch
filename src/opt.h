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

/*
 * @brief Validates command-line options.
 *
 * This function checks the number of command-line options provided and validates
 * them based on predefined criteria. It handles specific options for help and
 * an ASCII art option.
 *
 * @param n_opts The number of command-line options passed to the program.
 * @param opts An array of strings containing the command-line options.
 * @return 0 if the options are valid, 128 if the ASCII art option is selected,
 *         or calls the help function if invalid options are provided.
 *
 * @note If the number of options is 2 and the option is "-h" or "--help",
 *       the help message is printed. If the number of options is 3 and the
 *       first option is "-a", the function returns 128. For any other case,
 *       the help message is printed.
 */
int validate_opts(int n_opts, char **opts);

#endif
