#include <stdio.h>

int Length(char *A){
    int res=0;
    for(int i =0;A[i]!='\0';i++){
        res++;
    }
    return res;
}

int main(){
    
    char A[]= "Iamkashyap";
    int i ;
    i = Length(A);

    printf("The Length of A is %d",i);
    return 0;
}