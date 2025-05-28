#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[20];
    int length;
};


int LinearSearch(struct Array *arr, int key){
    int i;
    for(i=0;i<arr->length;i++){
        if(arr->A[i]==key){
            return i;
        }
    }
    return -1;    
}

int main(){

    struct Array arr = {{1,2,3,4,5,6,7,8},8} ;
  
   
    int result;

    result = LinearSearch(&arr,8);
    printf("%d\n", result);
}