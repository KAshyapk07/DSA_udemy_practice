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
void insert_first(struct Node *p,int x){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = p;
    p= temp;
   
}

void insert_between(struct Node *p, int x,int pos){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    if(pos==0){
        insert_first(&first,x);
    }
    for(int i=0 ; i<pos-1 ; i++){
        p=p->next;
    }
    if(p){
        temp->next = p->next;
        p->next = temp;
    }

}   


int main(){
    int A[]={1,2,3,4,5,6,7};
    create(A,6);

    printf("Before insertion\n");
    Display(first);
    
    printf("after insertion of 10 at first\n");
    insert_first(&first,10);
    Display(first);
    
    
    printf("after insertion of 15 at pos 5\n");
    insert_between(first,10,5);
    Display(first);
    
    return 0;
}