#ifndef ZARG_H
#define ZARG_H

typedef struct {
    char *name;
    char  code;
    int   type; /* 0: boolean, 1: with value */
    char *description;
} Flag;

int    argument_count(char **arguments, Flag *flag);
char **argument_value(char **arguments, Flag *flag);

int ppclen(char **array);

int is_flag(char *argument);
int is_argument(char *argument, Flag *flag);

#endif
