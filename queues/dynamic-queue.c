#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val ;
    struct Node *next ;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} DQueue;

void Init_Queue(DQueue *Q) {
    Q->head = NULL;
    Q->tail = NULL;
}

int isEmpty(DQueue *Q) {
    return (Q->head == NULL);
}

void enqueue(DQueue *Q , int value) {
    Node *new = (Node *)malloc(sizeof(Node));

    if (new == NULL) {
        printf("Memory Allocation Error");
        return;
    }

    new->val = value;
    new->next = NULL;

    if (isEmpty(Q)) {
        Q->head = Q->tail = new;
    } else {
        Q->tail->next = new;
        Q->tail = new;
    }
}

void dequeue(DQueue *Q) {
    if (isEmpty(Q)) {
        printf("Dynamic Queue is empty");
        return;
    }
    Node *temp = Q->head;
    Q->head = Q->head->next;

    if (Q->head == NULL) { 
        // if the queue is emtpy we should re-init
        Q->tail = NULL;
    }

    free(temp);
} 