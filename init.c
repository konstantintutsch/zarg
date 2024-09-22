#include "zarg.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define FLAG_VALUE " [value]" /**< This macro defines the text which is used to indicate that Flag.value is true within the help dialogue. */

/**
 * This function generates and outputs a help dialogue line for a Flag to the command line.
 * @param flag Flag
 * @param furthest_offset Furthest required offset to seperate Flag.description from Flag.code to align with all descriptions of all other generated lines.
 */
void gen_flag_help(Flag flag, unsigned int furthest_offset)
{
    unsigned int description_offset = furthest_offset - strlen(flag.name);

    printf("--%s, -%c", flag.name, flag.code);

    if (flag.value == true) {
        printf(FLAG_VALUE);
        description_offset -= strlen(FLAG_VALUE);
    }
    // Print necessary offset
    for (int i = 0; i < description_offset; i++)
        putchar(' ');

    printf("%s\n", flag.description);
}

/**
 * This function initializes the use of zarg's integrated help dialogue.
 * @param argv Arguments as strings (argv from main)
 * @param flags All Flag structures to be displayed by the help dialogue. This is an array of Flag structures and has to end with the `_FLAG` macro.
 *
 * @return Whether the help dialogue was printed
 */
bool zinit(char **argv, Flag flags[])
{
    Flag help = { "help", 'h', false, "Show this dialogue" };

    if (!flag_passed(argv, help))
        return false;           // --help was not issued

    int length = arflen(flags);

    // Calculate length of longest argument with FLAG_VALUE
    unsigned int furthest_offset = strlen(help.name);
    for (int i = 0; i < length; i++) {
        unsigned int buffer = strlen(flags[i].name);
        if (flags[i].value == true)
            buffer += strlen(FLAG_VALUE);

        if (buffer > furthest_offset)
            furthest_offset = buffer;
    }
    furthest_offset++;          // Minimum offset = 1

    printf("%s [option]\n\nOptions\n", argv[0]);
    gen_flag_help(help, furthest_offset);
    for (int i = 0; i < length; i++) {
        gen_flag_help(flags[i], furthest_offset);
    }

    return true;                // --help was issued
}
