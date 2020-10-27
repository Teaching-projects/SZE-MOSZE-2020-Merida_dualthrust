#!/bin/bash
if grep --quiet "error" "./cppcheck_results.txt"
then exit 1
fi
