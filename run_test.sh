#!/bin/bash

IFS=$'\n'

diff output_test_render_correct.txt output_test_render.txt

if [ $? -eq 0 ]
then
echo "Test successful."
exit 0
else
echo "Test failed."
exit 1
fi
