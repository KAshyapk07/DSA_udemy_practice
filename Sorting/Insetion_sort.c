#include <stdio.h>

void InsertionSort(int A[],int n){
    int i,j;
    for(i=1;i<n;i++){
        j=i-1;
        int x= A[i];
        while(j>-1 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }

}

int main(){

    int A[]= {3,11,17,15,7,4,1,8,20,2},n=10;
    
    InsertionSort(A,n);
    for(int i=0; i<n;i++){
        printf(" %d ",A[i]);
    }
    
    return 0;
}