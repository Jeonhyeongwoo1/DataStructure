//
//  HashTable.c
//  DataStructure
//
//  Created by hyeongwoojeon on 2022/06/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hash_chaining.h"

int createHash(CHash *hp, int size)
{
    if(hp == NULL)
    {
        return FALSE;
    }
    
    hp->size = size;
    hp->dataCnt = 0;
    hp->hash = (Node*)calloc(size, sizeof(Node));
    if(hp->hash == NULL)
    {
        return FALSE;
    }
    
    return TRUE;
    
}

int hashFunction(CHash *hp, int key)
{
    if(hp == NULL)
    {
        return FALSE;
    }
    
    int sum = 0;
    while (key > 0) {
        sum += key % 10;
        key = key / 10;
    }
    
    return sum % HASH_SIZE;
}

BOOL hashInput(CHash *hp, int iData)
{
    if(hp == NULL)
    {
        return FALSE;
    }
    
    int hashValue = hashFunction(hp, iData);
    Node* node = (Node*)calloc(1, sizeof(Node));
    if(node == NULL) return FALSE;
    
    node->key = iData;
    node->next = hp->hash[hashValue].next;
    hp->hash[hashValue].next = node;
    hp->dataCnt++;
    
    return TRUE;
}

int hashSearch(CHash *hp, int sData)
{
    if(hp == NULL)
    {
        return -1;
    }
    
    int hashValue = hashFunction(hp, sData);
    Node* node = (Node*)calloc(1, sizeof(Node));
    if(node == NULL)
    {
        return -1;
    }
    
    node = hp->hash[hashValue].next;
    while (node != NULL) {
        if(node->key == sData)
        {
            return hashValue;
        }
        node = node->next;
    }
    
    return -1;
}

BOOL hasDelete(CHash *hp, int dData)
{
    if(hp == NULL)
    {
        return FALSE;
    }
    
    Node *sp;
    Node *pre;
    
    int hashValue = hashFunction(hp, dData);
    pre = &hp->hash[hashValue];
    sp = pre->next;
    
    while (sp != NULL) {
        if(sp->key == dData){
            pre->next = sp->next;
            free(sp);
            hp->dataCnt--;
            return TRUE;
        }
        
        pre= sp;
        sp=sp->next;
    }
    
    return FALSE;
}

void destroyHash(CHash *hp)
{
    if(hp == NULL)
    {
        return;
    }
    
    Node* node = (Node*)malloc(sizeof(Node));
    Node* before = (Node*)malloc(sizeof(Node));
    if(hp->hash != NULL)
    {
        for(int i = 0; i < hp->size; i++)
        {
            if(hp->hash[i].next != NULL)
            {
                node = hp->hash[i].next;
                //printf("%5d", node->key);
                while (node != NULL) {
                    before = node->next;
                    free(node);
                    node = before;
                }
            }
        }
        
        free(hp->hash);
    }
    
    hp->size = hp->dataCnt = 0;
    hp->hash = NULL;
    return;
}

void hashPrint(CHash *hp)
{
    if(hp == NULL)
    {
        return;
    }
    
    Node* node = (Node*)malloc(sizeof(Node));
    for(int i = 0; i < hp->size; i++)
    {
        node = hp->hash[i].next;
        while (node != NULL) {
            printf("%d", node->key);
            node = node->next;
        }
    }
}
