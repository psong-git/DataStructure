#include "linkedlist.h"

Node  *newNode(int data)
{
    Node *new;
    new = (Node*)calloc(1, sizeof(Node));
    if (!new)
        return (0);
    new->data = data;
    return (new);
}

List  *newList()
{
    List *new;
    new = (List*)calloc(1, sizeof(List));
    if (!new)
        return (0);
    new->Head = newNode(0);
    return (new);
}

void    addNodeIndex(Node *node, List *list, int index)
{
    Node *temp;
	Node *curr;
	Node *before;

	curr = list->Head->next;
	before = list->Head;
	while (index--)
	{
		before = curr;
		curr = curr->next;
	}
    if (curr)	
	{	
		temp = curr->prev;
    	curr->prev = node;
		node->next = curr;
    	node->prev = temp;
		if (temp)
			temp->next = node;
	}
	else
	{	
		before->next = node;
		node->prev = before;
	}
    list->size++;
}

void    addNodeBack(Node *node, List *list)
{
	Node *curr;

    curr = list->Head;
    while (curr->next)
        curr = curr->next;
	curr->next = node;
    node->prev = curr;
    list->size++;
}

int	findIndex(List *list, int data)
{
	Node *curr;
	int	index = 0;

	curr = list->Head->next;
	while (curr)
	{
		if (curr->data > data)
			break;
		curr = curr->next;
		index++;
	}
	return (index);
}

Node    *deleteNodeFront(List *list)
{
	Node *curr;
    Node *temp;
    curr = list->Head->next;
    temp = curr->prev;
    temp->next = curr->next;
    if (curr->next)
        curr->next->prev = temp;
    list->size--;
    curr->next = NULL;
    //curr->prev = NULL;
    return (curr);
}

Node    *deleteNodeIndex(List *list, int deleteIndex)
{
	Node *curr;
    Node *temp;
    curr = list->Head->next;
	while (curr)
	{
		if (curr->data == deleteIndex)
		{
			temp = curr->prev;
			temp->next = curr->next;
			if (curr->next)
				curr->next->prev = temp;
			list->size--;
			break;
		}
		curr = curr->next;
	}
    return (curr);
}

Node	*findNode(List *list, int index)
{
	Node *curr;

	curr = list->Head->next;
	while (curr)
	{
		if (curr->data == index)
			break;
		curr = curr->next;
	}
	return (curr);
}
