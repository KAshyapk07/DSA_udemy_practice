//taylor series ---- e^x = 1+ x/1! + x^2/2! .........x^n/n! //

#include <stdio.h>

double e(int x, int n){
    static double f=1, p=1;
    double r;

    if(n==0){
        return 1;
    }
    else{
        r = e(x,n-1);
        f=f*x;
        p=p*n;
        return r+p/f;
    }

}

int main(){
    double a;
    a=e(5,6);
    printf("%lf \n",a);
    return 0;
}