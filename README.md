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
- Boolean flags with `flag_count() > 0` ✅/❌

## Table of Contents

- [Installation](#installation)
  - [Prerequisites](#prerequisites)
  - [Compiling](#compiling)
- [Removal](#removal)
- [Testing](#testing)

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
