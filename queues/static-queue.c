#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int elements[MAX];
    int head ;
    int tail ;
} Queue;

void Init_Queue(Queue *Q) {
    Q->head = 1;
    Q->tail = 0;
}

int isEmpty(Queue *Q) {
    return (Q->head > Q->tail);
}

int isFull(Queue *Q) {
    return (Q->tail == MAX );
}

void enqueue(Queue *Q , int value) {
    if (isFull(Q)) {
        printf("Queue is full! \n");
        return;
    }
    if (isEmpty(Q)) {
        Q->head = 0;
    }

    Q->elements[Q->tail] = value;
    Q->tail++;
}

void dequeue(Queue *Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty! \n");
        return;
    }
    
    Q->head++;

    if (Q->head > Q->tail) {
        Init_Queue(Q);
    }
}