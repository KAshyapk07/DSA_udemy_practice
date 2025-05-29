//for password or etc

#include <stdio.h>

int valid1(char *A){
    for(int i=0; A[i] != '\0';i++){
        if(!(A[i]>=65 && A[i]<=90) &&       //not cap letters
            !(A[i]>=97 && A[i]<=122)&&      //not small letters
            !(A[i]>=48 && A[i]<=58)         //not numbers
             &&(A[i]!=' ')  ){               //no space    
                return 0;
        }
    }
    return 1;

}


int main(){
    char A[20];
    
    printf("Enter String Within 20 characters\n");
    scanf("%s",A);
    
    if(valid1(A)){
        printf("Valid String\n");
    }
    else{
         printf("inValid String\n");
    }

    return 0;
}