#!/bin/bash

# Exit on error
set -e

# Executable used for testing
BASE="$(dirname ${0})/../build/test"

# check - Compare expected output and actual output of command
# @arg1 - Expected output as string
# @arg2 - Flags to append to BASE to assemble command
#
# Return: 0 Expected and actual output match
#         1 Expected does not match actual output
check() {
    EXPECTED="${1}"
    FLAGS="${2}"

    OUTPUT=$(eval "${BASE} ${FLAGS}")

    # Hash for multiline string comparison support
    HASH_EXPECTED="$(md5sum <<<${EXPECTED})"
    HASH_OUTPUT="$(md5sum <<<${OUTPUT})"

    printf "[CHECK] "

    if [[ ${HASH_OUTPUT} == ${HASH_EXPECTED} ]]
    then
        echo "Success"
        RESULT=0
    else
        echo "Failed 🔴"
        echo "Flags:    “${FLAGS}”"
        echo "Expected: “${EXPECTED}”"
        echo "Output:   “${OUTPUT}”"
        RESULT=1
    fi

    return ${RESULT}
}

# Help
HELP="${BASE} [option]

Options
--help, -h          Show this dialogue
--value, -v [value] A flag accepting a value
--boolean, -b       A flag not reading a value"
check "${HELP}" "-h"
check "${HELP}" "--help"

# Value Flags
check "short flag" "-v 'short flag'"
check "long flag" "--value 'long flag'"

# Boolean Flags
check "passed" "-b"
check "passed" "--boolean"
## Opposite (Flag not passed)
check "" ""

# Finished
echo "All checks passed. Success 🟢"
