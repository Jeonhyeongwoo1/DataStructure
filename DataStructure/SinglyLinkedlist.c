
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "singlyLinkedlist.h"
/*
enum BOOL createList(List *lp)
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
    
    lp->head->next = lp->tail;
    lp->tail = lp->tail;
    ++lp->size;
    
    return TRUE;
}

enum BOOL addFirst(List *lp, char *data)
{
    
    //Header 바로 뒤
    if(lp == NULL)
    {
        return FALSE;
    }
    
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL)
    {
        return FALSE;
    }
    
    strcpy(node->data, data);
    node->next = lp->head->next;
    lp->head->next = node->next;
    ++lp->size;
    return TRUE;
}

enum BOOL addLast(List *lp, char *data)
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

    Node* before = (Node*)malloc(sizeof(Node));
    before->next = lp->head->next;
    while (before->next != lp->tail) {
        before = before->next;
    }
    
    before->next = node;
    node->next = lp->tail;
    strcpy(node->data, data);
    ++lp->size;
    return TRUE;
}

void displayList(List *lp)
{
    if(lp == NULL)
    {
        return;
    }
    
    Node* current = (Node*)malloc(sizeof(Node));
    current = lp->head->next;
    while (current->next != lp->tail) {
        current = current->next;
        printf("%s", current->data);
    }
}

enum BOOL removeNode(List *lp, char *data)
{
    if(lp == NULL)
    {
        return FALSE;
    }
    
    Node* node = searchNode(lp, data);
    if(node == NULL)
    {
        return FALSE;
    }
    
    Node* before = (Node*)malloc(sizeof(Node));
    before = lp->head;
    while (before->next != node) {
        before = before->next;
    }
    
    before->next = node->next;
    free(node);
    --lp->size;
    
    return TRUE;
}

Node * searchNode(List *lp, char *data)
{
    if(lp == NULL)
    {
        return NULL;
    }
    
    Node* finder = (Node*)malloc(sizeof(Node));
    if(finder == NULL)
    {
        return NULL;
    }
    
    finder = lp->head->next;
    while (finder->next != lp->tail) {
        if(strcmp(finder->data, data) == 0)
        {
            return finder;
        }
        
        finder = finder->next;
    }
    
    return NULL;
}

void sortList(List *lp)
{
    if(lp == NULL)
    {
        return;
    }
    
    //오름차순
    Node* current = (Node*)malloc(sizeof(Node));
    Node* next = (Node*)malloc(sizeof(Node));
    
    current = lp->head;
    next = current->next;
    char temp[80];
    while (current->next != lp->tail) {
        while (next->next != lp->tail) {

            if(strcmp(current->data, next->data) > 0)
            {
                strcpy(temp, current->data);
                strcpy(current->data, next->data);
                strcpy(next->data, temp);
            }
            next = next->next;
        }
        current = current->next;
    }
    
}

void destroyList(List *lp) //모든 노드 삭제
{
    if(lp == NULL)
    {
        return ;
    }
    
    Node* next = (Node*)malloc(sizeof(Node));
    if(next == NULL)
    {
        return;
    }
    
    Node* before = (Node*)malloc(sizeof(Node));
    if(before == NULL)
    {
        return;
    }
    
    before = lp->head->next;
    while (before->next != lp->tail) {
        
        next = before->next;
        free(before);
        before = next;
    }
    
    free(lp->head);
    free(lp->tail);
    
    lp->head=NULL;
    lp->tail=NULL;
    lp->size = 0;
    
}
*/
