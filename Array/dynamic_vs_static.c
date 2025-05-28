#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[5]= {1,2,3,4,5};

    int *p;
    int i;

    p=(int *)malloc(5*sizeof(int));
    p[0]=10;
    p[1]=20;
    p[2]=30;
    p[3]=40;
    p[4]=50;

    for(i=0;i<5;i++){
        printf("%d",a[i]);
    }
    printf("\n");
    
    for(i=0;i<5;i++){
        printf("%d",p[i]);
    }
    return 0;
}