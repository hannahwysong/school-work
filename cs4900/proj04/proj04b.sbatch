#!/bin/bash

#SBATCH -N 1
#SBATCH --tasks-per-node=8
#SBATCH --job-name=proj04b
#SBATCH --output=proj04b.txt
#SBATCH --time=30:00

## First make sure all other modules are not loaded
module purge

## Load the appropriate module
module load openmpi/4.0.3-gcc-8.5.0

## compile your code
mpicc proj04b.c -o proj04b.mpi -lm

# Fix your environment
export OMPI_MCA_pml="^ucx"
export OMPI_MCA_btl_openib_if_include="mlx4_0:1"

# Make code executable
chmod u+x proj04b.mpi

# Runs for dot product calculations

m=10
for i in {1..9}; do
L1=$(($m**$i))
#mpirun -np 16 ./proj04b.mpi $L1 0 1 -1 45 45
done

for i in {1..9}; do
L1=$(($m**$i))
B=L1/4
#mpirun -np 16 ./proj04b.mpi $L1 0 1 $B 22 90
done

for i in {1..9}; do
L1=$(($m**$i))
B=L1*2.2
#mpirun -np 16 ./proj04b.mpi $L1 0 1 $B 75 135
done

# Runs for matrix multiplication


L2=1000
b=2.4*L2
mpirun -np 8 ./proj04b.mpi $L2 $L2 1 $b 45 135
mpirun -np 8 ./proj04b.mpi 1000 1000 1 1 135 135

L2=100000
b=2.4*L2
mpirun -np 8 ./proj04b.mpi $L2 $L2 1 $b 45 135
mpirun -np 8 ./proj04b.mpi 100000 100000 1 1 135 135