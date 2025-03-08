#!/bin/bash
#SBATCH --job-name=proj02
#SBATCH --output=proj02.txt
#SBATCH -N 1
#SBATCH --ntasks-per-node=16
function parallelTask {
	taskNum=$1
	for i in $(seq $1 16 64)
	do
		for j in $(seq 1 128)
   		do
			for k in $(seq 1 128)
	       		do	       
		       		~/decrypt $i $j $k w194hxw 
	    			done
		done
	done
	wait
}
date
for i in {1..16}
do
   parallelTask $i &
done
wait
date
