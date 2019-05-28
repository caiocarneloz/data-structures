#ifndef TNODE_H
#define TNODE_H

struct TNode
{
    int data;
    int bal;
    TNode *lef, *rig;
};

TNode *newTNode(int n);

#endif

