#!/bin/bash

IFS=$'\n'

./a.out preparedgame.json -test


diff results_correct_preparedgame.txt ./renderer outputs/hero_text_output.txt

if [ $? -eq 0 ]
then
echo "Test successful."
exit 0
else
echo "Test failed."
exit 1
fi
