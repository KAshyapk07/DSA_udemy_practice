#include <stdio.h>

int Word(char *A){
    int i ,word=1;
    for(i=0;A[i]!='\0';i++){
        if(A[i]==' ' && A[i-1]!= ' '){
            word++;
        }
    }
    printf("The no of words are %d\n",word);
}

int Count(char *A){
    int i,vow=0,cons=0;
    for(i=0;A[i]!='\0';i++){
        if(A[i]=='a' || A[i]=='e' || A[i]=='i' || A[i]=='o' || A[i]=='u' || A[i]=='A'|| A[i]=='E' || A[i]=='I' || A[i]=='O' || A[i]=='U'){
            vow++;
        }
        else if((A[i]>=65 &&A[i]<=90)||(A[i]>=97 && A[i]<=122)){
            cons++;
        }
    }
    printf("The no of vowels and constanants are %d , %d\n",vow,cons);
}

int main(){
    char A[20];
    printf("Enter the string");
    scanf(" %[^\n]",A);    // can also go with gets();
    
    Count(A);
    Word(A);

    return 0;
}