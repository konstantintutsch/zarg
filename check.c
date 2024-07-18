#include "zarg.h"

#include <string.h>

/**
 * valid_flag - Validate a string as a flag
 * @arg1 - Argument as a string
 *
 * Return: false Invalid
 *         true  Valid
 */

bool valid_flag(char *argument)
{
    if (argument[0] != '-')
        return false;

    if (argument[1] != '-' && strlen(argument) > 2)
        return false;

    return true;
}

/**
 * match_flag - Compare a string and a flag
 * @arg1 - Argument as a string
 * @arg2 - Flag
 *
 * Return: false argument != flag
 *         true  argument == flag
 */

bool match_flag(char *argument, Flag flag)
{
    if (!valid_flag(argument))
        return false;

    if ((strcmp(argument + 2, flag.name) == 0) || (argument[1] == flag.code))
        return true;

    return false;
}

/**
 * compare_flag - Compare two Flag structs
 * @arg1 - First flag to compare with
 * @arg2 - Second flag to compare with
 *
 * Return: false Flags do not match
 *         true  Flags match
 */

bool compare_flag(Flag first, Flag second)
{
    if (strcmp(first.name, second.name))
        return false;

    if (first.code != second.code)
        return false;

    if (first.value != second.value)
        return false;

    if (strcmp(first.description, second.description))
        return false;

    return true;
}
