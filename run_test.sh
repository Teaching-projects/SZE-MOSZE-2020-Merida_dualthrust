#!/bin/bash

IFS=$'\n'

./a.out scenario1.json -test >> results_scenario_1.txt


diff results_scenario_1.txt results_correct_scenario_1.txt

if [ $? -eq 0 ]
then
echo "Test successful."
exit 0
else
echo "Test failed."
exit 1
fi
