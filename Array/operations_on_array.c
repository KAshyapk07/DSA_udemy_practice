#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *A;
    int size;
    int length;
};


void Display(struct Array arr){
    int i;
    printf("\n The elements are \n");
    for(i=0;i<arr.length;i++){
        printf("%d\t ",arr.A[i]);       
    }
}

void Append(struct Array *arr , int x){
    if(arr->length<arr->size){
        arr->A[arr->length++]= x;
    }   
}

void Insert(struct Array *arr, int index , int x){
    if(index>=0 && index <= arr->length ){
        for(int i=arr->length;i>index;i--){
                arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }

}

int Delete(struct Array *arr , int index){
    int x=0;
    if( index>=0 && index<= arr->length){
        x=arr->A[index];
        for(int i = index ; i< arr->length-1; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length-- ;
        return x;
    }

    return 0;
}

int main(){
    int n,i;
    struct Array arr;     //initialisation
    printf("Enter the size of array \n");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size * sizeof(int));
    arr.length=0;
    
    printf("Enter the number of numbers in the array \n");
    scanf("%d",&n);

    printf("Enter all elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr.A[i]);   
    }
    arr.length=n;
    
    Display(arr);
    Insert(&arr, 4,100);
    Display(arr);
    Append(&arr , 10);
    Display(arr);
    int del= Delete(&arr, 4);
    Display(arr);

   
}