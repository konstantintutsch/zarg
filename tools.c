#include "zarg.h"

#include <stddef.h>

/**
 * This function counts how many elements exist in an array of strings.
 * @param array Array of strings with last element equal to NULL
 *
 * @return The number of elements
 */
int ppclen(char **array)
{
    int count = 0;

    while (array[count] != NULL)
        count++;

    return (count);
}

/**
 * This function counts how many elements exist in an array of Flag structures
 * @param array Array of Flag structures with last element equal to `_FLAG` macro
 *
 * @return The number of elements
 */
int arflen(Flag array[])
{
    int count = 0;

    while (!compare_flag(array[count], _FLAG))
        count++;

    return (count);
}
