#include "zarg.h"

#include <string.h>

/**
 * This function checks whether an argument is a flag or a value.
 * @param argument Argument as a string
 *
 * @return The validity of the passed argument as a flag
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
 * This function compares an argument and a Flag.
 * @param argument Argument as a string
 * @param flag Flag
 *
 * @return Whether the argument and the Flag match
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
 * This function compares two Flag structures.
 * @param first  First Flag to compare
 * @param second Second Flag to compare
 *
 * @return Whether the Flag structures are equal
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
