#!/usr/bin/bash
# cs4900
# Project 01
# Hannah Wysong
# w194hxw
# Due 23 Jan 2025  - accepted up to 10pm Jan24
# System = fry
# Compiler syntax = NA
# Job Control File = NA
# Additional File   = NA  (if more than one file, put these on separate lines)
# Results file         = proj01.txt
# Additional Resources = https://stackoverflow.com/questions/12722095/how-do-i-use-floating-point-arithmetic-in-bash ( for floating point algebra in bash )
declare -i sum
max=$1
min=$1
if [ 0 = $# ]; then
       echo 'sum=0     average=0'
        echo 'max=0     min=0'
else	
	for Variable in "$@"
	do
		sum+=$Variable
		if [ $Variable -gt $max ]; then 
			max=$Variable
		fi
		if [ $Variable -lt $min ]; then
                        min=$Variable
                fi
	done
	avg=$(echo "$sum/$#" | bc -l)
	printf '%s=%.2f\t' 'sum' $sum 'avg' $avg
	printf '\n'
	printf '%s=%.2f\t' 'max' $max 'min' $min
	printf '\n'
fi

