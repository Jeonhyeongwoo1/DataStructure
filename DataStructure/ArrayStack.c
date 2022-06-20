//
//  ArrayStack.c
//  DataStructure
//
//  Created by hyeongwoojeon on 2022/06/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayStack.h"

enum BOOL createStack(Stack *sp, int size)
{
    if(sp == NULL)
    {
        return FALSE;
    }
    
    int* stack = (int*)calloc(size, sizeof(int)); //쓰레기값 대신 0으로 초기화
    if(stack == NULL)
    {
        return FALSE;
    }
    
    sp->size = size;
    sp->stack = stack;
    sp->top = 0;
    
    return TRUE;
}

enum BOOL isStackEmpty(Stack *sp)
{
    if(sp == NULL)
    {
        return FALSE;
    }
    
    return sp->top == 0;
}

enum BOOL isStackFull(Stack *sp)
{
    if(sp == NULL)
    {
        return FALSE;
    }
    
    return sp->top == sp->size;
}

enum BOOL push(Stack *sp, int inData)
{
    if(sp == NULL)
    {
        return FALSE;
    }
    
    if(isStackFull(sp)) { return FALSE;}
    
    sp->stack[sp->top] = inData;
    sp->top++;
    return TRUE;
}

enum BOOL pop(Stack *sp, int *popData)
{
    if(sp == NULL)
    {
        return FALSE;
    }
    
    if(isStackEmpty(sp)) { return FALSE;}
    
    --sp->top;
    *popData = sp->stack[sp->top];
    return TRUE;
}

void printStack(const Stack* sp)
{
    if(sp == NULL)
    {
        return;
    }

    int i = sp->top;
    while (i != 0) {
        printf("%d", sp->stack[--i]);
    }
}

void destroyStack(Stack *sp){
    
    if(sp == NULL)
    {
        return ;
    }
    
    if(isStackEmpty(sp))
    {
        return;
    }
    
    free(sp->stack);
    sp->size = sp->top =0;
    sp->stack = NULL;
}
