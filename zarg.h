#ifndef ZARG_H

#include <stdbool.h>

#define _FLAG (Flag){"", 0, false, ""}

#define ZARG_H

typedef struct {
    char *name;
    char code;
    bool value;                 // false: boolean (no value passed after flag), true: with value
    char *description;
} Flag;

// init.c
bool zinit(char **argv, Flag flags[], int length);

// check.c
bool valid_flag(char *argument);
bool match_flag(char *argument, Flag flag);
bool compare_flag(Flag first, Flag second);

// parse.c
int flag_count(char **arguments, Flag flag);
char **flag_value(char **arguments, Flag flag);

// tools.c
int ppclen(char **array);
int arflen(Flag array[]);

#endif
