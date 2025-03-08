//
// cs4900
// Project 04a
// Hannah Wysong
// w194hxw
// Due 27 Feb 2024, accepted up to Feb 28 10pm
// System = fry
// Compiler syntax = ./compile.sh proj04a
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

float** mult(float **V3, float *V1, int L1, int L2) {
    float sum;
    // solution matrix
    float **solMat = (float **)malloc(L2 * sizeof(float *));                                                                                                        
    for (int i=0; i<L2; i++) {                         
        solMat[i][0] = (float *)malloc(L1 * sizeof(float));     
    }
  for (int i = 0; i < L2; i++) {
    for (int j = 0; j < L1; j++) {
      solMat[i][j]=V3[i][0]*V1[j]; 
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
    float **V3 = (float **)malloc(L2 * sizeof(float *));                                                                                                        
    for (int i=0; i<L2; i++) {                         
        V3[i] = (float *)malloc(1 * sizeof(float));     
    }
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
    for (int i = 0; i < L1; i++) {
        Xi=(dx/2.0+i)*dx;
        V1[i]=norm1*cos(A*Xi+a);
        V2[i]=norm1*sin(B*Xi+b);
    }
    for (int i = 0; i < L2; i++) {
        Yi=(dy/2.0+i)*dy;
        V3[i][0]=norm2*cos(B*Yi+b);
        //printf("Yi = %f\n", Yi);
    }

    //printV(V1, L1);
    //printV(V2, L1);

    // dot product of V1 and V2
    float dotProd = dot(V1,V2,L1);
    printf("The dot product of V1 and V2 is: %f\n", dotProd);

    //printf("Elements of the V3 matrix:\n");
    //for (int i = 0; i < L2; i++) {
        //printf("%f\n", V3[i][0]); // Print the single column of V3
    //}

    // vector multiply V3 by V1
    float** solMat = mult(V3,V1,L1,L2);

    printf("The solution matrix of (V3)^T by V1:\n");
    for (int i = 0; i < L2; i++) {
        for (int j = 0; j < L1; j++) {
            printf("%f ", solMat[i][j]); // print row
        }
        printf("\n"); // switch next column
    }

    // free allocated memory
    for (int i = 0; i < L2; i++) {
        free(V3[i]);
        free(solMat[i]);
    }

    free(V1);
    free(V2);
    free(V3);
    free(solMat);

}