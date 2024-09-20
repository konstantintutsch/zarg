#include "zarg.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This function counts how many arguments of a given Flag were passed.
 * @param arguments Arguments as strings
 * @param flag Flag
 *
 * @return The number of arguments matching the Flag structure
 */
int flag_count(char **arguments, Flag flag)
{
    int amount = 0;
    int length = ppclen(arguments);

    for (int i = 1; i < length; i++) {
        if (match_flag(arguments[i], flag))
            amount++;
    }

    return amount;
}

/**
 * This function reads and filters values from arguments.
 * @param arguments Arguments as strings (argv from main)
 * @param flag Flag
 *
 * @return The respective values of the passed Flag structure from the arguments. `free()` has to be called on the return
 */
char **flag_value(char **arguments, Flag flag)
{
    // Return nothing if the passed Flag is a toggle
    if (flag.value == false)
        return (char **)malloc(0);

    // TODO: Find an alternative to malloc() here so the function user does not need to call free()
    char **values =
        malloc(flag_count(arguments, flag) * sizeof(char *) + sizeof(NULL));

    int length = ppclen(arguments);
    int write = 0;

    for (int i = 0; i < length; i++) {
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
