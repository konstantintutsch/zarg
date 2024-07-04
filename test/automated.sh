#!/bin/bash

# Exit on error
set -e

# Executable used for testing
BASE="$(dirname ${0})/base"

check() {
    EXPECTED="${1}"
    FLAGS="${2}"

    OUTPUT=$(eval "${BASE} ${FLAGS}")

    printf "[CHECK] "

    if [[ ${OUTPUT} == ${EXPECTED} ]]
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
