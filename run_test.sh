#!/bin/bash

IFS=$'\n'

./a.out scenario1.json
echo "east"

diff output.txt results_correct_scenario_1.txt

if [ $? -eq 0 ]
then
echo "Test successful."
else
echo "Test failed."
fi

./a.out scenario2.json
echo "east"
echo "\n"

diff output.txt results_correct_scenario_2.txt

if [ $? -eq 0 ]
then
echo "Test successful."
else
echo "Test failed."
fi