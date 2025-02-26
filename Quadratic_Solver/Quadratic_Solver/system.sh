#!/usr/bin/bash

# a=1 b=2 c=1   : x = 1
# a=1 b=-1 c=-2 : x = -1, x = 2
# a=1 b=-2 c=3  : No solutions
a=(1 1 1 "a" "1g")
b=(2 -1 -2 4 5)
c=(1 -2 3 6 1)

# Values of 1 mean that errors occurred
# No output will be given if return is non-zero 
return_values=(0 0 0 1 1)
output=("-1" "-1,2" "" "" "")

# Run program and save output as a variable
errors=0
for i in ${!a[@]}
do
	result=$(./quadratic_solver.exe ${a[i]} ${b[i]} ${c[i]})

	# First check to see if return value is expected
	actual_return=$?
	if [ $actual_return -ne ${return_values[i]} ]
	then
		echo "Failed test $i"
		echo "Inputs: {${a[i]} ${b[i]} ${c[i]}}; Expected return value: ${return_values[i]}; Actual return value: $actual_return"
		((errors++))
	fi

	# Skip output checking if return value is 1
	if [ $actual_return -gt 0 ]
	then
		continue
	fi

	# Note the double brackets '[[ ]]'
	# Needed to compare to empty string ""
	if [[ $result != ${output[i]} ]]
	then
		echo "Failed test $i"
		echo "Inputs: {${a[i]} ${b[i]} ${c[i]}}; Expected output: '${output[i]}'; Actual output: '$result'"
	fi
done

exit $((errors))