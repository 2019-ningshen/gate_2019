#include<stdio.h>
#include<stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
} NODE;



NODE *create(NODE *p) {
    struct NODE* head = NULL;
    struct NODE* second = NULL;
    struct NODE* third = NULL;

    head = (struct NODE *)malloc(sizeof(NODE));
    second = (struct NODE *)malloc(sizeof(NODE));
    third = (struct NODE *)malloc(sizeof(NODE));

    head->data = 1;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 100;
    third->next = NULL;
}

int main() {
    struct NODE* p = (struct NODE *)malloc(sizeof(NODE));
    create(p);
    int i;
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}