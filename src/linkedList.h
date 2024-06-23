#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int x;
    int y;
    struct Node *next;
} Node;


void insertLinkedList(Node **head, int x, int y);
void pushLinkedList(Node **head);
void printLinkedList(Node *node);
void resetLinkedList(Node *node);
                            

#endif

