#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void Enqueue(int x){
    
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        printf("Queue is Full\n");     //in ll no certain conditionb can say if queue is full(unliited size) but if heap is full then new node wont be created , it can be said as FULL

    }
    else{
        t->data= x;
        t->next = NULL;
        if(front==NULL){
            front=rear=t;
        }
        else{
            rear->next = t;
            rear=t;
        }
    }
}

int Dequeue(){
    int x=-1;
    struct Node *t;
    if(front==NULL){
        printf("Queue is empty\n");
    }
    else{
        x=front->data;
        t=front;
        front = front->next;
        free(t);
    }
    return x;
}

void Display(){
    struct Node *p=front;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);
    Enqueue(60);

    Display();
    printf("%d \n",Dequeue());
    Display();
}