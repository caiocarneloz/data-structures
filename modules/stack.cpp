#include <stdio.h>
#include <stdlib.h>
#include "../headers/stack.h"


void initStack(Node **S)
{
    *S = NULL;
}

void push(Node **S, int data)
{
    Node *node;
    if(*S == NULL)
        *S = newNode(data);
    else
    {
        node = newNode(data);
        node->next = *S;
        *S = node;
    }
}

Node *pop(Node **S)
{
    if(*S != NULL)
    {
        Node *temp;
        temp = *S;
        *S = (*S)->next;
        return temp;        
    }
    else
        return NULL;
}

void printStack(Node *S)
{
    Node *temp = S;
    
    fprintf(stdout,"Stack: ");
    
    if(S == NULL)
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