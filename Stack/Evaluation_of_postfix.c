#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node *next;
}*top=NULL;



void push(int x){
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

int pop(){
    int x=-1;
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



int precedence(char x){
    if(x == '+'|| x=='-'){
        return 1;
    }
    else if(x=='*'||x=='/'){
        return 2;
    }
    return 0;
}

int isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'){
        return 0;
    }
    else 
        return 1;
}

int Eval(char *postfix){
    int i=0;
    int x1,x2,r;

    for(i=0;postfix[i]!='\0';i++){
        if(isOperand(postfix[i])){
            push(postfix[i]-'0');
        }
        else{
            x2=pop();
            x1=pop();
            switch(postfix[i]){
                case '+': r= x1 + x2; 
                            break;
                case '-': r = x1-x2 ;
                            break;
                
                case '*': r = x1*x2 ; 
                             break;
                case '/': r = x1/x2 ; 
                            break;
            }
            push(r);
        }
    }
    return top->data;

}

int main(){
    char *postfix = "234*+82/-";

    printf("The result is %d",Eval(postfix));
    return 0;
}
