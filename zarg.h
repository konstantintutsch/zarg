#ifndef ZARG_H

#include <stdbool.h>

#define ZARG_H

typedef struct {
    char *name;
    char  code;
    int   type; /* 0: boolean, 1: with value */
    char *description;
} Flag;

bool valid_flag(char *argument);
bool match_flag(char *argument, Flag flag);

int    flag_count(char **arguments, Flag flag);
char **flag_value(char **arguments, Flag flag);

int  ppclen(char **array);
bool zinit(char **argv, Flag flags[], int length);

#endif
