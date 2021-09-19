#ifndef DEQUE_H
# define DEQUE_H

# include <stdio.h>
# include <stdlib.h>

# define TRUE	1
# define FALSE 	0

# define LIST_LEN   5

//node 용
typedef struct node {
	char           data;
    struct node  *pRLink; // next
    struct node  *pLLink; // prev
} Node;

//링크드리스트 전체
typedef struct linkedlist {
	struct node *pFrontNode; // head
  struct node *pRearNode; // tail
	int    size;
} Linkedlist;

void  lstinit(Linkedlist *lst);
void  delAll(Linkedlist *lst);
void  deletepRearNode(Linkedlist *lst);
void  deletepFrontNode(Linkedlist *lst);
void  delOne(Linkedlist *lst, Node *del);
void  display(Node *front);
int	  size(Linkedlist lst);
void	insertpRearNode(Linkedlist *lst, Node *new_node);
Node	*getLast(Linkedlist *lst);
void	insertpFrontNode(Linkedlist *lst, Node *newNode);
void  add(Node *currNode, Node *newNode);
Node	*lstnew(char data);

#endif
