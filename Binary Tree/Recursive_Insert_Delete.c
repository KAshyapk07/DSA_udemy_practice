#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

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

struct Node * RecInsert(struct Node *p,int key)
{   
    struct Node *t;

    if(p==NULL){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data)
    {
        p->lchild=RecInsert(p->lchild,key);
    }
    else if(key > p->data)
    {
        p->rchild = RecInsert(p->rchild,key);
    }
    return p;
}

int Height(struct Node *p){
    int x,y;
    if(p==NULL){
        return 0;
    }
    else{
        x=Height(p->lchild);
        y=Height(p->rchild);
        return x>y?x+1:y+1;
    }
}

struct Node * Inpre(struct Node *p){
    while(p && p->rchild!=NULL){
        p=p->rchild;
    }
    return p;
}


struct Node * InSucc(struct Node *p){
    while(p && p->lchild!=NULL){
        p=p->lchild;
    }
    return p;
}
struct Node * Delete(struct Node *p,int key ){
    struct Node*q;

    if(p==NULL){
        return NULL;
    }
    if(p->lchild ==NULL && p->rchild == NULL){
        if(p==root){
            root=NULL;
        }
        free(p);
        return NULL;
    }


    if(key<p->data){
        p->lchild=Delete(p->lchild,key);
    }
    else if(key > p->data){
        p->rchild = Delete(p->rchild,key);
    }
    else{
        if(Height(p->lchild)>Height(p->rchild)){
            q=Inpre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else{
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

int main(){
    struct Node *temp;
    int key=8;
    root=RecInsert(root,10);
    RecInsert(root,5);
    RecInsert(root,20);
    RecInsert(root,8);
    RecInsert(root,30);

    Delete(root,20);
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