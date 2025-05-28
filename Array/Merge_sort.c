#include <stdio.h>
#include <stdlib.h>


struct Array {
    int A[20];
    int length;
};


void Display(struct Array arr){
    int i;
    printf("\n The elements are \n");
    for(i=0;i<arr.length;i++){
        printf("%d\t ",arr.A[i]);       
    }
}

struct Array * merge(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 =(struct Array *)malloc(sizeof(struct Array ));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }
        else{
            arr3->A[k++]=arr2->A[j++];
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k++]= arr1->A[i];
    }
    for(;j<arr2->length; j++){
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = arr1->length + arr2->length ; 
    return arr3;
}

int main(){
    struct Array arr1 = {{1,5,8,11,13,17,20},7};
    struct Array arr2 = {{2,4,7,9,12,14,15,19},8};
    struct Array *arr3;

    arr3 = merge(&arr1,&arr2);
    
    Display(*arr3);
    return 0;
}