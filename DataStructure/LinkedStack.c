//
//  LinkedStack.c
//  DataStructure
//
//  Created by hyeongwoojeon on 2022/06/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listStack.h"

enum BOOL createStack(Stack *sp)
{
    if(sp == NULL)
    {
        return FALSE;
    }
    
    sp->head = (Snode*)calloc(1, sizeof(Snode));
    if(sp->head == NULL){
        return FALSE;
    }
    
    sp->tail = (Snode*)calloc(1, sizeof(Snode));
    if(sp->tail == NULL){
        free((sp->head));
        return FALSE;
    }
    
    sp->head->next = sp->tail;
    sp->tail->next = sp->tail;
    
    return TRUE;
}

enum BOOL isStackEmpty(const Stack *sp)
{
    if(sp == NULL)
    {
        return FALSE;
    }
    
    return sp->head->next == sp->tail;
}

enum BOOL push(Stack *sp, int pushData)
{
    if(sp == NULL)
    {
        return FALSE;
    }
    
    Snode* node = (Snode*)malloc(sizeof(Snode));
    if(node == NULL)
    {
        return FALSE;
    }
    
    node->data = pushData;
    node->next = sp->head->next;
    sp->head->next = node;
    
    return TRUE;
}

enum BOOL pop(Stack *sp, int *popData)
{
    if(sp == NULL)
    {
        return FALSE;
    }
    
    if(isStackEmpty(sp))
    {
        return FALSE;
    }
    
    *popData = sp->head->next->data;
    sp->head->next = sp->head->next->next;
    free(sp->head->next);
    return TRUE;
}

void printStack(const Stack *sp)
{
    if(sp == NULL)
    {
        return;
    }
    
    if(isStackEmpty(sp))
    {
        return;
    }
    
    Snode* node = (Snode*) calloc(1, sizeof(Snode));
    node = sp->head;
    while (node != sp->tail) {
        node = node->next;
        printf("%5d\n", node->data);
    }
    
    printf("\n");
}

void destroyStack(Stack *sp)
{
    if(sp == NULL)
    {
        return;
    }
    
    Snode* current = sp->head->next;
    Snode* next = sp->head->next->next;
    
    while (current->next != sp->tail) {
        free(current);
        current = next;
        next = next->next;
    }
  
    free(sp->head);
    free(sp->tail);
    sp->head = sp->tail = NULL;
}
