#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    struct Node *next;
}*top=NULL;



void push(char x){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(top == NULL){
        top= t;
    }
    else{
        t->next = top;
        top = t;
    }
}

char pop(){
    char x=-1;
    struct Node *t;
    if(top==NULL){
        printf("The stack is empty \n");
    }
    else{
        t=top;
        top = top->next;
        x=t->data;
        t->next=NULL;
        free(t);
    }
    return x;
}

void Display(){
    struct Node *p;
    p=top;
    while(p!=NULL){
        printf("|_____%d_____|\n",p->data);
        p=p->next;  
    }
}



int isBalanced(char *exp){
    int i;
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(exp[i]);
        }
        else if(exp[i]==')'){
            if(top==NULL){
                return 0;
            }
            pop();
        }
    }
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char *exp = "((a+b)*(c+d)";

    printf("%d",isBalanced(exp));
    return 0;
}