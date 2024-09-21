#include "zarg.h"

#include <stdbool.h>
#include <stddef.h>

/**
 * This function counts how many elements exist in an array of strings.
 * @param array Array of strings with last element equal to NULL
 *
 * @return The number of elements
 */
unsigned int ppclen(char **array)
{
    unsigned int count = 0;

    while (array[count] != NULL)
        count++;

    return count;
}

/**
 * This function counts how many elements exist in an array of Flag structures
 * @param array Array of Flag structures with last element equal to `_FLAG` macro
 *
 * @return The number of elements
 */
unsigned int arflen(Flag array[])
{
    unsigned int count = 0;

    while (!compare_flag(array[count], _FLAG))
        count++;

    return count;
}

/**
 * This function checks whether a Flag was passed as an argument.
 * @param arguments Arguments as strings (argv from main)
 * @param flag Flag
 *
 * @return Whether the Flag was found among the arguments
 */
bool flag_passed(char **arguments, Flag flag)
{
    if (flag_count(arguments, flag) > 0)
        return (true);

    return (false);
}
