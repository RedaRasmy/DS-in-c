#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    struct Node *next;
} Node;

Node *head = NULL;

Node *createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    newNode->val = value;
    newNode->next = NULL;

    return newNode;
}

void insertAtHead(int value) {
    Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(int value) {
    Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void insertAt(int value , int index) {
    if (index == 0) {
        insertAtHead(value);
        return;
    }

    Node *newNode = createNode(value);
    Node *current = head;

    for (int i =0 ; (i<index-1 && current != NULL ); i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid Position\n");
        free(newNode);
        return;
    }
    Node *next = current->next;
    
    if (next == NULL) {
        current->next = newNode;
        return;
    }

    current->next = newNode;
    newNode->next = next;
}