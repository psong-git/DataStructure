#include "deque.h"

//초기화
void lstinit(Linkedlist *lst)
{
  if (!(lst->pFrontNode = malloc((sizeof(Node)))))
    return ;
  if (!(lst->pRearNode = malloc((sizeof(Node)))))
    return ;
  (lst->pFrontNode)->pLLink = lst->pRearNode;
  (lst->pFrontNode)->pRLink = lst->pRearNode;
  (lst->pRearNode)->pLLink = lst->pFrontNode;
  (lst->pRearNode)->pRLink = lst->pFrontNode;
  lst->size = 0;
}

//새 노드 생성
Node	*lstnew(char data)
{
	Node	*list;

	if (!(list = malloc(sizeof(Node))))
    return (0);
	list->data = data;
  list->pLLink = NULL;
	list->pRLink = NULL;
	return (list);
}

void  add(Node *currNode, Node *newNode)
{
  newNode->pRLink = currNode->pRLink;
  (currNode->pRLink)->pLLink = newNode;
  newNode->pLLink = currNode;
  currNode->pRLink = newNode;
}

//헤드 바로 뒤에 노드 추가
void	insertpFrontNode(Linkedlist *lst, Node *newNode)
{
  if (lst && newNode)
  {
	  add(lst->pFrontNode, newNode);
    (lst->size)++;
  }
}

// 마지막 노드 반환
Node	*getLast(Linkedlist *lst)
{
  if (lst->size >= 1)
    return ((lst->pRearNode)->pLLink);
  else
    return (NULL);
}

//맨 뒤에 노드 추가하기
//enqueue
void		insertpRearNode(Linkedlist *lst, Node *new_node)
{
	if (lst == NULL || new_node == NULL)
		return ;
	add(getLast(lst), new_node);
  (lst->size)++;
}

//size();
int	size(Linkedlist lst)
{
  return (lst.size);
}

//전체 조회
void display(Node *pFrontNode)
{
  if (pFrontNode == NULL)
    return ;
  Node *curNode = pFrontNode->pRLink;
  while (curNode->pRLink)
  {
    printf("%c\n", curNode->data);
    if (curNode->pRLink == pFrontNode)
        return ;
    curNode = curNode->pRLink;
  }
}

//노드삭제
void  delOne(Linkedlist *lst, Node *del)
{
  Node *curNode;

  if (lst == NULL || del == NULL)
    return ;
  if (lst->size >= 1)
  {
    curNode = del;
    (curNode->pLLink)->pRLink = curNode->pRLink;
    (curNode->pRLink)->pLLink = curNode->pLLink;
    free(del);
    del = NULL;
    (lst->size)--;
  }
}

//첫번째 노드삭제
void  deletepFrontNode(Linkedlist *lst)
{
  if (lst == NULL)
    return ;
  delOne(lst, (lst->pFrontNode)->pRLink);
}

//마지막 노드삭제
void  deletepRearNode(Linkedlist *lst)
{
  if (lst == NULL)
    return ;
  delOne(lst, (lst->pRearNode)->pLLink);
}

void  delAll(Linkedlist *lst)
{
  Node *tmp;
  Node *curNode;

  curNode = lst->pFrontNode->pRLink;
  while (curNode)
  {
    tmp = curNode->pRLink;
    delOne(lst, curNode);
    curNode = tmp;
  }
  free(lst->pFrontNode);
  lst->pFrontNode = NULL;
  lst->pRearNode = NULL;
}
