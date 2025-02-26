#!/usr/bin/bash

# Compile C++ executable
g++ ./quadratic_solver.cpp -o quadratic_solver.exe

if [ $? -eq 0 ]
then
	echo "Program compiled"
fi

# a=1 b=2 c=1   : x = 1
# a=1 b=-1 c=-2 : x = -2, x = 1
# a=1 b=-2 c=3  : No solutions
a=(1 1 1)
b=(2 -1 -2)
c=(1 -2 3)
output=("-1" "2,-1" "")

# Run program and save output as a variable
errors=0
for i in ${!a[@]}
do
	result=$(./quadratic_solver.exe ${a[i]} ${b[i]} ${c[i]})

	# Note the double brackets '[[ ]]'
	# Needed to compare to empty string ""
	if [[ $result != ${output[i]} ]]
	then
		((errors++))
		echo "error: Result $result != Expected output ${output[i]}"
	fi
done

# Check actual output against expected
if [ $errors -eq '0' ]
then
	echo "Passed all tests"
fi
