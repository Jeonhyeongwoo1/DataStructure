//
//  Josephus.c
//  DataStructure
//
//  Created by hyeongwoojeon on 2022/06/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum BOOL { FALSE, TRUE};

typedef struct _node Node;
struct _node{
    int data;
    Node* next;
};

typedef struct _queue{
    Node* head;
    Node* tail;
}Queue;

enum BOOL IsQueueEmpty(const Queue *qp)
{
    if(qp == NULL)
    {
        return FALSE;
    }
    
    return qp->head->next == qp->tail ? TRUE : FALSE;
}

void DisplayQueue(const Queue *qp)
{
    if(qp == NULL)
    {
        return;
    }
    
    if(IsQueueEmpty(qp) == TRUE)
    {
        return;
    }
    
    Node* node = (Node*)calloc(1, sizeof(Node));
    node = qp->head->next;
    while (node != qp->tail) {
        printf("%d", node->data);
        node = node->next;
    }

}

enum BOOL Dequeue(Queue *qp, int* data)
{
    if(qp == NULL)
    {
        return FALSE;
    }
    
    if(IsQueueEmpty(qp) == TRUE)
    {
        return FALSE;
    }
    
    Node* node = (Node*)calloc(1, sizeof(Node));
    if(node == NULL)
    {
        return FALSE;
    }
    
    node = qp->head->next;
    qp->head->next = node->next;
    *data = node->data;
    free(node);
    
    return TRUE;
}

enum BOOL Enqueue(Queue *qp, int data)
{
    if(qp == NULL)
    {
        return FALSE;
    }
    
    Node* node = (Node*)calloc(1, sizeof(Node));
    if(node == NULL)
    {
        return FALSE;
    }
    

    Node* before = (Node*)calloc(1, sizeof(Node));
    before = qp->head;
    while (before != qp->tail) {
        if(before->next == qp->tail)
        {
            before->next = node;
            node->next = qp->tail;
            node->data = data;
            break;
        }
        before = before->next;
    }
        
    return TRUE;
}

enum BOOL CreateQueue(Queue *qp)
{
    if(qp == NULL)
    {
        return FALSE;
    }
    
    qp->head = (Node*)calloc(1, sizeof(Node));
    qp->tail = (Node*)calloc(1, sizeof(Node));
    
    if(qp->head == NULL)
    {
        return FALSE;
    }
    
    if(qp->tail == NULL)
    {
        return FALSE;
    }
    
    qp->head->next = qp->tail;
    qp->tail->next = qp->tail;
    return TRUE;
}

void DestroyQueue(Queue *qp)
{
    if(qp == NULL)
    {
        return;
    }
    
    Node* node = (Node*)calloc(1, sizeof(Node));
    if(node == NULL)
    {
        return;
    }
    
    node = qp->head->next;
    while (node != qp->tail) {
        free(node);
        node = qp->head->next->next;
    }
    
    if(qp->head != NULL)
    {
        free(qp->head);
    }
    
    if(qp->tail != NULL)
    {
        free(qp->tail);
    }
    
    qp->head = qp->tail = NULL;
    
}

void Josephus(Queue *qp, int value)
{
    
    if(qp == NULL) { return;}
    
    int data = 0;
    while (!IsQueueEmpty(qp)) {
        
        for(int i = 1; i < value; i++)
        {
            if(Dequeue(qp, &data) == TRUE)
                Enqueue(qp, data);
        }
        
        if(Dequeue(qp, &data) == TRUE)
            printf("%d", data);
    }

    DestroyQueue(qp);
}
