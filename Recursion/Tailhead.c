#include <stdio.h>

//function takes parameter n and prints all the numbers recursively until 0
void fun(int n){

    if(n>0){
        printf("%d ",n);
        fun(n-1);   //for head recurssion call the fun function before the print statement
        
    }
}
int main(){
    int x;
    printf("Enter a number\n");
    scanf("%d",&x);
    fun(x);
    return 0;
}