#ifndef ZARG_H
#define ZARG_H

typedef struct {
    char *name;
    char  code;
    char  type; /* i > integer; s > string, b > boolean */
    char *description;
} Flag;

int   argument_count(char **arguments, Flag *flag);
void *argument_value(char **arguments, Flag *flag);

int ppclen(char **array);

int is_flag(char *argument);
int is_argument(char *argument, Flag *flag);

#endif
