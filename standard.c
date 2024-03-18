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
 * zhelp - Generate a line from a Flag
 *
 * @arg1: Flag
 */

void zhelp(Flag flag)
{
    printf("--%s, -%c", flag.name, flag.code);
    
    if (flag.type == 1)
    {
        printf("  VALUE\t");
    }
    else
    {
        printf("\t\t");
    }
    
    printf("%s\n", flag.description);
}

/**
 * zinit - Help dialogue check
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
        return false;

    printf("%s [option]\n\nOptions\n", argv[0]);
    zhelp(help);
    for (int i = 0; i < length; i++)
    {
        zhelp(flags[i]);
    }

    return true;
}
