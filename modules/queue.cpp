#include <stdio.h>
#include <stdlib.h>
#include "../headers/queue.h"

void initQueue(Node **Q)
{
    *Q = NULL;
}

void enqueue(Node **Q, int data)
{
    if(*Q == NULL)
        *Q = newNode(data);
    else
    {
        Node *temp = *Q;
        
        while(temp->next != NULL)
            temp = temp->next;
        
        temp->next = newNode(data);
    }
}

Node *dequeue(Node **Q)
{
    if(*Q != NULL)
    {
        Node *temp;
        temp = *Q;
        *Q = (*Q)->next;
        return temp;        
    }
    else
        return NULL;
}

void printQueue(Node *Q)
{
    Node *temp = Q;
    
    fprintf(stdout,"Queue: ");
    
    if(Q == NULL)
        fprintf(stdout,"empty\n");
    else
    {
        while(temp->next != NULL)
        {
            fprintf(stdout,"%d, ",temp->data);
            temp = temp->next;
        }
        fprintf(stdout,"%d.\n",temp->data);
    }
}