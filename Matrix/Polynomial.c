#include <stdio.h>
#include <stdlib.h>

struct Term{
    int coeff;
    int exp;
};

struct Polynomial{
    int n;
    struct Term *t;
};

void create(struct Polynomial *p){
    printf("Enter no of terms:\n");
    scanf("%d", &p->n);
    p->t = (struct Term *)malloc(p->n * sizeof(struct Term));

    printf("Enter each term as: coeff exp\n");
    for(int i = 0; i < p->n; i++){
        scanf("%d %d", &p->t[i].coeff, &p->t[i].exp);
    }
}

void display(struct Polynomial p){
    for (int i = 0; i < p.n; i++) {
        printf("%dx^%d", p.t[i].coeff, p.t[i].exp);
        if (i != p.n - 1)
            printf(" + ");
    }
    printf("\n");
}

struct Polynomial *add(struct Polynomial *p1, struct Polynomial *p2){
    int i = 0, j = 0, k = 0;
    struct Polynomial *sum = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    sum->t = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));

    while(i < p1->n && j < p2->n){
        if(p1->t[i].exp > p2->t[j].exp){
            sum->t[k++] = p1->t[i++];
        }
        else if(p1->t[i].exp < p2->t[j].exp){
            sum->t[k++] = p2->t[j++];
        }
        else {
            sum->t[k].exp = p1->t[i].exp;
            sum->t[k].coeff = p1->t[i].coeff + p2->t[j].coeff;
            i++; j++; k++;
        }
    }

    while(i < p1->n)
        sum->t[k++] = p1->t[i++];
    while(j < p2->n)
        sum->t[k++] = p2->t[j++];

    sum->n = k;
    return sum;
}

int main(){
    struct Polynomial p1, p2;
    printf("Enter Polynomial 1:\n");
    create(&p1);
    printf("Polynomial 1: ");
    display(p1);

    printf("Enter Polynomial 2:\n");
    create(&p2);
    printf("Polynomial 2: ");
    display(p2);

    struct Polynomial *p3 = add(&p1, &p2);
    printf("Sum of Polynomials: ");
    display(*p3);


    free(p1.t);
    free(p2.t);
    free(p3->t);
    free(p3);

    return 0;
}
