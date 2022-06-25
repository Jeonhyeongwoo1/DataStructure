//
//  CircularQueue.c
//  DataStructure
//
//  Created by hyeongwoojeon on 2022/06/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularQueue.h"


enum BOOL isQueueEmpty(const Queue *qp)
{
    if(qp == NULL)
    {
        return FALSE;
    }
    
    return qp->front == qp->rear ? TRUE : FALSE;
}

enum BOOL isQueueFull(const Queue *qp)
{
    if(qp == NULL)
    {
        return FALSE;
    }
    
    return qp->front == (qp->rear + 1) % qp->size ? TRUE : FALSE;
}

enum BOOL enqueue(Queue *qp, int enqueData)
{
    if(qp == NULL)
    {
        return FALSE;
    }
    
    if(isQueueFull(qp))
    {
        return FALSE;
    }
    
    qp->queue[qp->rear] = enqueData;
    qp->rear = (qp->rear + 1) % qp->size;
    return TRUE;
}

enum BOOL dequeue(Queue *qp, int *dequeData)
{
    if(qp == NULL)
    {
        return FALSE;
    }
    
    if(isQueueEmpty(qp))
    {
        return FALSE;
    }
    
    *dequeData = qp->queue[qp->front];
    qp->front = (qp->front + 1) % qp->size;
    return TRUE;
}

enum BOOL createQueue(Queue *qp, int size)
{
    if(qp == NULL)
    {
        return FALSE;
    }
    
    qp->queue = (int*)calloc(5, sizeof(int));
    if(qp->queue == NULL)
    {
        return FALSE;
    }
    
    qp->size = size;
    qp->rear = qp->front = 0;
    return TRUE;
}

void printQueue(const Queue *qp)
{
    if(qp == NULL)
    {
        return;
    }
    
    int i = qp->front;
    while (i != qp->rear) {
        i = (qp->front + 1) % qp->size;
        printf("%d", qp->queue[i]);
    }
    printf("\n");
}

void destoryQueue(Queue *qp)
{
    if(qp ==NULL)
    {
        return;
    }
    
    if(qp->queue != NULL)
    {
        free(qp->queue);
    }
    
    qp->queue = NULL;
    qp->size = qp->front = qp->rear = 0;
    
}
