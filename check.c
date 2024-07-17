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
