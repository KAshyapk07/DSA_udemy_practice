#include <stdio.h>

char* reverse(char *A){
    char B[10];
    int i,j;
    for(i=0;A[i]!='\0';i++){
    }
    i=i-1;
    for(j=0;i>=0;j++,i--){
        B[j]=A[i];
    }
    for(int k=0; A[k]!='\0'; k++){
        A[k]=B[k];
    }
    return A;
} 

int Palindrome(char *A){
    char *B = reverse(A);

    for(int i=0;A[i]!= '\0';i++){
        if(A[i]!=B[i]){
            printf("\nNot a Palindrome");
            return 0;
        }
    }
    printf("\nIS a palindrome");
}

int comparison(char *A,char *B){                                  // to ignore upper/lower cases , convert both arrays to upper/lower 
    int i,j;
    for(i=0,j=0;A[i]!='\0'&& B[j]!='\0';j++,i++){
        if(A[i]!=B[j]){
            break;
        }
    }
    if(A[i]<B[j]){
        printf("A is smaller");
    }
    else if(A[i]>B[j]){
        printf("A is Greater");
        
    }
}


int main(){
    char A[]="Kashyap";
    char B[]="KAshyap";

    char C[] = "madam";
    comparison(A,B);
    Palindrome(C);
    return 0;
}