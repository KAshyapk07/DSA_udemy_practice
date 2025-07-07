#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char * infix_to_postfix(char *infix){
    int i=0,j=0;    
    char *postfix;
    int len = strlen(infix);
    postfix= (char *)malloc((len+2)*sizeof(char));

    while(infix[i]!='\0'){
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else{
            if(precedence(infix[i])>precedence(top->data)){
                push(infix[i++]);
            }
            else{
                postfix[j++]=pop();
            }
        }
    }
    while(top!=NULL){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    char *infix = "a+b*c+d";
    push('#');  //to avoid error at top->data if top is null;


    char *postfix=infix_to_postfix(infix);
    printf("%s ",postfix);
}
