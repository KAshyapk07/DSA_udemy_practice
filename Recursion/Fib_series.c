#include <stdio.h>

int fib_loop(int n){         //iterative
    int t0=0,t1=1,s=0,i;
    
    if (n<=1){
        return n;
    }
    else{
    for(i=2;i<=n;i++){

        s=t0+t1;
        t0=t1;
        t1=s;

    }
    return s;
    }
}

int recursive_fib(int n){    //recursive
    if(n<=1){
        return n;
    }
    else{
        return recursive_fib(n-2)+recursive_fib(n-1);
    }
}

int F[10];

int memoization_fib(int n){

    if(n<=1){
        F[n]=n;
        return n;
    }
    else{
        if(F[n-2]==-1){
            F[n-2]=memoization_fib(n-2);
        }
        if(F[n-1]==-1){
            F[n-1]=memoization_fib(n-1);
        }
        F[n]=F[n-1]+F[n-2]; 
        return F[n-2]+F[n-1];
    }
}

int main(){
    for(int i=0; i<10;i++){
        F[i]=-1;
    }

    printf("%d \n",fib_loop(11));
    printf("%d \n",recursive_fib(10));
    printf("%d \n",memoization_fib(9));
    return  0;
}