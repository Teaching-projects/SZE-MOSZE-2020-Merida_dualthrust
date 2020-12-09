#!/bin/bash

IFS=$'\n'

./a.out preparedgame.json -test >> results_preparedgame.txt


diff results_preparedgame.txt results_correct_preparedgame.txt

if [ $? -eq 0 ]
then
echo "Test successful."
exit 0
else
echo "Test failed."
exit 1
fi
