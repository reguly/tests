#!/bin/bash
#SBATCH --job-name=rtm    # Job name
#SBATCH --ntasks=2                    # Run on a single CPU
##SBATCH --nodes=1
#SBATCH --time=01:00:00               # Time limit hrs:min:sec
#SBATCH --output=out_%j.log   # Standard output and error log
##SBATCH --gres=gpu:4
#SBATCH --account=jarvissz-cfd-scaling
##SBATCH --partition=baskerville 
#SBATCH --qos=bham 
#SBATCH --exclusive
#SBATCH --cpus-per-task 72
#SBATCH --mem 400G

hostname
cd /bask/projects/j/jarvissz-cfd-scaling/tests
./run_all.sh
