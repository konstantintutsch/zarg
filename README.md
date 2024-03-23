# zarg

```
Copyright (c) 2024 Konstantin Tutsch.
This project is distributed under the GNU General Public License.
```

A minimalist C library for standardi**z**ed handling of command line **arg**uments. 🚀

## Features

*zarg* aims to be a fast, minimalist and efficient library designed for lightweight applications 🍃

- Short Flags: Single dash and single alphanumeric character ⏱️
- Long Flags: Double dash and multiple alphanumeric characters 📍
- Values: Read strings behind flags and create an array 📊
- Simple boolean flags ✅
- Automatically generated help dialogue 📚

## Table of Contents

- [Example](#example)
- [Installation](#installation)
  - [Prerequisites](#prerequisites)
  - [Compiling](#compiling)
- [Removal](#removal)
- [Testing](#testing)

## Example

How you can use *zarg*.

```c
#include <stdio.h>
#include <stdlib.h>
#include <zarg.h>

int main(int   argc,
         char *argv[])
{
    /* long, short, type (with/without value), description */
    Flag plus = {"add", 'a', 1, "Add up numbers"};
    Flag encourage = {"encourage", 'e', 0, "Encourage the user"};

    /* Help dialogue check, exit */
    if (zinit(argv, (Flag[]){plus,encourage}, 2))
        return 0;

    int total = 0;
    char **numbers = flag_value(argv, plus);

    for(int i = 0; i < ppclen(numbers); i++) /* DO NOT use flag_count(argv, plus) */
        total += atoi(numbers[i]);

    free(numbers);
    printf("Your numbers sum up to %d!\n", total);

    if (flag_count(argv, encourage) > 0)
        printf("Great job! That's how one should pass command line arguments!\n");

    return 0;
}
```

Compile.

```
$ gcc -Wall -fstack-protector -lzarg myzarg.c -o myzarg
```

Then execute:

```
$ ./myzarg --help
./myzarg [option]

Options
--help, -h          Show this dialogue
--add, -a [value]   Add up numbers
--encourage, -e     Encourage the user
```

… or

```
$ ./myzarg --add 2 -a 40
Your numbers sum up to 42!
```

If you've had a bad day, add `--encourage`!

```
$ ./myzarg --encourage -a 40 -a 2
Your numbers sum up to 42!
Great job! That's how one should pass command line arguments!
```

A complete list of *zarg*s capabilities is written down in [test.c](/test.c).

## Installation

### Prerequisites

- make (*v4.4+*)
- gcc (*v13.2+*)

### Compiling

To compile libzarg, execute the `build` make rule.

```
$ make build
```

After building libzarg, execute the `install` rule with root privileges to install libzarg to your system.

```
# make install
```

## Removal

Execute the `uninstall` rule with root privileges to completely remove libzarg from your system.

```
# make uninstall
```

## Testing

Follow the installation steps first. Once finished, use the `test` make rule to compile the test application.

```
$ make test
```

To get started, execute `./test --help`.
