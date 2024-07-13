#include "zarg.h"

#include <stddef.h>

/**
 * ppclen - Counts how many elements exist in an array of pointers to pointers to characters
 *
 * @arg1: Array
 *
 * @return: Counted elements
 */

int ppclen(char **array)
{
    int count = 0;

    while (array[count] != NULL)
        count++;

    return (count);
}
