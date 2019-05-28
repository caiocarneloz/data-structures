#include <stdlib.h>
#include <stdio.h>
#include "../headers/avl.h"


void initAVL(TNode **T)
{
    *T = NULL;
}

void insertAVL(TNode **T, int data)
{
    if(*T == NULL)
        *T = newTNode(data);
    else
    {
        TNode *temp, *prev, *node;
        
        temp = prev = *T;
        node = newTNode(data);
        
        while(temp != NULL)
        {
            prev = temp;
            if(node->data > temp->data)
                temp = temp->rig;
            else
                temp = temp->lef;
        }
        
        if(node->data > prev->data)
            prev->rig = node;
        else
            prev->lef = node;
    }
}

void removeAVL(TNode **T, int key)
{
    TNode *node = searchAVL(*T,key);
    TNode *par = parent(*T,node);
    
    if(node != NULL)
    {
        if(isLeaf(node))
        {
            if(par->rig == node)
                par->rig = NULL;
            else
                par->lef = NULL;
            
            free(node);
        }
        else
        {
            int data;
            TNode *suc = findSuccessor(node);
            data = suc->data;
            removeAVL(&(*T), suc->data);
            node->data = data;
        }
    }
}

TNode *searchAVL(TNode *T, int key)
{
    while(T != NULL && T->data != key)
    {
        if(key > T->data)
            T = T->rig;
        else
            T = T->lef;
    }
    
    return T;
}

int balanceFactor(TNode *T)
{
    if(T != NULL)
        return (T->lef==NULL?0:T->lef->bal) - (T->rig==NULL?0:T->rig->bal);
    else
        return 0;
}

int isLeaf(TNode *T)
{
    return T->rig == NULL && T->lef == NULL;
}

TNode *parent(TNode *T, TNode *node)
{
    TNode *par;
    
    while(T != NULL && T->data != node->data)
    {
        par = T;
        if(node->data > T->data)
            T = T->rig;
        else
            T = T->lef;
    }
    
    return par;
}

TNode *findSuccessor(TNode *node)
{
    TNode *b, *s;
    b = s = NULL;
    
    findBigger(node->lef, &b);
    findSmaller(node->rig, &s);
    
    if(b!= NULL && isLeaf(b))
        return b;
    else if(s != NULL && isLeaf(s))
        return s;
    else
        return b==NULL?s:b;
}

void findBigger(TNode *T, TNode **b)
{
    if(T != NULL)
    {
        if(*b == NULL || T->data > (*b)->data)
            *b = T;

        findBigger(T->lef, &(*b));
        findBigger(T->rig, &(*b));
    }
}

void findSmaller(TNode *T, TNode **b)
{
    if(T != NULL)
    {
        if(*b == NULL || T->data < (*b)->data)
            *b = T;

        findSmaller(T->lef, &(*b));
        findSmaller(T->rig, &(*b));
    }
}

void printAVL(TNode *T)
{
    if(T != NULL)
    {
        if(!(T->lef==NULL && T->rig==NULL))
            fprintf(stdout, "(%d) Children\'s = (%d) (%d)\n", T->data, T->lef==NULL?0:T->lef->data, T->rig==NULL?0:T->rig->data);
        printAVL(T->lef);
        printAVL(T->rig);
    }
}