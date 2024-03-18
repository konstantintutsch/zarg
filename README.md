# zarg

```
Copyright (c) 2024 Konstantin Tutsch.
This project is distributed under the GNU General Public License.
```

A minimalist C library for standardi**z**ed handling of command line **arg**uments. 🚀

## Features

- Short and long flags: `--example` or `-e`
- Values for flags: `--example value`
- Boolean flags with `argument_count() > 0`

## Installation

### Prerequisites

- make (*v4.4+*)
- gcc (*v13.2+*)

### Compile

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
