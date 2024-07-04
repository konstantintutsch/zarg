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
