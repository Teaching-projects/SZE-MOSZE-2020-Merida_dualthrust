#!/bin/bash

IFS=$'\n'

for i in 'cat input.txt';
do
    echo "Input parameters: $i, results:"
    echo "$i" | ./a.out 
done