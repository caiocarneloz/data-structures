#ifndef NODE_H
#define NODE_H

struct Node
{
    int data;
    Node *next;
};

Node *newNode(int n);

#endif

