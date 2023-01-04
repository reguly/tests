#need to be added to the render,video group for vtune/advisor on Intel Developer Cloud nodes

#aps
OMP_NUM_THREADS=1 OMP_PROC_BIND=TRUE mpirun -np 112 -bind-to core aps -r=aps_result -- ../MG-CFD-app-OP2/bin/mgcfd_mpi -i input-mgcfd.dat -m ptscotch

#aps --report ./aps_result

#vtune
#hpc-performance should work, but it failed in my test
types=( hotspots uarch-exploration memory-access threading )
for type in "${types[@]}"
do
# it should work generally for all MPIs, but it could have much higher overhead
OMP_NUM_THREADS=1 OMP_PROC_BIND=TRUE mpirun -np 112 -bind-to core -l vtune -c ${type} -r ${type}_allrank -- ../MG-CFD-app-OP2/bin/mgcfd_mpi -i input-mgcfd.dat -m ptscotch

#gtool is Intel MPI specific
ranks=( 5 0-3 )
for rank in "${ranks[@]}" 
do
	echo $rank $type
OMP_NUM_THREADS=28 OMP_PROC_BIND=TRUE mpirun -np 8 -bind-to numa  -gtool "vtune -c ${type} -r ${type}_rank${rank}:$rank"  ../MG-CFD-app-OP2/bin/mgcfd_mpi_openmp -i input-mgcfd.dat -m ptscotch
done

done

#advisor
#all tasks advisor 
#OMP_NUM_THREADS=1 OMP_PROC_BIND=TRUE mpirun -np 112 -bind-to core "advisor --collect=survey --project-dir=./advi_results" ../MG-CFD-app-OP2/bin/mgcfd_mpi -i input-mgcfd.dat -m ptscotch
#OMP_NUM_THREADS=1 OMP_PROC_BIND=TRUE mpirun -np 112 -bind-to core "advisor --collect=tripcounts --flop --project-dir=./advi_results" ../MG-CFD-app-OP2/bin/mgcfd_mpi -i input-mgcfd.dat -m ptscotch


# individual rank should be gnerated in the project dir  
#
#for example below
#zhuxiao@sdp4451:~/ops_spr/Rotor37_8M/advi_results$ ls
#advi_results.advixeproj  annotations.advidb2  rank.1  rank.2

ranks=( 1-2 )
for rank in "${ranks[@]}"
do
OMP_NUM_THREADS=1 OMP_PROC_BIND=TRUE mpirun -np 112 -bind-to core -gtool "advisor --collect=survey --project-dir=./advi_results:${rank}"   ../MG-CFD-app-OP2/bin/mgcfd_mpi -i input-mgcfd.dat -m ptscotch
OMP_NUM_THREADS=1 OMP_PROC_BIND=TRUE mpirun -np 112 -bind-to core -gtool "advisor --collect=tripcounts --flop --project-dir=./advi_results:${rank}"   ../MG-CFD-app-OP2/bin/mgcfd_mpi -i input-mgcfd.dat -m ptscotch
done

# view results
# to get an html report
  # advisor --report all –-project-dir ./advi_results –report-output=./op2_report.html --mpi-rank=1

#  or use 
 #  advisor-gui ./advi_results/rank.1
