#!/bin/bash
#SBATCH -N 1                                    # Nodes = 1
#SBATCH --ntasks-per-node=40                    # Tasks on each node = 40 
#SBATCH --job-name=omp                          # Specify job name
#SBATCH --output=%J.out                         # Name of your output file (%J is replaced with job_id)
#SBATCH --error=%J.err                          # Name of your error file
#SBATCH --time=1-00:00:00                       # Specify time taken to run your script
#SBATCH --partition=cpu                         # Specify partition (cpu, gpu, hm)
#SBATCH --reservation=hpcws

ulimit -s unlimited

./$1
