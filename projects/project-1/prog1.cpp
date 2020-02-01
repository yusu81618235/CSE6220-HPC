#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MPI_CHK(err) if (err != MPI_SUCCESS) return err



int main(int argc, char *argv[]) {

    if(argc!=3){
        fprintf(stderr,"argc invalid, must have N, C specified. aborting the program ... \n");
        exit(EXIT_FAILURE);
    }

    
    // int n;
    // int c;
    // n = atoi( argv[1] );
    // c = atoi( argv[2] );
    // int local_n = 
    // printf("local_n:%d,seed on master process c:%d\n",n,c);
    // printf("arg count: %d:\n" ,argc);
    // int i;
    // for (i=0; i<argc; i++){

    //     printf("arg num %d",i);
    //     printf("arg val: %s\n", argv[i]);
    // }
    int rank,size;
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int p = size;
    int err;
    // master process:
    const int root = 0;
    // int n,c;
    int arg_buff[2] = {0,0};
    if (rank == root){
        arg_buff[0]= atoi(argv[1]);
        arg_buff[1] = atoi(argv[2]);

    }
    printf("[%d]: before Bcast, number size is %d,master seeding number is %d\n", rank, arg_buff[0],arg_buff[1]);
    // all ranks start calling MPI_Bcast, root to all other ranks, assign a buff to send the argv, buff = [n,c], already converted to int type
    MPI_Bcast(&arg_buff, 2, MPI_INT, root, MPI_COMM_WORLD);
    
    //after Bcast, cast values to variable n, c , and calculate each rank's new seed number 
    int n,c;
    n = arg_buff[0];
    c = arg_buff[1];
    int new_seed;
    new_seed = c+rank;
    printf("[%d]: After Bcast, number size is %d, new seed number is %d\n",rank, n, new_seed);

    // consider the N/P, N is not divisible by P cases, we need to assign the maximum numbers for a rank, so some may have one more number than the other.
    
    // Get the rank of the process

    // Get the name of the processor
    // char processor_name[MPI_MAX_PROCESSOR_NAME];
    // int name_len;
    // MPI_Get_processor_name(processor_name, &name_len);

    // // Print off a hello world message
    // printf("From machine %s: rank %d out of %d processors\n",
    //        processor_name, rank, p);

    // Finalize the MPI environment.
    MPI_Finalize();
}