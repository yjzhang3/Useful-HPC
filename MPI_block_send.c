// MPI_Comm_rank is the "communicator" and can be found in many MPI routines
// it is used so that one can divide upthe PEs into subset for various algorithmic outpus

// in this file, we want to send 
#include <stdio.h>
#include "mpi.h"
main(int argc, char** argv) {
  int my_PE_num, numbertoreceive, numbertosend=42;
  MPI_status status; 
  // arc is the number of arguments passed into the program
  
  MPI_Init(&argc, &argv); //before any MPI call must have this
  MPI_Comm_rank(MPI_COMM_WORLD，&my_PE_num)); // MPI_COMM_WORLD is a communicator
  // that is used to divide PEs into sub sections
  
  
    // numbertoreceive, a pointer that will get value right before the call
    // 1 is number of items to receive
    // MPI_INT is datatype
  if (my_PE_num==0) {
    MPI_Recv (&numbertoreceive, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status)；
    printf("Number received is: %d\n", numbertoreceive)
    }
  else MPI_Send(&numbertosend, 1, MPI_INT, 0,10,MPI_COMM_WORLD);
  // a pointer to whatever we wish to send
  // number of ...
  // datatype
  // destination of messgae, PE0
  // message tag (specifies priority)
  // don't care about subsets of PEs
  
  MPI_Finalize();
}
  

      
  
  
