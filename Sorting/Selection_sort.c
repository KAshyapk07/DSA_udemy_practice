#include <stdio.h>

void SelectionSort(int A[],int n){
    int i,j,k;
    int temp=0;
    for(i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(A[j]<A[k]){
                k=j;
            }
            temp=A[i];
            A[i]=A[k];
            A[k]=temp;
        }
       
    }

}

int main(){

    int A[]= {4,3,2,1},n=4;
    
    SelectionSort(A,n);
    for(int i=0; i<n;i++){
        printf(" %d ",A[i]);
    }
    
    return 0;
}