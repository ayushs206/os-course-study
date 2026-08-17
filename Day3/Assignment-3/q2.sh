#!/bin/bash

read -p "Enter string 1: " str1
read -p "Enter string 2: " str2

if [[ "$str1" < "$str2" ]]
then
	echo "$str1 appears first in dictionary"
elif [[ "$str1" == "$str2" ]]
then
	echo "$str1 and $str2 are same strings"
else 
	echo "$str1 appears later in dictionary"
fi
