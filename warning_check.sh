#!/bin/bash
if grep --quiet "warning" "./cppcheck_results.txt"
then exit 1
fi
