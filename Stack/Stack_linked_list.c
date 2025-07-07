#include <stdio.h>
#include <stdlib.h>

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

int main(){
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);

    Display();

    printf("The Popped ele is %d\n",pop());

    Display();
}