#include "zarg.h"

#include <string.h>

/**
 * valid_flag - Check if string is a command line flag
 *
 * @arg1: Argument
 *
 * @return: Yes/No
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
 * match_flag - Check if string is argument flag
 *
 * @arg1: Argument
 * @arg2: Flag
 *
 * @return: Yes/No
 */

bool match_flag(char *argument,
                Flag flag)
{
    if (!valid_flag(argument))
        return false;

    if ((strcmp(argument + 2, flag.name) == 0) || (argument[1] == flag.code))
        return true;

    return false;
}


