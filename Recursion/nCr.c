//nCr = n! / (r! *(n-r)!) //

#include <stdio.h>

int fact(int n){

    if(n<=1){
        return 1;
    }
    else{
        return fact(n-1)*n;
    }
}


int nCr_formula(int n ,int r){
    int num, den;

    num= fact(n);
    den=fact(r)*fact(n-r);

    return num/den;
}

int nCr_recursive(int n, int r){
    if(n==r || r==0){
        return 1;
    }
    else{
        return nCr_recursive(n-1,r-1)+nCr_recursive(n-1,r);
    }
}

int main(){
    printf("%d \n", nCr_formula(5,3));
    printf("%d \n", nCr_recursive(5,3));
    return 0;
}