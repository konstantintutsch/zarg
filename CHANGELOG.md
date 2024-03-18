# Changelog

⚠️  — Breaking change

# 0.0.3

- Automatic help dialogue generation with `zinit()`
- ⚠️ Pass `Flag` type by value now ([Here's why](https://austinmorlan.com/posts/pass_by_value_vs_pointer/)): e. g. `flag_count(argv, &flag)` -> `flag_count(argv, flag)`

# 0.0.2

- ⚠️ Remove data type conversion
- ⚠️ Rename `argument_value()` to `flag_value()`
- ⚠️ Rename `argument_count()` to `flag_count()`
- ⚠️ Change data type of `flag_value()` to `char **`
- ⚠️ Rename `is_flag()` to `valid_flag()`
- ⚠️ Rename `is_argument()` to `match_flag()`
- ⚠️ Change data type of `valid_flag()` and `match_flag()` to `bool`
- Add check to `valid_flag()`: `-exyz` was valid for `-e` before, fixed now

# 0.0.1

- Support for short and long flags: `--example` or `-e`
- Support for string or integer values
- Support for boolean flags with `argument_count() > 0`
