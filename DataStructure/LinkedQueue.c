//
//  LinkedQueue.c
//  DataStructure
//
//  Created by hyeongwoojeon on 2022/06/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listQueue.h"

/*
enum BOOL isQueueEmpty(const Queue *qp)
{
    if(qp == NULL)
    {
        return FALSE;
    }
    
    return qp->head->next == qp->tail ? TRUE : FALSE;
}

enum BOOL dequeue(Queue *qp, int* dequeData)
{
    if(qp == NULL)
    {
        return FALSE;
    }
    
    if(isQueueEmpty(qp))
    {
        return FALSE;
    }
    
    Node* node = qp->head->next;
    qp->head->next = node->next;
    *dequeData = node->data;
    free(node);
    return TRUE;
}

void printQueue(const Queue *qp)
{
    if(qp == NULL)
    {
        return;
    }
    
    if(isQueueEmpty(qp))
    {
        return;
    }
    
    Node* current = qp->head->next;
    while (current != qp->tail) {
        printf("%d", current->data);
        current = current->next;
    }
    
    printf("\n");
}

void destroyQueue(Queue *qp)
{
    if(qp == NULL)
    {
        return;
    }
    
    Node* node = qp->head->next;
    while (node != qp->tail) {
        qp->head->next = qp->head->next->next;
        free(node);
        node = qp->head->next;
    }
    
    free(qp->head);
    free(qp->tail);
    qp->head = NULL;
    qp->tail = NULL;
    
    return;
}

enum BOOL enqueue(Queue *qp, int enqueData)
{
    if(qp == NULL)
    {
        return FALSE;
    }
    
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL)
    {
        return FALSE;
    }
    
    node->data = enqueData;
    
    Node* before = qp->head->next;
    while (before != qp->tail) {
        if(before->next == qp->tail)
        {
            before->next = node;
            node->next = qp->tail;
            break;
        }
        
        before = before->next;
    }
    
    return TRUE;
}

enum BOOL createQueue(Queue *qp)
{
    if(qp == NULL)
    {
        return TRUE;
    }
    
    qp->head = (Node*)calloc(1, sizeof(Node));
    qp->tail = (Node*)calloc(1, sizeof(Node));
    
    qp->head->next = qp->tail;
    qp->tail->next = qp->tail;

    return TRUE;
}
*/
