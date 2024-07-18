# Changelog

⚠️ — Breaking change

# 0.1.2

-   Add `compare_flag()`
-   Add `_FLAG`
-   Add `arflen()`
-   From now on, arrays of Flag structs should look like this: `{yourflag, yourotherflag, _FLAG}`. The `_FLAG` marks the end of the array.
-   You can use `arflen()` to get the number of elements of this array.
-   ⚠️ Remove parameter `int length` from `zinit()`
-   ⚠️ `zinit()`'s array of Flag structs parameter now needs `_FLAG` as it's last element

# 0.1.1

-   Add minimum offset of 1 between flags and their description

# 0.1.0

-   Manually generate spacing for description in the help dialogue to replaces tabs and avoid visual errors
-   ⚠️ Move int Flag.type to bool Flag.value: name and data type change in struct Flag

# 0.0.4

-   Replace `  VALUE` with ` [value]` in help dialogue
-   Add error handling for value flags for which no value was given

# 0.0.3

-   Automatic help dialogue generation with `zinit()`
-   ⚠️ Pass `Flag` type by value now ([Here's why](https://austinmorlan.com/posts/pass_by_value_vs_pointer/)): e. g. `flag_count(argv, &flag)` -> `flag_count(argv, flag)`

# 0.0.2

-   ⚠️ Remove data type conversion
-   ⚠️ Rename `argument_value()` to `flag_value()`
-   ⚠️ Rename `argument_count()` to `flag_count()`
-   ⚠️ Change data type of `flag_value()` to `char **`
-   ⚠️ Rename `is_flag()` to `valid_flag()`
-   ⚠️ Rename `is_argument()` to `match_flag()`
-   ⚠️ Change data type of `valid_flag()` and `match_flag()` to `bool`
-   Add check to `valid_flag()`: `-exyz` was valid for `-e` before, fixed now

# 0.0.1

-   Support for short and long flags: `--example` or `-e`
-   Support for string or integer values
-   Support for boolean flags with `argument_count() > 0`
