#include <stdlib.h>
#include "../headers/tnode.h"

TNode *newTNode(int n)
{
    TNode *node = (TNode*)malloc(sizeof(TNode));
    node->data = n;
    node->lef = NULL;
    node->rig = NULL;
    node->bal = 0;
    
    return node;
}