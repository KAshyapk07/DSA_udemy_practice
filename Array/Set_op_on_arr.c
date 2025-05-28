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

struct Array * Union(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 =(struct Array *)malloc(sizeof(struct Array ));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j] < arr1->A[i]){
            arr3->A[k++]=arr2->A[j++];
        }
        else{
            arr3->A[k++]= arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k++]= arr1->A[i];
    }
    for(;j<arr2->length; j++){
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k ; 
    return arr3;
}

struct Array * Intersection(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 =(struct Array *)malloc(sizeof(struct Array ));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            i++;
        }
        else if(arr2->A[j] < arr1->A[i]){
           j++;
        }
        else{
            arr3->A[k++]= arr1->A[i++];
            j++;
        }
    }
    arr3->length = k ; 
    return arr3;
}
struct Array * Difference(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 =(struct Array *)malloc(sizeof(struct Array ));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr2->A[j] < arr1->A[i]){
            j++;
        }
        else{
           i++;
            j++;
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k++]= arr1->A[i];
    }

    arr3->length = k ; 
    return arr3;
}

int main(){
    struct Array arr1 = {{2,6,10,11,15,25,20},7};
    struct Array arr2 = {{2,4,6,11,12,15,19},7};
    struct Array *arr3;


    arr3 = Union(&arr1,&arr2);
    Display(*arr3);
    
    arr3= Intersection(&arr1,&arr2);
    Display(*arr3);
    
    arr3= Difference(&arr1,&arr2);
    Display(*arr3);
    
    return 0;
}