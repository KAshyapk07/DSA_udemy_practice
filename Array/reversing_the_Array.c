#include <stdio.h>
#include <stdlib.h>


struct Array {
    int A[10];
    int length;
};

void Reverse_with_dup_array(struct Array *arr ){

    int *B;
    int i,j;

    B=(int *)malloc(arr->length*sizeof(int));

    for(i=arr->length-1,j=0;i>=0;i--,j++){
        B[j]= arr->A[i];
    }
    for(i=0;i<arr->length;i++){
        arr->A[i]= B[i];
    }

}

void Reverse2(struct Array *arr){
    int i,j;
    int temp;
    for(i=0,j=arr->length-1;j>=0;i++,j--){
        temp=arr->A[i];
        arr->A[i]=arr->A[j];
        arr->A[j]=temp;
    }
}

void Display(struct Array arr){
    int i;
    printf("\n The elements are \n");
    for(i=0;i<arr.length;i++){
        printf("%d\t ",arr.A[i]);       
    }
}

int main(){
    struct Array arr= {{1,2,3,4,5,6,7,8,9,10},10};
    
    Reverse_with_dup_array(&arr);
    Display(arr);
    Reverse2(&arr);
    Display(arr);
    return 0;
}