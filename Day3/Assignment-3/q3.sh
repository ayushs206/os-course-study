#!/bin/bash

read -p "Enter first Element: " num1
read -p "Enter second Element: " num2
read -p "Enter number of next elements want to print: " count

for ((i=1; i<=count; i++))
do
	sum=$((num1+num2))
	num1=$num2
	num2=$sum
	echo "$sum"
done
