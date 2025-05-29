#include <stdio.h>
#include <stdio.h>

int Toggle(char *A){
    int i;
    
    for(i=0;A[i]!='\0';i++){
        if(A[i]>= 65 && A[i]<= 90){
            A[i]=A[i] + 32 ;
        }
        else if(A[i]> 97 && A[i]<=122){
            A[i]=A[i] - 32 ; 
        }
    }
  
}

int upper_to_lower(char *A){
    int i;
    
    for(i=0;A[i]!='\0';i++){
        A[i] += 32 ; 
    }
  
}

int main(){
    
    char A[20];
    char B[20];
    printf("Enter all capital string \n");
    scanf("%s",A);
     upper_to_lower(A);
    printf("%s\n",A);
    
    
    printf("Enter a mixed string \n");
    scanf("%s",B);
     Toggle(B);
    printf("%s\n",B);
    return 0;
}