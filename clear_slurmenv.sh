#!/bin/bash
vars=$(env | grep -o '^SLURM_[^=]*')

# Loop over the list and unset each variable
for var in $vars
do
    unset $var
done
