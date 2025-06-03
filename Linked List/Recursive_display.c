#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
}*first;

void create(int A[],int n){
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first ->next = NULL;
    last=first;
    
    for(int i=1; i<=n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next = t;
        last=t;
    }
}

void Display(struct Node *first){

    while(first!=NULL){
        printf("%d\n", first->data);
        first=first->next; 
    }
}

void Rec_Display(struct Node *p){
    if(p!= NULL){
        printf("%d->",p->data);
        Rec_Display(p->next);
    }
}


int main(){
    int A[]={1,2,3,4,5,6,7};
    create(A,6);

    Rec_Display(first);
    return 0;
}