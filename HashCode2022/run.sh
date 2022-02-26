#!/bin/bash

# Usage run.sh OriginalSolution BruteForceSolution [Checker]

# Requirement: Have a program named gen.cpp which generates appropriate
# test cases
# If checker is provided, it should return an exit code of 0 if check passes and 1 otherwise

# Initial clean up
if [ -a sol ]; then
    rm sol
fi
if [ -a brute ]; then
    rm brute
fi
if [ -a gen ]; then
    rm gen
fi
if [ -a check ]; then
    rm check
fi

if [ -z "$1" ]; then
    echo "Error: Original solution missing"
	exit 1
fi
if [ -z "$2" ]; then
    echo "Error: Brute force solution missing"
	exit 1
fi


g++ -std=c++17 "$1.cpp" -o sol
g++ -std=c++17 "$2.cpp" -o brute
g++ -std=c++17 "gen.cpp" -o gen

# Check if the third command line argument is unitialized
if [ ! -z "$3" ]; then
    g++ -std=c++17 "$3.cpp" -o check
fi

for((i = 1; ; ++i)); do
    ./gen $i > in
    ./sol < in > out
    ./brute < in > correct
    
    if [ -a check ]; then
        ./check > log
        if [ $? -eq 1 ]; then
            break;
        fi
    else
        if ! diff -Z -u "out" "correct" > log ; then
            break
        fi
    fi
    echo "Test: $i"
    echo "AC"
done

echo "WA on the following test:"
cat in

echo "Your answer is:"
cat out

echo "Correct answer is:"
cat correct

echo "Checker Log:"
cat log

rm gen sol brute out correct log

if [ -a check ]; then
    rm check
fi
