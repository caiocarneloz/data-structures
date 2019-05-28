#include "../headers/node.h"
#include <stdlib.h>

Node *newNode(int n)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = n;
    node->next = NULL;
    
    return node;
}