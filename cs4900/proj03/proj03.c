//
// cs4900
// Project 03
// Hannah Wysong
// w194hxw
// Due 08 Feb 2024, accepted up to Feb 09 10pm
// System = fry
// Compiler syntax = sbatch proj03.sbatch
// Job Control File = proj03.sbatch
// Additional File  = NA
// Results file     = proj03.txt
//

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <assert.h>

//#define DEBUG

// DO NOT CHANGE THIS FUNCTION!!!!!
// function to return a random variable between [0,1)
double randVar() {
    return (double)((rand() % 2000000000) / 2000000000.0);
}

/* function to return M and P*/
unsigned long* calMandP(int N ) {

  //Save the results in an integer array
  static unsigned long MnP[2];

  // Constant for small square 
  // Reciprocal of sqrt(2) or 1/sqrt(2)
  double rsq2=0.70710678118654752440;

  // initialize counters each time the function is called
  unsigned long M=0, P=0;
  
  // random variables
  double x, y, rs;
  int randomPnts;

   // Pick N random (x,y) points
  for(randomPnts = 0; randomPnts < N; ++randomPnts) {

    x=randVar();
    y=randVar();

    // radius squared
    rs=x*x+y*y;

#ifdef DEBUG
    // test random values in function
    printf("%d x=%f y=%f rs=%f\n",randomPnts,x,y,rs);
#endif 

    if (rs<1){                   // or should it be rs<=1
      // Inside circle
      ++M;
      if (x<rsq2 && y<rsq2){     // or should it be <=
	// inside inner square
	++P;
      }
    }
  }

  MnP[0]=M;  
  MnP[1]=P;  
  return MnP;
}

int main(int argc, char *argv[]) {
  clock_t begin = clock();
    int rank, size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Use current time as seed for random generator 
    srand(time(0)); 

    // For convenience I passed "N" on the command line
    char *a = argv[1];
    int N = atoi(a);

    unsigned long* MnP; // Store in vector M=MnP[0] and P=MnP[1]
    unsigned long sum_M = 0, sum_P = 0;
    float prev_M = 1, prev_P = 1;
    unsigned long recv_M = 0, recv_P = 0;
    float epsilon = 0.000001;
    bool notEpsilon = true;
    int count = 0;
    int N_total = 0;

    while (notEpsilon){
    // Perform calculations on each rank
    MnP = calMandP(N);
    N_total += (N*size);
    // Send result to rank 0
    if (rank != 0) {
        MPI_Send(&MnP[0], 1, MPI_UNSIGNED_LONG, 0, 555, MPI_COMM_WORLD);
        MPI_Send(&MnP[1], 1, MPI_UNSIGNED_LONG, 0, 333, MPI_COMM_WORLD);

    } else {
        count++;

        // Collect data from each rank
        for (int i = 1; i < size; i++) {
            MPI_Recv(&recv_M, 1, MPI_UNSIGNED_LONG, i, 555, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Recv(&recv_P, 1, MPI_UNSIGNED_LONG, i, 333, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            sum_M += recv_M;
            sum_P += recv_P;
        }

        // Include rank 0's own results
        sum_M += MnP[0];
        sum_P += MnP[1];

        // Display results
        if (count != 1 && fabs((4.0 * sum_M / (4.0*N*count)) - prev_M) < epsilon &&
		       	fabs((2.0 * sum_M / sum_P) - prev_P) < epsilon) {
    printf("Results\n");
    printf("Iterations: %i\n", count);
    printf("N: %i\n", N_total);
    printf("Epsilon: %f\n", epsilon);
    printf("M Total: %llu\n", sum_M);
    printf("P Total: %llu\n", sum_P);
    printf("Final M Pi: %f\n",  4.0 * sum_M / (4.0*N*count));
    printf("Final P Pi: %f\n", 2.0 * sum_M / sum_P);
    notEpsilon=false;
  }
  
	prev_M = 4.0 * sum_M / (4.0*N*count);
	prev_P = 2.0 * sum_M / sum_P;
}
}
    // Finalize the MPI environment.
  clock_t end = clock();
	double time = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time: %f\n", time);
  
  MPI_Finalize();
  return 0;
}


