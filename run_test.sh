#!/bin/bash

IFS=$'\n'

./a.out scenario1.json >> results.txt

diff results.txt results_correct.txt

if [ $? -eq 0 ]
then
echo "Test successful."
else
echo "Test failed."
fi