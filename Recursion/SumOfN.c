#include <stdio.h>

int Sum(int n){      //recursive sum
    if(n==0){
        return 0;
    }
    else{
        return Sum(n-1) + n ;
    }
}

int Isum(int n){
    int s=0;
    int i;
    for(i=1; i<=n; i++){
        s=s+i;
    }
    return s;
}

int main(){
    int r;
    r= Isum(5);
    printf("%d",r);
    return 0;   
}

