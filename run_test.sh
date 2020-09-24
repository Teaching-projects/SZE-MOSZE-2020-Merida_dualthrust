#!/bin/bash

IFS=$'\n'

./a.out units/Tolvaj.json units/Robin.json >> results.txt
./a.out units/Tolvaj.json units/Tomcat.json >> results.txt
./a.out units/Robin.json units/Tolvaj.json >> results.txt
./a.out units/Robin.json units/Tomcat.json >> results.txt
./a.out units/Tomcat.json units/Tolvaj.json >> results.txt
./a.out units/Tomcat.json units/Robin.json >> results.txt

cat results.txt
cat results_correct.txt

diff results.txt results_correct.txt
