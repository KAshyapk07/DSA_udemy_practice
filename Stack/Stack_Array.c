#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int Top;
    int *A;
};

void create(struct stack *st){
    printf("Enter The Size\n");
    scanf("%d",&st->size);
    st->Top = -1;
    st->A=(int *)malloc(st->size*sizeof(int));
}

void Dispaly(struct stack *st){
    for(int i=st->Top;i>=0;i--){
        printf("%d\n",st->A[i]);
    }
    printf("\n");
}

void push(struct stack *st,int x){
    if(st->Top == st->size-1){
        printf("Stack Overflow\n");
    }
    else{
        st->Top++;
        st->A[st->Top] = x;
    }
}

int pop(struct stack *St){
    int popped;
    if(St->Top == -1){
        printf("Stack Underflow");
    }
    else{
        popped = St->A[St->Top];
        St->Top--;
    }
    return popped;
}

int main(){
    struct stack st;
    create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);

    Dispaly(&st);
    
    int a = pop(&st);
    printf("The deleted element is %d\n",a);
    Dispaly(&st);
    
}