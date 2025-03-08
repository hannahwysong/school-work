//
// cs4900
// Project 04a
// Hannah Wysong
// w194hxw
// Due 27 Feb 2024, accepted up to Feb 28 10pm
// System = fry
// Compiler syntax =
// Job Control File = proj04a.sbatch
// Results file     = proj04a.txt
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>
#include <assert.h>

float dot(float *v1, float *v2, int N) {
    int i;
    float sum=0.0;
    for (i = 0; i < N; i++) {
        sum += v1[i]*v2[i];
    }
    return sum;
}

float** mult(float *V3, float *V1, int L1, int L2) {
    float sum;
    // solution matrix
    float **solMat = (float **)malloc(L2 * sizeof(float *));                                                                                                        
    for (int i=0; i<L2; i++) {                         
        solMat[i] = (float *)malloc(L1 * sizeof(float));     
    }
  for (int i = 0; i < L2; i++) {
    for (int j = 0; j < L1; j++) {
    solMat[i][j]=V3[i]*V1[j];
    }
  }
  return solMat;
}

void printV(float *V, int size) {
    for (int i = 0; i < size; i++) {
        printf("%f\n", V[i]);
    }
}

int main(int argc, char** argv)
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int L1 = atoi(argv[1]);
    int L2 = atoi(argv[2]);
    int A = atoi(argv[3]);
    int B = atoi(argv[4]);
    int Ap = atoi(argv[5]);
    int Bp = atoi(argv[6]);

    float *V1 = (float *)malloc(sizeof(float) * L1);
    assert(V1 != NULL);
    float *V2 = (float *)malloc(sizeof(float) * L1);
    assert(V2 != NULL);
    float *V3 = (float *)malloc(sizeof(float) * L1);
    assert(V3 != NULL);                                                                                                       
    // Constants
    float pi=acos(-1.0);
    float a = pi * Ap/180;
    float b = pi * Bp/180;
    float dx=2.0*pi/L1;
    float dy=2.0*pi/L2;
    float norm1=sqrt(2.0/L1);
    float norm2=sqrt(2.0/L2);

    float Xi;
    float Yi;
    int NL1 = (int)(L1/size); 
    int RL1 = (L1%size);
    float xlast;

    // partition elements on each rank 
    if (rank<RL1){
        ++NL1;
        xlast=-dx/2.0+rank*NL1*dx;
    }else{
        xlast=-dx/2.0+RL1*(NL1+1)*dx+(rank-RL1)*NL1*dx;
    }

    Xi=xlast;
        for (int i = 0; i < NL1; i++) {
        Xi=Xi+dx;
        V1[i]=norm1*cos(A*Xi+a);
        V2[i]=norm1*sin(B*Xi+b);
        V3[i]=norm2*cos(B*Xi+b);
        }

    MPI_Barrier(MPI_COMM_WORLD);

    // dot product of V1 and V2
    if (L2 == 0) {
    float local_sum = dot(V1,V2,L1);
    float global_sum;
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_FLOAT, MPI_SUM, 0,
             MPI_COMM_WORLD);
    if (rank == 0 ){
    printf("The dot product of V1 and V2 is: %f\n", global_sum);
    }
}

    float local_diag = 0.0;
    float** solMat = mult(V3,V1,NL1,L2);
    for (int i=0; i<NL1; i++) {
        local_diag += solMat[i][i+NL1*rank];
    }
    float global_diag = 0.0;
    MPI_Reduce(&local_diag, &global_diag, 1, MPI_FLOAT, MPI_SUM, 0,
        MPI_COMM_WORLD);

    float local_sum = 0.0;
    for (int i=0;i< L1; i++) {
        for (int j=0; j<NL1; j++){
            local_sum += solMat[i][j];
        }
    }
    local_sum -= local_diag;
    float global_sum;
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    if (rank==0){
        printf("The sum of the diagonal of the solution matrix is: %f\n", global_diag);
        printf("The sum of the rest of the elements of the solution matrix is: %f\n", global_sum);
    }

    // free allocated memory
    for (int i = 0; i < L2; i++) {
        free(solMat[i]);
    }

    free(V1);
    free(V2);
    free(V3);
    free(solMat);

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();

}