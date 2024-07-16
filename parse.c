#include "zarg.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * flag_count - Count how many arguments of a given flag were passed
 * @arg1 - Arguments as an array of strings
 * @arg2 - Flag
 *
 * Return: The number of flags
 */

int flag_count(char **arguments,
               Flag   flag)
{
    int amount = 0;
    int length = ppclen(arguments);

    for (int i = 1; i < length; i++)
    {
        if (match_flag(arguments[i], flag))
            amount++;
    }

    return amount;
}

/**
 * flag_value - Read and filter values from command line arguments
 *              free() has to be called on the return value
 * @arg1 - Arguments with values as an array of strings, e. g. ["--directory ./src", "--notdirectory ./file.txt"]
 * @arg2 - Flag, e. g. (Flag){"directory", …}
 *
 * Return: Values, e. g. ["./src"]
 */

char **flag_value(char **arguments,
                  Flag   flag)
{
    if (flag.value == false)
        return (char **)malloc(0);

    // TODO: Find an alternative to malloc() here so the function user does not need to call free()
    char **values = malloc(flag_count(arguments, flag) * sizeof(char *) + sizeof(NULL));

    int length = ppclen(arguments);
    int write = 0;

    for (int i = 0; i < length; i++)
    {
        if (!valid_flag(arguments[i]))
            continue;

        if (!match_flag(arguments[i], flag))
            continue;

        // Value was not set
        if (i + 1 == length)
            continue;
        if (valid_flag(arguments[i + 1]))
            continue;

        values[write] = malloc(strlen(arguments[i + 1]) * sizeof(char));
        strcpy(values[write], arguments[i + 1]);

        write++;
    }

    values[write] = NULL;

    return values;
}
