#!/bin/bash

rm -f -r in template *.out *.dSYM

chars=( {a..z} )

for i in {a..z}; do
	rm -f "${i}.cpp"
	rm -f "${i}" "${i}.out"
done

files=()

for((i = 0; i < $1; ++i)); do
	touch "${chars[i]}.cpp"
	files+=( "${chars[i]}.cpp" )
done

subl --project setup ${files[@]}
echo "Created " ${files[@]}
