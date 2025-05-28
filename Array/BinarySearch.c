#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[20];
    int length;
};

int BinarySearch_iterative(struct Array *arr,int key){
    int l=0,h = arr->length-1;
    while(l<=h){
        int mid= (l+h)/2;
        if(arr->A[mid]==key){
            return mid;
        }
        else if(arr->A[mid]<key){
            l= mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return -1; 
}

int binarysearch_recursive(struct Array *arr , int l, int h,int key){

    if(l<=h){
       int mid = (l+h)/2;
        if (arr->A[mid]==key){
            return mid;
        }
        else if(arr->A[mid]<key){
            return binarysearch_recursive(arr,l=mid+1,h,key);
        }
        else{
            return binarysearch_recursive(arr,l,h=mid-1,key);
        }

    }
}

int main(){
    struct Array arr= {{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},20};
     
    int res = BinarySearch_iterative(&arr, 18);
    int res2 = binarysearch_recursive(&arr,0, arr.length-1, 18);
    printf("%d\n", res);
    printf("%d\n", res2);
    return 0;
}