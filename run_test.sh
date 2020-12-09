#!/bin/bash

IFS=$'\n'

./a.out preparedgame.json -test >> output_test.txt

diff output_test_correct.txt output_test.txt

if [ $? -eq 1 ]
then
echo "Test successful."
exit 0
else
echo "Test failed."
exit 1
fi