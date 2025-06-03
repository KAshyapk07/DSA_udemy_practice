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

int max(struct Node *p){
    int max = -1;
    while(p){
        if(p->data > max){
            max = p->data;
        }
        p= p->next;
    }
    return max;
}

int Recursive_max(struct Node *p){
    int x;
    if(p==0){
        return -1;
    }
    x= Recursive_max(p->next);
    if(x>p->data){
        return x;
    }
    else return p->data;
}

int main(){
    int A[]={1,2,33,4,5,6,7,10,15,20};
    create(A,9);

    Display(first);
    printf("max is %d\n",max(first));
    printf("rec_max is %d\n",Recursive_max(first));
    return 0;
}