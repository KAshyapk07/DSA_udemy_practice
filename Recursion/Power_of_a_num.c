#include <stdio.h>

int power1(int n , int m){
    if (m==0){
        return 1;
    }
    else{
        return power1(n,m-1)*n;
    }
}

int power2(int n , int m){
    if(n==0){
        return 1;
    }
    else if(n%2==0){
        return power2(n*n, m/2);
    }
    else{
        return  n*power2(n*n,(m-1)/2);
    }
}

int main(){
    int k,r;
    k=power1(2,9);
    r= power2(3,4);
    printf("%d", k);
    printf("%d",r);
    return 0;
}