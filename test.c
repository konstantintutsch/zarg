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

#include "zarg.h"

int main(int   argc,
         char *argv[])
{
    Flag help = {"help",   'h', 'b', "Help dialogue"};
    Flag num  = {"number", 'n', 'i', "Print number"};
    Flag str  = {"string", 's', 's', "Print string"};

    if (argument_count(argv, &help) > 0)
    {
        printf(" --help,\t-h\tThis dialogue\n --number,\t-n\tPass a number\n --string,\t-s\tPass a string\n");
        return 0;
    }
    
    int *num_list = (int *)argument_value(argv, &num);
    for (int i = 0; i < argument_count(argv, &num); i++)
        printf("Number %d: %d\n", i, num_list[i]);
    
    char **str_list = (char **)argument_value(argv, &str);
    for (int i = 0; i < argument_count(argv, &str); i++)
        printf("String %d: %s\n", i, str_list[i]);

    return 0;
}
