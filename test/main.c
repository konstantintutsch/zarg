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
    Flag flags[] = { with, without, _FLAG };

    if (zinit(argv, flags))
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
    if (flag_passed(argv, without))
        printf("passed\n");

    /**
     * Test for non-related arguments (argument_value())
     */
    char **files = argument_value(argv, flags);
    for (int i = 0; i < ppclen(files); i++)
        printf("File: %s\n", files[i]);
    free(files);

    return 0;
}
