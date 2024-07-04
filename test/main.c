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

#include <zarg.h>
#include <stdio.h>
#include <stdlib.h>

int main(int   argc,
         char *argv[])
{
    Flag with = {"value", 'v', true, "A flag accepting a value"};
    Flag without = {"boolean", 'b', false, "A flag not reading a value"};

    if (zinit(argv, (Flag[]){with, without}, 2))
        return 0;

    /**
     * Test for Flag.value = true (with)
     */
    char **values = flag_value(argv, with);
    for(int i = 0; i < ppclen(values); i++)
        printf("%s\n", values[i]);
    free(values);

    /**
     * Test for Flag.value = false (without)
     */
    if (flag_count(argv, without) > 0)
        printf("passed\n");

    return 0;
}
