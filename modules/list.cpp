#include <stdio.h>
#include <stdlib.h>
#include "../headers/list.h"


void initList(Node **H)
{
    *H = NULL;
}

void *insertionList(Node **H, int n)
{
    if(*H == NULL)
        *H = newNode(n);
    else
    {
        Node *temp = *H;
        
        while(temp->next != NULL)
            temp = temp->next;
        
        temp->next = newNode(n);
    }
}

void *insertionSort(Node **H, int n)
{
    if(*H == NULL)
        *H = newNode(n);
    else
    {
        Node *temp, *prev;
        temp = prev = *H;
        
        while(temp != NULL && n > temp->data)
        {
            prev = temp;
            temp = temp->next;
        }
        
        if(prev == temp)
        {
            temp = newNode(n);
            (*H)->next = NULL;
            temp->next = *H;
            *H = temp;
        }
        else
        {               
            prev->next = newNode(n);
            prev->next->next = temp;
        }
    }
}

void *removeList(Node **H, int n)
{
    Node *temp, *prev;
    temp = prev = *H;
    
    if(*H != NULL)
    {
    
        if((*H)->data == n)
        {
            *H = (*H)->next;
            free(temp);
        }
        else
        {
            while(temp != NULL && temp->data != n)
            {
                prev = temp;
                temp = temp->next;
            }
            
            if(temp != NULL)
            {
                prev->next = temp->next;
                free(temp);
            }
        }
    }
}

void *killList(Node **H)
{
    if(*H != NULL)
    {
        killList(&(*H)->next);
        free(*H);
    }
    *H = NULL;
}

void printList(Node *H)
{
    Node *temp = H;
    
    fprintf(stdout,"List: ");
    
    if(H == NULL)
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

