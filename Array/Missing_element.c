#include <stdio.h>
#include <stdlib.h>

struct Array{
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
void Missing_multiple(struct Array *arr){
    int i,l,h,diff;
   
    l=arr->A[0]-0;
    diff = l-0; 
    h=arr->A[arr->length];

    printf("The Missing elements are ");      //this finds the multiple adjacent missing also and totally 2 missing in entire array ; 
    for(i=0;i<arr->length;i++){
        if(arr->A[i]-i != diff){
            while(diff< arr->A[i]-i){
                printf("%d ",i+diff);
                diff++;
            }
        }
    }
}

int Missing(struct Array *arr)
{
    int l,h,diff;
    l=arr->A[0];
    diff=l-0;
    h=arr->A[arr->length];
    for(int i=0;i<arr->length;i++){
        if(arr->A[i]-i != diff){
            return i+diff;
        }
    }
    return -1;
}
int main(){
    struct Array arr = {{1,2,3,4,5,6,7,8},8};
    struct Array arr2= {{6,7,8,11,12,13,15,16,18,20},10};

    Display(arr);
    int r= Missing(&arr);

    printf("The missing element in arr1 is %d \n",r);
    Missing_multiple(&arr2);
    return 0;
}