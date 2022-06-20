//
//  DoublyLinkedlist.c
//  DataStructure
//
//  Created by hyeongwoojeon on 2022/06/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublyLinkedlist.h"

enum BOOL createList(List* lp)
{
    if(lp == NULL)
    {
        return FALSE;
    }
    
    lp->head = (Node*) malloc(sizeof(Node));
    if(lp->head == NULL)
    {
        return FALSE;
    }
    
    lp->tail = (Node*) malloc(sizeof(Node));
    if(lp->tail == NULL)
    {
        return FALSE;
    }
    
    lp->head->prev = lp->head;
    lp->head->next = lp->tail;
    
    lp->tail->next = lp->tail;
    lp->tail->prev = lp->head;
    lp->size = 0;
    
    return TRUE;
}

enum BOOL addFirst(List *lp, int data)
{
    if(lp == NULL)
    {
        return FALSE;
    }
    
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL)
    {
        return FALSE;
    }
    
    node->data = data;
    node->prev = lp->head;
    node->next = lp->head->next;
    lp->head->next->prev = node;
    lp->head->next = node;
    ++lp->size;
    return TRUE;
}

enum BOOL addLast(List *lp, int data)
{
    if(lp== NULL)
    {
        return FALSE;
    }
    
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL)
    {
        return FALSE;
    }
    
    node->data = data;
    node->prev = lp->tail->prev;
    node->next = lp->tail;
    
    lp->tail->prev->next = node;
    lp->tail->prev = node;
    ++lp->size;
    return TRUE;
    
}

void displayList(List *lp)
{
    if(lp == NULL)
    {
        return;
    }
    
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL) { return;}
    
    node = lp->head->next;
    while (node != lp->tail) {
        node = node->next;
        printf("%d : ", node->data);
    }
    
    return;
}

Node* searchNode(List *lp, int data)
{
    if(lp == NULL)
    {
        return NULL;
    }
    
    Node* current = (Node*)malloc(sizeof(Node));
    if(current == NULL)
    {
        return NULL;
    }
        
    current = lp->head->next;
    while (current->next != lp->tail) {
        if(current->data == data)
        {
            return current;
        }
        
        current = current->next;
    }
}

enum BOOL removeNode(List *lp, int data)
{
    if(lp == NULL)
    {
        return FALSE;
    }
    
    Node* current = searchNode(lp, data);
    if(current == NULL)
    {
        return FALSE;
    }
    
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    --lp->size;
    return TRUE;
    
}

void sortList(List* lp)
{
    if(lp == NULL)
    {
        return;
    }
    
    Node* current = (Node*)malloc(sizeof(Node));
    if(current == NULL)
    {
        return;
    }
    
    Node* next = (Node*)malloc(sizeof(Node));
    if(next == NULL)
    {
        return;
    }
    
    current = lp->head->next;
    while (current->next != lp->tail) {
        next->next = current;
        while (next->next != lp->tail) {
            if(current->data > next->data)
            {
                int temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
            next->next = next;
        }
        
        current = current->next;
    }
}

void destoryList(List *lp)
{
    
    if(lp == NULL)
    {
        return;
    }
    
    Node* current = (Node*)malloc(sizeof(Node));
    Node* next = (Node*)malloc(sizeof(Node));
    
    current = lp->head;
    while (current->next != lp->tail) {
        next = current->next;
        free(current);
        current->next = next;
    }
    
    free(current);
    free(next);
    lp->head = NULL;
    lp->tail = NULL;
    lp->size = 0;
    
}
