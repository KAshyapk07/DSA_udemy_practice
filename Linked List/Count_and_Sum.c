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
int Count(struct Node *p){
    int n;
    while(p!=NULL){
        n=n+1;
        p=p->next;
    }
    return n;
}

int sum(struct Node *p){
    int sum=0;
    while(p!=NULL){
        sum = sum+p->data;
        p=p->next;
    }
    return sum;
}

int Sum_recursion(struct Node *p){
    if(p==0){
        return 0 ;
    }
    else{
        return Sum_recursion(p->next)+p->data;
    }
}

int main(){
    int a,b,c,d;
    int A[]={1,2,3,4,5,6,7};
    create(A,6);

    Display(first);
    a=Count(first);
    b=sum(first);
    c=Sum_recursion(first);
    

    printf("The Count is %d\n",a);
    printf("The Sum  is %d\n",b);
    printf("The Recursive sum is %d\n",c);
    return 0;
}