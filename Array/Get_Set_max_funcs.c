#include <stdio.h>
#include <stdlib.h>


struct Array {
    int A[9];
    int length;
};

void Display(struct Array arr){
    int i;
    printf("\n The elements are \n");
    for(i=0;i<arr.length;i++){
        printf("%d\t ",arr.A[i]);       
    }
}

int Get(struct Array arr, int index){
    if(index>=0 && index <= arr.length){
        return arr.A[index];
    }
    return -1;
}

int Set(struct Array *arr, int index,int x){
    if(index >=0 && index <=arr->length){
        arr->A[index] = x;
    }
}

int Max(struct Array arr){
    int max,i;
    max=arr.A[0];
    for(i=0;i<arr.length;i++){
        if(arr.A[i]>max){
            max = arr.A[i];
        }
    }
    return max;

}

int Min(struct Array arr){
    int min,i;
    min = arr.A[0];
    for(i=0;i<arr.length;i++){
        if(arr.A[i]<min){
            min = arr.A[i];
        }
    }
    return min;
}

int main(){
    struct Array arr= {{1,2,3,4,5,6,7,8,9},9};
    
    printf("Get %d\n", Get(arr,5));
    Set(&arr,4,50);
    Display(arr);
    printf("The max element is %d\n", Max(arr));
  
    printf("The min element is %d\n",Min(arr));
    
    
    return 0;
}