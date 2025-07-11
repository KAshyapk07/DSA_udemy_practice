#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;


void Insert(int key){
    struct Node *t = root;
    struct Node *p,*r;

    if(root==NULL){
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL){
        r=t;
        if(key<t->data){
            t=t->lchild;
        }
        else if(key>t->data){
            t=t->rchild;
        }
        else{
            printf("Element already exists\n");
            return;
        }
    }
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;

    if(key < r->data){
        r->lchild = p;
    }
    else{
        r->rchild = p;
    }
}
void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

struct Node * search(int key){
    struct Node *t=root;

    while(t!=NULL){
        if(key == t->data){
            return t;
        }
        else if(key<t->data){
            t=t->lchild;
        }
        else{
            t=t->rchild;
        }
    }
    return NULL;
}

int main(){
    struct Node *temp;
    int key=8;
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);

    Inorder(root);
    printf("\n");
    temp=search(key);

    if(temp!=NULL){
        printf("The element %d is found\n",temp->data);
    }
    else{
        printf("The Element %d is not found\n",key);
    }
    return 0;
}