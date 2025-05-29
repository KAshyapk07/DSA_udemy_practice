#include <stdio.h>



int reverse2(char *A){
    int i, j;
    char temp;
    for(j=0;A[j]!='\0';j++){
    }
    j=j-1;
    while(i<j){
        temp = A[i];
        A[i] = A[j];
        A[j]= temp;
    }
    printf("The 2nd way  Reversed String is %s\n",A);
}

int reverse(char *A){
    char B[10];
    int i,j;
    for(i=0;A[i]!='\0';i++){
    }
    i=i-1;
    for(j=0;i>=0;j++,i--){
        B[j]=A[i];
    }
    printf("The Reversed String is %s\n",B);
} 

int main(){
    char A[10];
    
    printf("Enter String Within 10 characters\n");
    scanf("%s",A);
    
    reverse(A);
    reverse2(A);
    return 0;
}