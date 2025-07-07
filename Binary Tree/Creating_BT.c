#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


struct Node *root=NULL;

void Treecreate(){
    struct Node *p,*t;
    int x;
    struct Queue q;
    Create(&q,100);
    printf("enter Root Value \n");
    scanf("%d",&x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild=root->rchild=NULL;

    Enqueue(&q,root);

    while(!isEmpty(&q)){
        p=Dequeue(&q);
        printf("enter left Child value of %d\n",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            Enqueue(&q,t);
             
        }
        printf("Enter Right Child value of %d\n",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            Enqueue(&q,t);
             
        }
    }
}

void Preordertraversal(struct Node *p){
    if(p){
        printf("%d ",p->data);
        Preordertraversal(p->lchild);
        Preordertraversal(p->rchild);
    }

}


void Inordertraversal(struct Node *p){
    if(p){
        Inordertraversal(p->lchild);
        printf("%d ",p->data);
        Inordertraversal(p->rchild);
    }

}

void Postordertraversal(struct Node *p){
    if(p){
        Postordertraversal(p->lchild);
        Postordertraversal(p->rchild);
        printf("%d ",p->data);
    }

}


int main(){
    Treecreate();
    printf("\nThe preorder Traversal is\n");
    Preordertraversal(root);

    printf("\nThe INorder Traversal is\n");
    Inordertraversal(root);
    printf("\nThe postorder Traversal is\n");
    Postordertraversal(root);
    return 0;
}