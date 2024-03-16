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

#include <string.h>

/**
 * is_flag - Check if string is a command line flag
 *
 * @arg1: argument
 *
 * @return: 1 Yes
 *          0 No
 */

int is_flag(char *argument)
{
    if (argument[0] == '-')
        return 1;

    return 0;
}

/**
 * is_argument - Check if string is argument flag
 *
 * @arg1: argument to check
 * @arg2: flag type
 *
 * @return: 1 Yes
 *          0 No
 */

int is_argument(char *argument,
                Flag *flag)
{
    if ((strcmp(argument + 2, flag->name) == 0) || (argument[1] == flag->code))
        return 1;

    return 0;
}


