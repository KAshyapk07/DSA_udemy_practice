#include <stdio.h>

void Permutation(char s[],int k){
    static int A[10] = {0};
    static char Res[10]; 
    int i;
    if(s[k]=='\0'){
        Res[k]='\0';
        printf("%s\n",Res);
    }
    else{
    for(i=0;s[i]!='\0';i++){
        if(A[i]==0){
            Res[k]= s[i];
            A[i]=1;
            Permutation(s,k+1);
            A[i]=0;
            }
        }
    }
}


int main(){
    char s[]= "ABCD";
    Permutation(s,0);

    return 0;

}