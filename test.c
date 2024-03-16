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
    Flag help = {"help", 'h', 'b', "Help dialogue"};
    Flag num = {"number", 'n', 'i', "Print number"};
    Flag str = {"string", 's', 's', "Print string"};

    int helps = argument_count(argv, &help);
    int numbers = argument_count(argv, &num);
    int strings = argument_count(argv, &str);

    printf("Helps given: %d\n", helps);
    printf("Numbers given: %d\n", numbers);
    printf("Strings given: %d\n", strings);
    
    int *num_list = (int *)argument_value(argv, &num);
    for (int i = 0; i < numbers; i++)
        printf("Number %d: %d\n", i, num_list[i]);
    
    char **str_list = (char **)argument_value(argv, &str);
    for (int i = 0; i < strings; i++)
        printf("String %d: %s\n", i, str_list[i]);


    return 0;
}
