#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild; 
}Node;

struct Queue{
    int size;
    int front;
    int rear;
    Node **Q;
};

void Create(struct Queue *q,int size){
    q->size= size;
    q->front = q->rear =0;
    q->Q = (Node **)malloc(q->size*sizeof(Node *));
}

void Enqueue(struct Queue *q,Node *x){
    if((q->rear+1)%q->size == q->front){
        printf("Queue is full\n");
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]= x;
    }
}

Node *Dequeue(struct Queue *q) {
    Node * x = NULL;
    if (q->front == q->rear) {
        printf("Queue is empty\n");
    } else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue *p){
    return p->front == p->rear;
}

