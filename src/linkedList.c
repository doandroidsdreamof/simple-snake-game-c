#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void insertLinkedList(Node **head, int x, int y) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  newNode->x = x;
  newNode->y = y;
  newNode->next = *head;
  *head = newNode;
}

void printLinkedList(Node *head) {
  while (head != NULL) {
    printf(" %d linked list node x =>", head->x);
    head = head->next;
  }
}

void pushLinkedList(Node **head) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
   Node *currentNode = *head;

  newNode->x = currentNode->x;
  newNode->y = currentNode->y;
  newNode->next = NULL;


  while (currentNode->next != NULL) {
    currentNode = currentNode->next;
  }
  currentNode->next = newNode;
}

void resetLinkedList(Node *head) {
  Node *currentNode = head;
  while (currentNode != NULL) {
    Node *next = currentNode->next;
    free(currentNode);
    currentNode = next;
  }
}
