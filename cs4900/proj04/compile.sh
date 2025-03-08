#!/usr/bin/bash

# compile the source
/opt/apps/mpi/openmpi-4.0.3_gcc-8.5.0/bin/mpicc $1.c -o $1.mpi -lm

# make it executable
chmod 700 $1.mpi

