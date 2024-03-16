/**
 * Copyright (c) 2024 Konstantin Tutsch.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "zarg.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * array_elements - Counts how many elements exist in an array of pointers to strings
 *
 * @arg1: array
 *
 * @return: counted elements
 */

int array_elements(char **array)
{
    int count = 0;

    while (array[count] != NULL)
        count++;

    return (count);
}

/**
 * argument_count - Count how many arguments of a given type exist
 *
 * @arg1: arguments
 * @arg2: type, e. g. d,e
 *
 * @return: Count of arguments
 */

int argument_count(char **arguments,
                   Flag  *flag)
{
    int amount = 0;

    for (int i = 1; i < array_elements(arguments); i++)
    {
        if (is_argument(arguments[i], flag))
            amount++;
    }

    return amount;
}

/**
 * argument_value - Filter out values from a command line arguments
 *             e. g. `-d ./src`,`--directory ./lib` -> `./src`,`./lib`
 *
 * @arg1: command line arguments
 * @arg2: argument to check for
 *
 * @return: Success
 */

void *argument_value(char **arguments,
                     Flag  *flag)
{
    void *ptr;

    int flagc = argument_count(arguments, flag);
    int numbers[flagc];
    char **strings = malloc(flagc * sizeof(char *));

    int argi = 0;

    for (int i = 0; i < array_elements(arguments); i++)
    {
        if (!is_flag(arguments[i]))
            continue;

        if (!is_argument(arguments[i], flag))
            continue;

        char *buffer = arguments[i + 1];

        switch(flag->type)
        {
        case 'i':
            numbers[argi] = atoi(buffer);
            break;
        case 's':
            strings[argi] = malloc(strlen(buffer) * sizeof(char));
            strcpy(strings[argi], buffer);
            break;
        }

        argi++;
    }

    switch(flag->type)
    {
    case 'i':
        ptr = &numbers;
        break;
    case 's':
        ptr = (void *)strings;
        break;
    }

    return ptr;
}