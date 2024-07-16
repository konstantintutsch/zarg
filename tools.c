#include "zarg.h"

#include <stddef.h>

/**
 * ppclen - Counts how many elements exist in an array of pointers to pointers to characters
 * @arg1 - Array of strings with last element equal to NULL
 *
 * Return: The number of elements
 */

int ppclen(char **array)
{
    int count = 0;

    while (array[count] != NULL)
        count++;

    return (count);
}
