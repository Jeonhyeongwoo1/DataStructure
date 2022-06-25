
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX (100)

enum BOOL { FALSE, TRUE };

typedef struct _heap{
    int* heap;
    int size;
    int count;
}Heap;

enum BOOL CreateHeap(Heap *hp, int size)
{
    if(hp == NULL)
    {
        return FALSE;
    }
    
    hp->size = size;
    hp->count = 0;
    hp->heap = (int*) calloc(size + 1, sizeof(int));
    return hp->heap != NULL;
}

enum BOOL IsHeapEmpty(Heap *hp)
{
    return hp->count == 0;
}

enum BOOL IsHeapFull(Heap *hp)
{
    return hp->count == hp->size;
}

void ReHeapUp(Heap * hp, int child)
{
    if(hp == NULL)
    {
        return;
    }
    
    int parent = child;
    while (parent > 1) {
        parent = child / 2;
        
        if(hp->heap[parent] < hp->heap[child])
        {
            break;
        }
        
        int temp = hp->heap[parent];
        hp->heap[parent] = hp->heap[child];
        hp->heap[child] = temp;
        child = parent;
    }
}

enum BOOL InsertHeap(Heap *hp, int inData)
{
    if(hp == NULL)
    {
        return FALSE;
    }
    
    if(IsHeapFull(hp))
    {
        return FALSE;
    }
    
    hp->count++;
    hp->heap[hp->count] = inData;
    ReHeapUp(hp, hp->count);
    
    return TRUE;
}

void PrintHeap(const Heap *hp)
{
    if(hp == NULL)
    {
        return;
    }
    
    for(int i = 1; i <= hp->count; i++)
    {
        printf("%d\n", hp->heap[i]);
    }
}

void ReHeapDown(Heap *hp, int parent)
{
    int left, right;
    int child;
    
    while (1) {
        
        left = parent * 2;
        right = (parent * 2) + 1;
        
        if(left > hp->count){ //Root만 존재
            break;
        }
        
        if(left == hp->count) // Left만 존재
        {
            child = left;
        }else if(hp->heap[left] < hp->heap[right]){
            child = left;
        }else{
            child = right;
        }
        
        if(hp->heap[parent] < hp->heap[child]){
            break;
        }
        
        int temp = hp->heap[parent];
        hp->heap[parent] = hp->heap[child];
        hp->heap[child] = temp;
        parent = child;
        
    }
    
}

enum BOOL DeleteHeap(Heap *hp, int *getData)
{
    if (hp == NULL) {
        return FALSE;
    }
    
    if(IsHeapEmpty(hp))
    {
        return FALSE;
    }
    
    *getData = hp->heap[1];
    hp->heap[1] = hp->heap[hp->count];
    hp->count--;
    ReHeapDown(hp, 1);
    
    return TRUE;
}

void DestoryHeap(Heap *hp)
{
    if(hp == NULL)
    {
        return;
    }
    
    hp->count = 0;
    hp->size = 0;
    free(hp->heap);
    hp->heap = NULL;
}
