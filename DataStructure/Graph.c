//
//  Graph.c
//  DataStructure
//
//  Created by hyeongwoojeon on 2022/06/24.
//
/*
#include <stdio.h>

#include <stdlib.h>
#include <string.h>

#include "Graph.h"

int grp[MAX][MAX];
int vertex;
int edge;
int visited[MAX];
int stack[MAX];
int top;
int cnt;

void printGraph()
{
    printf("%2s", "");
    for (int i = 0; i < vertex; i++) {
        printf("%2c", i + 'A');
    }
    printf("\n");
    for(int i = 0; i < vertex; i++)
    {
        printf("%2c", i + 'A');
        for(int j = 0; j < vertex; j++)
        {
            printf("%2d", grp[i][j]);
        }
        
        printf("\n");
    }
}

void createGraph(void){
    
    char s, e;
    scanf("%d %d", &vertex, &edge);
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            grp[i][j] = 0;
        }
    }
    
    for (int i = 0; i < edge; i++) {
        scanf(" %c %c", &s, &e);
        grp[s - 'A'][e - 'A'] = 1;
        grp[e - 'A'][s - 'A'] = 1; //대칭형을 이루기 때문
    }
    
}
*/
