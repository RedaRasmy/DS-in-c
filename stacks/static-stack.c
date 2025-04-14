#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef int Element;

typedef struct {
    int top ;
    Element elements[MAX];
} Stack;


void Init_Stack(Stack *S) {
    S->top = -1;
}

void pop(Stack *S) {
    if (S->top == -1) {
        printf("Error : Stack is empty\n");
    } else {
        S->top--;
    }
}

void push(Stack *S, Element elm) {
    if (isFull(*S)) {
        printf("Error : Stack is full\n");
    } else {
        S->top++;
        S->elements[S->top] = elm;
    }
}

int isFull(Stack S) {
    if (S.top == MAX - 1) {
        return 1;
    } else {
        return 0;
    }
}
int isEmpty(Stack S) {
    if (S.top == -1 ){
        return 1;
    } else {
        return 0;
    }
}

Element peek(Stack S) {
    if (isEmpty(S)) {
        printf("Impossible : Stack is empty\n");
        return -1;
    } else {
        return S.elements[S.top];
    }
}





