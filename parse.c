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
unsigned int flag_count(char **arguments, Flag flag)
{
    unsigned int amount = 0;
    unsigned int length = ppclen(arguments);

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

    unsigned int length = ppclen(arguments);
    unsigned int write = 0;

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

/**
 * This function detects arguments not in relation to any Flag structures.
 * @param arguments Arguments as strings (argv from main)
 * @param flags Flag structures
 *
 * @return An array of strings containing all value arguments without relations. `free()` has to be called on the return
 */
char **argument_value(char **arguments, Flag flags[])
{
    unsigned int arguments_c = ppclen(arguments);        // NULL in arguments[] marks a related argument, not the end of the array

    arguments[0] = NULL;        // Executed command, not an argument
    for (int index_a = 1; index_a < arguments_c; index_a++) {
        if (arguments[index_a] == NULL)
            continue;

        for (int index_f = 0; index_f < arflen(flags); index_f++) {
            if (!match_flag(arguments[index_a], flags[index_f]))
                continue;
            arguments[index_a] = NULL;  // is a Flag, related

            if (!flags[index_f].value)
                continue;
            arguments[index_a + 1] = NULL;      // is the argument of a Flag accepting values, related

            break;
        }
    }

    // Elements of index array growing dynamic to the amount of non-related arguments
    typedef struct {
        int *array;
        size_t size;
    } dynamic_int;
    dynamic_int index = { NULL, 0 };
                                   // All indexes for arguments[] which contain values to be returned

    size_t allocate = 0; // Number of characters which will be stored
    for (int i = 0; i < arguments_c; i++) {
        if (arguments[i] == NULL)       // is related, skip
            continue;

        allocate += strlen(arguments[i]);

        // Grow array for one more int
        index.size++;
        index.array = realloc(index.array, index.size * sizeof(int));
        // Save position in array
        index.array[index.size - 1] = i;
    }
    char **nonrelated = malloc(allocate * sizeof(char) + 14 * sizeof(char));    // I don't know why, but you need at least `14*sizeof(char)` to store NULL at the end of this array. `size(NULL)`, `sizeof(void*)` and `sizeof(char*)` are not sufficient for some reason??? Oh, and otherwise, NULL will be stored in the first and last element of the array?????

    // Filter out all NULL elements from arguments and save them in nonrelated
    for (int i = 0; i < index.size; i++) {
        nonrelated[i] =
            malloc(strlen(arguments[index.array[i]]) * sizeof(char));
        strcpy(nonrelated[i], arguments[index.array[i]]);
    }
    // Mark end of array to be compatible with ppclen()
    nonrelated[index.size] = NULL;

    return nonrelated;
}
