#include <stdio.h>



void Bubble(int A[],int n){
    int i,j;
    int temp;
    for(i=0;i< n-1;i++){
        int flag=0;
        for(j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;   
            }
        }
        if(flag==0){
            printf("The List is already sorted\n");
            break;
        }
    }
}

int main(){

    int A[]= {3,7,8,9},n=4;
    
    Bubble(A,n);
    for(int i=0; i<n;i++){
        printf(" %d ",A[i]);
    }
    
    return 0;
}