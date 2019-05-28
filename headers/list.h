#ifndef LIST_H
#define LIST_H
#include "node.h"

void initList(Node **H);
void *insertList(Node **H, int n);
void *insertionSort(Node **H, int n);
void *removeList(Node **H, int n);
void *killList(Node **H);
void printList(Node *H);


#endif

