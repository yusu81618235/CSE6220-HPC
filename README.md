# CSE6220-HPC
HPC course CSE6220 github repo

## Install MPICH on local machines:
For my ubuntu and mac:<br>
1. Install MPICH from the tar ball: [mpich-3.3.2](https://www.mpich.org/downloads/)
```
$ wget http://www.mpich.org/static/downloads/3.3.2/mpich-3.3.2.tar.gz
$ tar -xzf mpich-3.3.2.tar.gz
$ cd mpich-3.3.2
```
2. Configure, avoid building fortran library as not needed:
```
$ ./configure --disable-fortran
```
    ... Wait until the command logs showing Configuration completed.
  
3. Make and install:
```
$ make; sudo make install
```
4. test with `$ mpiexec --version`, if make is successful, call this command, will have the following:
```
HYDRA build details:
    Version:                                 3.3.2
    Release Date:                            Tue Nov 12 21:23:16 CST 2019
    CC:                              gcc    
    CXX:                             g++    
    F77:                             
    F90:                             
    Configure options:                       '--disable-option-checking' '--prefix=NONE' '--disable-fortran' '--cache-file=/dev/null' '--srcdir=.' 'CC=gcc' 'CFLAGS= -O2' 'LDFLAGS=' 'LIBS=' 'CPPFLAGS= -I/home/muyangguo/mpich-3.3.2/src/mpl/include -I/home/muyangguo/mpich-3.3.2/src/mpl/include -I/home/muyangguo/mpich-3.3.2/src/openpa/src -I/home/muyangguo/mpich-3.3.2/src/openpa/src -D_REENTRANT -I/home/muyangguo/mpich-3.3.2/src/mpi/romio/include' 'MPLLIBNAME=mpl'
    Process Manager:                         pmi
    Launchers available:                     ssh rsh fork slurm ll lsf sge manual persist
    Topology libraries available:            hwloc
    Resource management kernels available:   user slurm ll lsf sge pbs cobalt
    Checkpointing libraries available:       
    Demux engines available:                 poll select

```


The cluster used MPI lib is mvapich2, I chose to use MPICH on my local machine, as many features for clusters and networks are not needed. Alternatively, another open source distribution is OpenMPI. I just go with MPICH, either one should work. 


