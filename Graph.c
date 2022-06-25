//
//  Graph.c
//  DataStructure
//
//  Created by hyeongwoojeon on 2022/06/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
/*
int grp[MAX][MAX];
int vertex;
int edge;
int visited[MAX];
int stack[MAX];
int top;
int cnt;

void startDFS(void)
{
    
    for(int i = 0; i < vertex; i++)
    {
        visited[i] = 0;
    }
    
    top = 0;
    cnt = 0;
    
    for (int i = 0; i < vertex; i++) {
        if (visited[i] == 0) {
            cnt++;
            reDFS(i);
            printf("\n"); //3번돌아야함
        }
    }
    
    printf("그래프 수 : %d", cnt);
}

void DFS(int u)
{
    int v;
    top = 0;
    stack[top++] = u;
    visited[u] = 1;
    
    while (top > 0) {
        u = stack[--top];
        printf("%2c", u + 'A');
        for (v = 0; v < vertex; v++) {
            if((grp[u][v] == 1) && (visited[v] == 0)) {
                stack[top++] = v;
                visited[v] = 1;
            }
        }
    }
}

void reDFS(int u)
{
    visited[u] = 1;
    printf("%2c", u + 'A');
    for (int i = 0; i < vertex; i++) {
        
        if(visited[i] == 0 && grp[u][i] == 1){
            reDFS(i);
        }
    }
}

void printGraph(void)
{
    printf("%2c", ' ');
    for(int i = 0; i < vertex; i++)
    {
        printf("%2c", 'A' + i);
    }
    printf("\n");
    
    for(int i = 0; i < vertex; i++)
    {
        printf("%2c", 'A' + i);
        for(int j=0; j < vertex; j++)
        {
            printf("%2d", grp[i][j]);
        }
        
        printf("\n");
    }
    
}

void createGraph(void)
{
    char s, e;
    
    scanf("%d %d", &vertex, &edge);
    
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            grp[i][j] = 0;
        }
    }
    
    for(int j =0; j < edge; j++)
    {
        scanf(" %c %c", &s, &e);
        grp[s - 'A'][e - 'A'] = 1;
        grp[e - 'A'][s - 'A'] = 1;
    }
}
*/
