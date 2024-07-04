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
#include <string.h>
#include <stdbool.h>

const char value_text[] = " [value] ";

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

/**
 * gen_flag_help - Generate a line from a Flag
 *
 * @arg1: Flag
 * @arg2: Furthest required offset of all flags that will be or have been passed
 */

void gen_flag_help(Flag flag,
                   int  furthest_offset)
{
    int description_offset = furthest_offset - strlen(flag.name);

    printf("--%s, -%c", flag.name, flag.code);
  
    if (flag.type == 1)
    {
        printf(value_text);
        description_offset -= strlen(value_text);
    }
   
    // Print necessary offset
    for (int i = 0; i < description_offset; i++)
        putchar(' ');
  
    printf("%s\n", flag.description);
}

/**
 * zinit - Help dialogue check and preperations for flag line generation
 *
 * @arg1: argv
 * @arg2: Flags
 *
 * @return: Exit/Continue
 */

bool zinit(char **argv,
           Flag   flags[],
           int    length)
{
    Flag help = {"help", 'h', 0, "Show this dialogue"};

    if (flag_count(argv, help) == 0)
        return false; // --help was not issued

    // Calculate length of longest argument with value_text
    int furthest_offset = 0;
    for (int i = 0; i < length; i++)
    {
        int buffer = strlen(flags[i].name);
        if (flags[i].type == 1)
            buffer += strlen(value_text);

        if (buffer > furthest_offset)
            furthest_offset = buffer;
    }

    printf("%s [option]\n\nOptions\n", argv[0]);
    gen_flag_help(help, furthest_offset);
    for (int i = 0; i < length; i++)
    {
        gen_flag_help(flags[i], furthest_offset);
    }

    return true; // --help was issued
}
