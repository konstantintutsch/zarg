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

#include <stdio.h>
#include <stdlib.h>

#include "zarg.h"

int main(int   argc,
         char *argv[])
{
    Flag help = {"help",   'h', 0, "Help dialogue"};
    Flag num  = {"number", 'n', 1, "Print number"};
    Flag str  = {"string", 's', 1, "Print string"};

    if (argument_count(argv, &help) > 0)
    {
        printf(" --help,\t-h\tThis dialogue\n --number,\t-n\tPass a number\n --string,\t-s\tPass a string\n");
        return 0;
    }
    
    char **num_list = argument_value(argv, &num);
    for (int i = 0; i < argument_count(argv, &num); i++)
        printf("Number %d: %d\n", i, atoi(num_list[i]));
    free(num_list);
    
    char **str_list = argument_value(argv, &str);
    for (int i = 0; i < argument_count(argv, &str); i++)
        printf("String %d: %s\n", i, str_list[i]);
    free(str_list);

    return 0;
}
