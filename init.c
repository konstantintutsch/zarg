#include "zarg.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const char value_text[] = " [value]";

/**
 * gen_flag_help - Generate a help dialogue line for a flag
 * @arg1 - Flag
 * @arg2 - Furthest required offset of all flags that will be or have been passed
 */

void gen_flag_help(Flag flag, int furthest_offset)
{
    int description_offset = furthest_offset - strlen(flag.name);

    printf("--%s, -%c", flag.name, flag.code);

    if (flag.value == true) {
        printf(value_text);
        description_offset -= strlen(value_text);
    }
    // Print necessary offset
    for (int i = 0; i < description_offset; i++)
        putchar(' ');

    printf("%s\n", flag.description);
}

/**
 * zinit - Check wether to display the help dialogue and generate it if necessary
 * @arg1 - Arguments (always argv from main)
 * @arg2 - Flags
 * @arg3 - Number of flags
 *
 * Return: false No help dialogue was printed
 *         true  The help dialogue was printed, exit the program
 */

bool zinit(char **argv, Flag flags[])
{
    Flag help = { "help", 'h', false, "Show this dialogue" };

    if (flag_count(argv, help) == 0)
        return false;           // --help was not issued

    int length = arflen(flags);

    // Calculate length of longest argument with value_text
    int furthest_offset = strlen(help.name);
    for (int i = 0; i < length; i++) {
        int buffer = strlen(flags[i].name);
        if (flags[i].value == true)
            buffer += strlen(value_text);

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
