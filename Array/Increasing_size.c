#include <stdio.h>
#include <stdlib.h>

int main(){

    int *p,*q;

    p=(int *)malloc(5*sizeof(int));
    p[0]=5;p[1]=10;p[2]=15;p[3]=20;p[4]=25;

    q=(int *)malloc(10*sizeof(int));

    for(int i=0; i<5;i++){
        q[i]=p[i];
    }
    free(p);
    p=q;
    q=NULL;

    for(int i=0; i<10;i++){
        printf("%d\n ",p[i]);
    }
}