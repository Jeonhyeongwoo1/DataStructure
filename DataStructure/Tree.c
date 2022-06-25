//
//  Tree.c
//  DataStructure
//
//  Created by hyeongwoojeon on 2022/06/23.
//
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node Node;
typedef struct _node{
    int data;
    Node* left;
    Node* right;
}Node;

typedef struct _Tree{
    Node *root;
    int nodeCnt;
}Tree;


void InitTree(Tree *tp)
{
    if(tp == NULL)
    {
        return;
    }
    
    tp->root = NULL;
    tp->nodeCnt = 0;
}

Node* MakeNode(int data, Node *left, Node *right)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL)
    {
        return NULL;
    }
    
    node->left = left;
    node->right = right;
    node->data = data;
    return node;
}

Node *AddNode(Tree *tp, int data)
{
    if(tp == NULL)
    {
        return NULL;
    }
    
    Node* node = tp->root;
    Node* parent = tp->root;
    while (node != NULL) {
        parent = node;
        node = parent->data > data ? parent->left : parent->right;
    }
    
    node = MakeNode(data, NULL, NULL);
    if(tp->root == NULL)
    {
        tp->root = node;
        return node;
    }
    else if(parent->data > data)
    {
        parent->left = node;
    }
    else if(parent->data < data)
    {
        parent->right = node;
    }
    
    return node;
}

void PreorderTraverse(Node *np)
{
    while (np != NULL) {
        printf("%d\n", np->data);
        PreorderTraverse(np->left);
        PreorderTraverse(np->right);
        break;
    }
}

void InorderTraverse(Node *np)
{
    while (np != NULL) {
        InorderTraverse(np->left);
        printf("%d\n", np->data);
        InorderTraverse(np->right);
        break;
    }
}

void PostorderTraverse(Node *np)
{
    while (np != NULL) {
        PostorderTraverse(np->left);
        PostorderTraverse(np->right);
        printf("%d\n", np->data);
        break;
    }
}

Node* SearchTreeNode(Tree* tp, int data)
{
    if(tp == NULL)
    {
        return NULL;
    }
    
    Node* child = tp->root;
    Node* parent = tp->root;
    
    while (child != NULL) {
        if(child->data == data)
        {
            return child;
        }
        
        parent = child;
        child = parent->data > data ? parent->left : parent->right;
    }
    
    return NULL;
}

Node* DeleteNode(Tree *tp, int data)
{
    
    if(tp == NULL)
    {
        return NULL;
    }
    
    Node* parent = tp->root;
    Node* child = tp->root;
    Node* del = (Node*)malloc(sizeof(Node));
    
    while (child != NULL) {
        if(child->data == data)
        {
            break;
        }
        
        parent = child;
        child = parent->data > data ? parent->left : parent->right;
    }
    
    del = child;
    if(del->right == NULL)
    {
        if(parent->data > data)
        {
            parent->left = del->left;
        }else
        {
            parent->right = del->left;
        }
    }
    else if(del->right != NULL && del->right->left == NULL)
    {
        if(parent->data >data)
        {
            parent->left = del->right;
        }
        else
        {
            parent->right =del->right;
        }
        
        if(del->left != NULL)
        {
            del->right->left = del->left;
        }
        
    }
    else
    {
        Node* findParent = child->right;
        Node* find = child->right;
        while (find->left != NULL) {
            findParent = find;
            find = find->left;
        }
        
        findParent->left = NULL;
        find->left = child->left;
        find->right = child->right;
        if(parent->data > data)
        {
            parent->left = find;
        }
        else
        {
            parent->right = find;
        }
    }
    
    free(del);
    tp->nodeCnt--;
    return del;
}

void PostorderDelete(Node *np)
{
    while (np != NULL) {
        PostorderDelete(np->left);
        PostorderDelete(np->right);
        printf("%d\n", np->data);
        free(np);
        break;
    }
}

void DestroyTree(Tree* tp)
{
    if(tp == NULL)
    {
        return;
    }
    
    PostorderDelete(tp->root);
    tp->root = NULL;
    tp->nodeCnt = 0;
    
}
*/
