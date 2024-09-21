#ifndef ZARG_H

#include <stdbool.h>

#define _FLAG (Flag){"", 0, false, ""} /**< This macro marks the end of an array of Flag structures. */

#define ZARG_H

typedef struct {
    char *name;                 /**< This field stores the full name of the Flag. It will be the text used after a double dash (`--`) */
    char code;                  /**< This field stores the abbreviation of the name of the Flag. It will be the character used after a single dash (`-`) */
    bool value;                 /**< This field indicates whether a Flag accepts a value or is just a toggle. */
    char *description;          /**< This field stores the description of the function of the Flag. */
} Flag;

// init.c
bool zinit(char **argv, Flag flags[]);

// check.c
bool valid_flag(char *argument);
bool match_flag(char *argument, Flag flag);
bool compare_flag(Flag first, Flag second);

// parse.c
unsigned int flag_count(char **arguments, Flag flag);
char **flag_value(char **arguments, Flag flag);
char **argument_value(char **arguments, Flag flags[]);

// tools.c
unsigned int ppclen(char **array);
unsigned int arflen(Flag array[]);
bool flag_passed(char **arguments, Flag flag);

#endif
