#include <stdio.h> 
#include "mpi.h"

// have PE0 send a number to other three PEs
// have them multiply that number that their own PE number
// print the results out, in order
// send them back to PE0
// print out the sum
main(int argc, char** argv){
  int my_PE_num, numbertoreceive, numbertosend=4,index, result=0; 
  MPI_Status status;
  MPI_Init(&argc, &argv); 
  MPI_Comm_rank(MPI_COMM_WORLD, &my_PE_num);
  
  if (my_PE_num==0)
    for (index=1; index<4; index++) // send a number to all other PEs (1-4)
      MPI_Send( &numbertosend, 1,MPI_INT, index, 10,MPI_COMM_WORLD); 
      // node 0 send to node 1,2,3
  else{ // all other PEs receive
    MPI_Recv( &numbertoreceive, 1, MPI_INT, 0, 10, MPI_COMM_WORLD, &status);
    // node 1,2,3 receives number 4 from node 0
    result = numbertoreceive * my_PE_num; // multiply by the their own PE number
    // calculate result, which is index*4//
    // does result automatically assume it is stored in a PE?
  }
  
  // why is sending serial but receiving parallel?
  
  for (index=1; index<4; index++){
    MPI_Barrier(MPI_COMM_WORLD);
    if (index==my_PE_num)
      printf("PE %d's result is %d.\n", my_PE_num, result);
  } // print PE number in order
  
  
  if (my_PE_num==0){
    for (index=1; index<4; index++){
      MPI_Recv( &numbertoreceive, 1,MPI_INT,index,10, MPI_COMM_WORLD, &status);
      // node 0 receives number from node 1,2,3
      result += numbertoreceive; // then add result together (I'm receiving number from
      //node 1, 2, 3, but how do I know 4, 8, 12 are stored in node 1,2,3?? I didn't
      // see the relevant operations?
    }
    printf("Total is %d.\n", result); }
  // node 
  else
    MPI_Send( &result, 1, MPI_INT, 0, 10, MPI_COMM_WORLD);
  
  
  
  MPI_Finalize();
}
