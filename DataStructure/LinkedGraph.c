//
//  LinkedGraph.c
//  DataStructure
//
//  Created by hyeongwoojeon on 2022/06/25.
//

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedGraph.h"

int visited[MAX_VERTEX];
int queue[MAX_VERTEX];
int front;
int rear;
int cnt;

bool_t initGraph(graph_t *gp){
    
    char s, e;
    
    if(gp == NULL)
    {
        return false;
    }
    
    scanf("%d %d", &gp->vertexCnt, &gp->edgeCnt);
    
    for(int i = 0; i < gp->vertexCnt; i++)
    {
        gp->graph[i] = NULL;
    }
    
    for(int i = 0; i < gp->edgeCnt; i++)
    {
        scanf(" %c %c", &s, &e);
        if(!addNode(gp, s - 'A', e - 'A')){
            destroyGraph(gp);
            return FALSE;
        }
    }
    
    return TRUE;
}

void destroyGraph(graph_t *gp){
    
    if(gp == NULL){
        return;
    }
    
    node_t* current = (node_t*)malloc(sizeof(node_t));
    
    for (int i = 0; i < gp->vertexCnt; i++) {
        
        while (gp->graph[i] != NULL) {
            current = gp->graph[i];
            gp->graph[i] = current->next;
            free(current);
        }
    }
    gp->vertexCnt =0;
    gp->edgeCnt = 0;
    
}

bool_t addNode(graph_t *gp, int v1, int v2){
    
   
    node_t* n1 = (node_t*)malloc(sizeof(node_t));
    if(n1 == NULL)
    {
        return FALSE;
    }
    
    node_t* n2 = (node_t*)malloc(sizeof(node_t));
    if(n2 == NULL)
    {
        free(n1);
        return FALSE;
    }
    
    n1->vertex = v1;
    n1->next = NULL;
    n2->vertex = v2;
    n2->next = NULL;

    n1->next = gp->graph[v2];
    gp->graph[v2] = n1;
    
    n2->next = gp->graph[v1];
    gp->graph[v1] = n2;
    
    return TRUE;
}

void outputGraph(graph_t *gp){
    if(gp == NULL){
        return;
    }
    
    node_t* node = (node_t*) calloc(1, sizeof(node_t));
    for (int i = 0; i < gp->vertexCnt; i++) {
        printf("%2c", i + 'A');
        node = gp->graph[i];
        while (node != NULL) {
            printf(" > %2c", node->vertex + 'A');
            node = node->next;
        }
        printf("\n");
    }
}

void startBFS(graph_t *gp)
{
    if(gp == NULL)
    {
        return;
    }
    
    //초기화
    for (int i = 0; i < gp->vertexCnt; i++) {
        visited[i] = 0;
    }
    
    front = 0;
    rear = 0;
    cnt = 0;
    
    for (int i = 0; i < gp->vertexCnt; i++) {
        if(visited[i] == 0)
        {
            cnt++;
            BFS(gp, i);
            printf("\n");
        }
    }
}

void BFS(graph_t *gp, int s)
{
    
    queue[rear++] = s;
    visited[s] = 1;
    while (rear != front) {
        s = queue[front];
        if(visited[s] == 1)
        {
            printf("%2c", s + 'A');
            front++;
        }
        
        node_t* node = gp->graph[s];
        while (node != NULL) {
            if(visited[node->vertex] == 0)
            {
               // printf("%2c", node->vertex + 'A');
                queue[rear++] = node->vertex;
                visited[node->vertex] = 1;
            }
            
            node = node->next;
        }
       
    }
    
}
*/
