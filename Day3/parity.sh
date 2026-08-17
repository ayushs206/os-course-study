#!/bin/bash
echo -n "Enter a number: "
read num
rem=$(expr $num % 2)
if [ "$rem" -eq 0 ]
then
	echo "$num is Even"
else
	echo "$num is Odd"
fi
