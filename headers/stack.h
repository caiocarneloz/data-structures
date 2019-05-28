#ifndef STACK_H
#define STACK_H
#include "node.h"

void initStack(Node **S);
void push(Node **S, int data);
Node *pop(Node **S);
void printStack(Node *S);

#endif

