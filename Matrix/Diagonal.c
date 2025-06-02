#include <stdio.h>

void set(char A[],int i,int j,int x){
    if(i==j){
        A[i-1]=x;
    }
}

int get(char A[],int i,int j,int x){
    if(i==j){
        x= A[i-1];
    }
    return x;
}

void display(char A[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
            printf(" %d ",A[i]);
            }
            else{
                printf(" 0 ");
            }
            
        }
        printf("\n");

    }
}

int main(){
    int x=0;
    char A[] = {0};
    set(A,1,1,10);
    set(A,2,2,20);
    set(A,3,3,30);
    set(A,4,4,40);

    printf("%d\n",get(A,2,2,x));
    display(A,4);

}