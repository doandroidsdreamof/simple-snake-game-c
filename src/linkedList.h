#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int x;
    int y;
    struct Node *next;
} Node;


void insertLinkedList(Node **head, int x, int y);
void printLinkedList(Node *node);

#endif

