#ifndef AVL_H
#define AVL_H
#include "tnode.h"

void initAVL(TNode **T);
void insertAVL(TNode **T, int data);
void removeAVL(TNode **T, int key);
TNode *searchAVL(TNode *T, int key);
int balanceFactor(TNode *T);
int isLeaf(TNode *T);
TNode *parent(TNode *T, TNode *node);
TNode *findSuccessor(TNode *node);
void findBigger(TNode *T, TNode **b);
void findSmaller(TNode *T, TNode **b);
void printAVL(TNode *T);

#endif

