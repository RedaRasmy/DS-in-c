#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val ;
    struct Node *next;
} Node;

typedef struct {
    Node *top ;
} DynamicStack;

void Init_DynamicStack(DynamicStack *S) {
    S->top = NULL;
}

int isEmpty(DynamicStack *S) {
    return (S->top == NULL);
}



void push(DynamicStack *S, int val ) {
    Node *new = (Node *)malloc(sizeof(Node));

    if (new == NULL){
        printf("Memory Error");
        return;
    }

    new->val = val;
    new->next = S->top;
    S->top = new;
}

void pop(DynamicStack *S) {
    if (isEmpty(S)) {
        printf("Stack is Empty");
        return;
    } 

    Node *temp = S->top;
    S->top = S->top->next;
    free(temp);
}

int peek(DynamicStack *S) {
    if (isEmpty(S)) {
        printf("Stack is empty\n");
        return -1;
    }
    return S->top->val;
}

void printStack(DynamicStack *S) {
    if (isEmpty(S)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack content : ");
    Node *temp = S->top;
    
    while (temp != NULL) {
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf("\n");
}