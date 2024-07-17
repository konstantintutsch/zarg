#include <zarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of program
 *        Also contains all possible use cases of zarg
 *
 * Return: 0 Successful
 */

int main(int argc, char *argv[])
{
    Flag with = { "value", 'v', true, "A flag accepting a value" };
    Flag without = { "boolean", 'b', false, "A flag not reading a value" };

    if (zinit(argv, (Flag[]) {
              with, without}
              , 2))
        return 0;

    /**
     * Test for Flag.value = true (with)
     */
    char **values = flag_value(argv, with);
    for (int i = 0; i < ppclen(values); i++)
        printf("%s\n", values[i]);
    free(values);

    /**
     * Test for Flag.value = false (without)
     */
    if (flag_count(argv, without) > 0)
        printf("passed\n");

    return 0;
}
