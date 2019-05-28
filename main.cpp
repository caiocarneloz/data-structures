#include <stdio.h>
#include <stdlib.h>
#include "headers/list.h"
#include "headers/stack.h"
#include "headers/queue.h"
#include "headers/avl.h"


void ListRout()
{
    Node *H;
    initList(&H);
    insertionSort(&H,5);
    insertionSort(&H,3);
    insertionSort(&H,8);
    removeList(&H,8);
    killList(&H);
    fprintf(stdout,"\nLIST OUTPUT\n");
    printList(H);
}

void StackRout()
{
    Node *S;
    initStack(&S);
    push(&S, 10);
    push(&S, 16);
    push(&S, 11);
    push(&S, 11);
    fprintf(stdout,"\nSTACK OUTPUT\n");
    printStack(S);
}

void QueueRout()
{
    Node *Q;
    initQueue(&Q);
    enqueue(&Q,5);
    enqueue(&Q,3);
    enqueue(&Q,7);
    enqueue(&Q,1);
    enqueue(&Q,8);
    fprintf(stdout,"\nQUEUE OUTPUT\n");
    printQueue(Q);
}

void AVLRout()
{
    TNode *T, *b = NULL;
    
    initAVL(&T);
    insertAVL(&T,20);
    insertAVL(&T,15);
    insertAVL(&T,8);
    insertAVL(&T,7);
    insertAVL(&T,9);
    insertAVL(&T,18);
    insertAVL(&T,16);
    insertAVL(&T,19);
    insertAVL(&T,30);
    insertAVL(&T,25);
    insertAVL(&T,23);
    insertAVL(&T,27);
    insertAVL(&T,37);
    insertAVL(&T,33);
    insertAVL(&T,39);
    removeAVL(&T,20);
    fprintf(stdout,"\nAVL OUTPUT\n");
    printAVL(T);
}

int main(int argc, char** argv)
{
    ListRout();
    StackRout();
    QueueRout();
    AVLRout();
    return 0;
}