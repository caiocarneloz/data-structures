#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

void initQueue(Node **Q);
void enqueue(Node **Q, int data);
Node *dequeue(Node **Q);
void printQueue(Node *Q);

#endif

