#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include <stdlib.h>
# include <stdio.h>

typedef struct  node
{
    int data;
    struct node *prev;
    struct node *next;
}               Node;

typedef struct  list
{
    struct node *Head;
    int size;
}               List;

Node  *newNode(int data);
List  *newList();
void    addNodeIndex(Node *node, List *list, int index);
void    addNodeBack(Node *node, List *list);
int	findIndex(List *list, int data);
Node    *deleteNodeIndex(List *list, int deleteIndex);
Node    *deleteNodeFront(List *list);
Node	*findNode(List *list, int index);
#endif
