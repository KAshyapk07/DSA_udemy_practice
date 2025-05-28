#include <stdio.h>
#include <stdlib.h>

int main(){    //creating 2d array
      
    int A[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};   //method 1
 
    int *B[3];           //stack                     //method 2: array of pointers pointing to arrays
    B[0]=(int *)malloc(4*sizeof(int)); 
    B[1]=(int *)malloc(4*sizeof(int)); //heap
    B[2]=(int *)malloc(4*sizeof(int));

    int **C;   //method 3: double pointer array

    C=(int **)malloc(3*sizeof(int *)); //heap
    C[0]=(int *)malloc(4*sizeof(int));//heap
    C[1]=(int *)malloc(4*sizeof(int));
    C[2]=(int *)malloc(4*sizeof(int));
}