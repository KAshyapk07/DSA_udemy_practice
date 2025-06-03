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

struct Node * search(struct Node* p,int key){
    while(p){
        if(p->data == key){
            return p;
        }
        else{
            return NULL;
        }
    }
}

struct Node * Rec_Search(struct Node *p,int key){
    if(p->data == key){
        return p;
    }
    if(p == NULL){
        return NULL;
    }
    else return Rec_Search(p->next,key);
}

int main(){
    int A[]={1,2,3,4,5,6,7};
    struct Node *temp1,*temp2;
    create(A,6);

    temp1 = search(first,11);
    if(temp1){
        printf("The key is present \n");
    }
    else{
        printf("The key is not present \n");
    }
    
    temp2 = Rec_Search(first,5);
    if(temp2){
        printf("The key is present \n");
    }
    else{
        printf("The key is not present \n");
    }
    

    Display(first);

    return 0;
}