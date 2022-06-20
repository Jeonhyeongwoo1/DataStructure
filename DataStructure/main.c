//
//  main.c
//  DataStructure
//
//  Created by hyeongwoojeon on 2022/06/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _stack {
    char *stack[100001];
    int size;
    int top;
}Stack;

enum BOOL { TRUE, FALSE};

enum BOOL Push(Stack* sp, char* data)
{
    if(sp == NULL)
    {
        return FALSE;
    }
    
    
    return  TRUE;
}

enum BOOL CreateStack(Stack* sp, int size)
{
    if(sp == NULL)
    {
        return FALSE;
    }
    
    sp->size = size;
    sp->top = 0;
    return TRUE;
}

int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}


