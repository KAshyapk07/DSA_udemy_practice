#include<stdio.h>

void FunA(int n);
void FunB(int n);

void FunA(int n){

    if (n>0){
        printf("%d \n",n);
        FunB(n-1);
    }
}

void FunB(int n){

    if(n>0){
        printf("%d \n" , n);
        FunA(n/2);
    }
}

int main(){
    FunA(20);

    return(0);
}